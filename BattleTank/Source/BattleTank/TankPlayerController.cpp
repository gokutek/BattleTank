// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "TankAimingComponent.h"


void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    
    UTankAimingComponent* AimingComponent = GetControllerTank()->FindComponentByClass<UTankAimingComponent>();
    if (AimingComponent)
    {
        FoundAimingComponent(AimingComponent);
    }
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
        GetControllerTank()->AimAt(HitLocation);
    }
}


bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
    // 获取准心的屏幕坐标
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    FVector2D ScreenLocation(ViewportSizeX * CrosshairPositionX,
        ViewportSizeY * CrosshairPositionY);

    // 根据屏幕坐标，求摄像机坐标、观察方向
    FVector CameraWorldPosition;
    FVector LookDirection;
    if (!DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, 
        CameraWorldPosition, LookDirection))
    {
        return false;
    }

    // Trace
    FHitResult HitResult;
    FVector StartPosition = PlayerCameraManager->GetCameraLocation();
    FVector EndPosition = StartPosition + LookDirection * 1000000;
    if (!GetWorld()->LineTraceSingleByChannel(HitResult, 
        StartPosition,
        EndPosition,
        ECC_Visibility))
    {
        return false;
    }
    
    HitLocation = HitResult.Location;

    return true;
}
