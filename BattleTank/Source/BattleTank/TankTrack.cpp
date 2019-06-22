// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

UTankTrack::UTankTrack()
{
    PrimaryComponentTick.bCanEverTick = true;
}


void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    float SlippageSpeed = FVector::DotProduct(GetComponentVelocity(), GetRightVector());

    // Work-out the required acceleration this frame to correct
    FVector CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

    // Calculate and apply sideways (F = m a)
    UStaticMeshComponent* TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
    FVector CorrectionForce = TankRoot->GetMass() * CorrectionAcceleration / 2; // Two tracks
    TankRoot->AddForce(CorrectionForce);

}


void UTankTrack::SetThrottle(float Throttle)
{
    // 给坦克的根组件施加一个力
    FVector Force = GetForwardVector() * Throttle * TrackMaxDrivingForce;
    UPrimitiveComponent* Tank = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    Tank->AddForceAtLocation(Force, GetComponentLocation());
}
