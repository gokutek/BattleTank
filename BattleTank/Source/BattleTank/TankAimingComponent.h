﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTankTurret;


UENUM()
enum class EFiringState : uint8
{
    Reloading,
    Aiming,
    Locked
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

    // 设置炮筒、炮台组件的引用
    UFUNCTION(BlueprintCallable, Category = "Setup")
    void Initialise(UTankBarrel* Barrel, UTankTurret* Turret);

    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    // 将炮筒以指定的速度瞄向指定的点
    void AimAt(FVector const &HitLocation, float LaunchSpeed);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
    void MoveBarrelTowards(FVector const &AimDirection);

protected:
    UPROPERTY(BlueprintReadOnly, Category = "State")
    EFiringState FiringState = EFiringState::Reloading;

private:
    UPROPERTY()
    UTankBarrel* Barrel;

    UPROPERTY()
    UTankTurret* Turret;
};
