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
    float MaxDegreesPerSeconds = 5; // 每秒移动的角度

    UPROPERTY(EditAnywhere, Category = Setup)
    float MaxElevateDegrees = 40; // 炮筒向上可以抬起的最大角度
    
    UPROPERTY(EditAnywhere, Category = Setup)
    float MinElevateDegrees = 0; // 炮筒向下可以抬起的最大角度

public:
    // 改变Pitch
    void Elevate(float RelativeSpeed);
};
