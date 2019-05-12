// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrel(UTankBarrel* Barrel)
{
    this->Barrel = Barrel;
}


void UTankAimingComponent::SetTurret(UTankTurret* Turret)
{
    this->Turret = Turret;
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UTankAimingComponent::AimAt(FVector const &HitLocation, float LaunchSpeed)
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
}
