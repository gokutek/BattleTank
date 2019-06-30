// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"


class ATank;


/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
    UPROPERTY(EditAnywhere, Category = "Setup")
    float Distance = 8000.f;
	
public:
    ATankAIController();

    virtual void BeginPlay() override;

    virtual void Tick(float DeltaTime) override;
};
