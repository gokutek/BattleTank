// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}



// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
    LastFireSeconds = FPlatformTime::Seconds();
    FiringState = EFiringState::Reloading;
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (FPlatformTime::Seconds() - LastFireSeconds > ReloadTimeInSeconds) {
        FiringState = EFiringState::Reloading;
    }
}


void UTankAimingComponent::Initialise(UTankBarrel* Barrel, UTankTurret* Turret)
{
    this->Barrel = Barrel;
    this->Turret = Turret;
}


void UTankAimingComponent::AimAt(FVector const &HitLocation)
{
    if (!Barrel)
    {
        return;
    }

    FVector TossVelocity;
    bool result = UGameplayStatics::SuggestProjectileVelocity(this, TossVelocity,
        Barrel->GetSocketLocation(TEXT("Projectile")),
        HitLocation,
        LaunchSpeed,
        false,
        0.0f,
        0.0f,
        ESuggestProjVelocityTraceOption::DoNotTrace);
    
    if (!result)
    {
        return;
    }

    FVector AimDirection = TossVelocity.GetSafeNormal();

    MoveBarrelTowards(AimDirection);
}


void UTankAimingComponent::MoveBarrelTowards(FVector const &AimDirection)
{
    FRotator const BarrelRotator = Barrel->GetForwardVector().Rotation();
    FRotator const AimRotator = AimDirection.Rotation();
    FRotator const DeltaRotator = AimRotator - BarrelRotator;
    Barrel->Elevate(DeltaRotator.Pitch);
    Turret->Rotate(DeltaRotator.Yaw);
}


void UTankAimingComponent::Fire()
{
    UE_LOG(LogTemp, Warning, TEXT("Fire..."));

    bool isReloaded = FPlatformTime::Seconds() - LastFireSeconds > ReloadTimeInSeconds;

    if (isReloaded && Barrel && ProjectileBlueprint) {
        FVector const Location = Barrel->GetSocketLocation(FName("Projectile"));
        FRotator const Rotation = Barrel->GetSocketRotation(FName("Projectile"));

        AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Location, Rotation);
        verify(Projectile != nullptr);
        Projectile->LaunchProjectile(LaunchSpeed);

        LastFireSeconds = FPlatformTime::Seconds();
    }
}
