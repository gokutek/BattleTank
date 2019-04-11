// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere)
    float CrosshairPositionX = 0.5f; // 在屏幕上的位置与视口的比例
    
    UPROPERTY(EditAnywhere)
    float CrosshairPositionY = 0.3333f;

public:
    virtual void BeginPlay() override;

    virtual void Tick(float DeltaTime) override;

    ATank* GetControllerTank() const;

    void AimTowardsCrosshair();

    bool GetSightRayHitLocation(FVector& HitLocation) const;
};
