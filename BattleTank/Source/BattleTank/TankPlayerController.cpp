// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
}


void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    AimTowardsCrosshair();
}


ATank* ATankPlayerController::GetControllerTank() const
{
    return Cast<ATank>(Super::GetPawn());
}


void ATankPlayerController::AimTowardsCrosshair()
{
    FVector HitLocation;
    if (GetSightRayHitLocation(HitLocation))
    {

    }
}


bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
    // ��ȡ׼�ĵ���Ļ����
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    FVector2D ScreenLocation(ViewportSizeX * CrosshairPositionX, ViewportSizeY * CrosshairPositionY);

    // ��Ļ����ת3D����

    return true;
}
