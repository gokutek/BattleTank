// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
    // ��̹�˵ĸ����ʩ��һ����
    FVector Force = GetForwardVector() * Throttle * TrackMaxDrivingForce;
    UPrimitiveComponent* Tank = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    Tank->AddForceAtLocation(Force, GetComponentLocation());
}
