// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
}


void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}


ATank* ATankPlayerController::GetControllerTank() const
{
    return Cast<ATank>(Super::GetPawn());
}


void ATankPlayerController::AimTowardsCrosshair()
{

}
