// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
}


void ATankPlayerController::Possess(APawn * InPawn)
{
    Super::Possess(InPawn);

    if (InPawn)
    {
        UE_LOG(LogTemp, Warning, TEXT("ATankPlayerController::Possess: %s"), *InPawn->GetName());
    }
}


ATank* ATankPlayerController::GetControllerTank() const
{
    return Cast<ATank>(Super::GetPawn());
}
