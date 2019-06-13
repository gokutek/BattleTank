// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"


ATankAIController::ATankAIController()
{
    PrimaryActorTick.bCanEverTick = true;
}


void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
}


void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // 将AI控制的坦克瞄准玩家控制的坦克
    ATank* OurTank = Cast<ATank>(GetPawn());
    ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
    if (OurTank && PlayerTank)
    {
        MoveToActor(PlayerTank, Distance);
        UTankAimingComponent* AimingComponent = OurTank->FindComponentByClass<UTankAimingComponent>();
        ensure(AimingComponent);
        AimingComponent->AimAt(PlayerTank->GetActorLocation());
        OurTank->Fire();
    }
}
