// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "TankMovementComponent.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}


void ATank::AimAt(FVector const& HitLocation)
{
    if (AimingComponent)
    {
        AimingComponent->AimAt(HitLocation, LaunchSpeed);
    }
}


void ATank::Fire()
{
    UE_LOG(LogTemp, Warning, TEXT("Fire..."));

    bool isReloaded = FPlatformTime::Seconds() - LastFireSeconds > ReloadTimeInSeconds;

    if (isReloaded && TankBarrel) {
        FVector const Location = TankBarrel->GetSocketLocation(FName("Projectile"));
        FRotator const Rotation = TankBarrel->GetSocketRotation(FName("Projectile"));

        AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Location, Rotation);
        verify(Projectile != nullptr);
        Projectile->LaunchProjectile(LaunchSpeed);

        LastFireSeconds = FPlatformTime::Seconds();
    }
}
