// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API UTankBarrel : public UInstancedStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    void Elevate();
};
