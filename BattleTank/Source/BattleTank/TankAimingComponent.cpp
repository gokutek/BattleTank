// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrel(UStaticMeshComponent* Barrel)
{
    this->Barrel = Barrel;
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

    UE_LOG(LogTemp, Warning, TEXT("%s: %s"), *GetOwner()->GetName(),
        *AimDirection.ToString());
}
