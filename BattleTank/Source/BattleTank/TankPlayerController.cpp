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
    // 获取准心的屏幕坐标
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    FVector2D ScreenLocation(ViewportSizeX * CrosshairPositionX, ViewportSizeY * CrosshairPositionY);

    // 屏幕坐标转3D坐标
    FVector CameraWorldPosition;
    FVector WorldDirection;
    if (!DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldPosition, WorldDirection))
    {
        return false;
    }

    UE_LOG(LogTemp, Warning, TEXT("WorldDirection = %s"), *WorldDirection.ToString());

    // Trace
    return true;
}
