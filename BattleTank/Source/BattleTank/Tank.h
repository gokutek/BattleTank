// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

    void AimAt(FVector const& HitLocation);

    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetBarrel(UTankBarrel* Barrel);

    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetTurret(UTankTurret* Turret);

protected:
    UPROPERTY()
    UTankAimingComponent* AimingComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
    UPROPERTY(EditAnywhere, Category = Firing)
    float LaunchSpeed;
};
