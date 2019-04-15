// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"


ATankAIController::ATankAIController()
{
    PrimaryActorTick.bCanEverTick = true;
}


void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

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


void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // 将AI控制的坦克瞄准玩家控制的坦克
    ATank* OurTank = Cast<ATank>(GetPawn());
    ATank* PlayerTank = GetPlayerTank();
    if (OurTank && PlayerTank)
    {
        OurTank->AimAt(PlayerTank->GetActorLocation());
    }
}
