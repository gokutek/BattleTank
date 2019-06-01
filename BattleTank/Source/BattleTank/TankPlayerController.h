// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


class ATank;


/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly)
    float CrosshairPositionX = 0.5f; // ����Ļ�ϵ�λ�����ӿڵı���
    
    UPROPERTY(EditDefaultsOnly)
    float CrosshairPositionY = 0.3333f;

public:
    virtual void BeginPlay() override;

    virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable, Category = "Setup")
    ATank* GetControllerTank() const;

    void AimTowardsCrosshair();

    bool GetSightRayHitLocation(FVector& HitLocation) const;
};
