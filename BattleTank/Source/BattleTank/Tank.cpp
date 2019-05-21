// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "Projectile.h"
#include "TankBarrel.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    AimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


void ATank::AimAt(FVector const& HitLocation)
{
    AimingComponent->AimAt(HitLocation, LaunchSpeed);
}


void ATank::SetBarrel(UTankBarrel* Barrel)
{
    TankBarrel = Barrel;

    AimingComponent->SetBarrel(Barrel);
}


void ATank::SetTurret(UTankTurret* Turret)
{
    AimingComponent->SetTurret(Turret);
}


void ATank::Fire()
{
    UE_LOG(LogTemp, Warning, TEXT("Fire..."));

    if (!TankBarrel) { return; }

    FVector const Location = TankBarrel->GetSocketLocation(FName("Projectile"));
    FRotator const Rotation = TankBarrel->GetSocketRotation(FName("Projectile"));

    GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Location, Rotation);
}
