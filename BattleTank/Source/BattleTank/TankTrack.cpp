// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

UTankTrack::UTankTrack()
{
    PrimaryComponentTick.bCanEverTick = true;
}


void UTankTrack::BeginPlay()
{
    Super::BeginPlay();

    OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}


void UTankTrack::ApplySidewaysForce()
{
    float SlippageSpeed = FVector::DotProduct(GetComponentVelocity(), GetRightVector());

    // Work-out the required acceleration this frame to correct
    FVector CorrectionAcceleration = -SlippageSpeed / GetWorld()->GetDeltaSeconds() * GetRightVector();

    // Calculate and apply sideways (F = m a)
    UStaticMeshComponent* TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
    FVector CorrectionForce = TankRoot->GetMass() * CorrectionAcceleration / 2; // Two tracks
    TankRoot->AddForce(CorrectionForce);
}


void UTankTrack::SetThrottle(float Throttle)
{
    CurrentThrottle = FMath::Clamp(CurrentThrottle + Throttle, -1.0f, 1.0f);
}


void UTankTrack::DriveTank()
{
    // 给坦克的根组件施加一个力
    FVector Force = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
    UPrimitiveComponent* Tank = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    Tank->AddForceAtLocation(Force, GetComponentLocation());
}


void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    UE_LOG(LogTemp, Warning, TEXT(" UTankTrack::OnHit"));
    DriveTank();
    ApplySidewaysForce();
    CurrentThrottle = 0.0f;
}
