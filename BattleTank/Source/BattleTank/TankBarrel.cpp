// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
    RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);

    float ElevationChange = RelativeSpeed * MaxDegreesPerSeconds * GetWorld()->DeltaTimeSeconds;
    float NewPitch = ElevationChange + RelativeRotation.Pitch;
    NewPitch = FMath::Clamp(NewPitch, MinElevateDegrees, MaxElevateDegrees);
    SetRelativeRotation(FRotator(NewPitch, 0.f, 0.f));
}
