// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
    // 给坦克的根组件施加一个力
    FVector Force = GetForwardVector() * Throttle * TrackMaxDrivingForce;
    UPrimitiveComponent* Tank = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    Tank->AddForceAtLocation(Force, GetComponentLocation());
}
