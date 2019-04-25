// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hideCategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, Category = Setup)
    float MaxDegreesPerSeconds = 20;

    UPROPERTY(EditAnywhere, Category = Setup)
    float MaxElevateDegrees = 40; // ��Ͳ���Ͽ���̧������Ƕ�
    
    UPROPERTY(EditAnywhere, Category = Setup)
    float MinDegreesPerSeconds = 0; // ��Ͳ���¿���̧������Ƕ�

public:
    void Elevate();
};
