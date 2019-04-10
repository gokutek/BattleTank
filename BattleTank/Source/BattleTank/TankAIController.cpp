// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
    ATank* tank = GetPlayerTank();
    if (tank)
    {
        UE_LOG(LogTemp, Warning, TEXT("ATankAIController::BeginPlay: %s"), *tank->GetName());
    }
}


ATank* ATankAIController::GetPlayerTank() const
{
    return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
