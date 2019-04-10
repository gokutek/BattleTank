// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
    ATank* tank = Cast<ATank>(GetPawn());
    if (tank)
    {
        UE_LOG(LogTemp, Warning, TEXT("ATankAIController::BeginPlay: %s"), *tank->GetName());
    }
}
