// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;
}


void UTankMovementComponent::IntendMoveForward(float Throw)
{
    //UE_LOG(LogTemp, Warning, TEXT("throw:%f"), Throw);
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(Throw);
}


void UTankMovementComponent::IntendTurnRight(float Throw)
{
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(-Throw);
}


void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
    //UE_LOG(LogTemp, Warning, TEXT("RequestDirectMove: %s: %f"), *GetOwner()->GetName(), *MoveVelocity.ToString());
    FVector const TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
    FVector const AIForwardIntention = MoveVelocity.GetSafeNormal();

    float ForwardThrow = FVector::DotProduct(AIForwardIntention, TankForward);
    IntendMoveForward(ForwardThrow);

    FVector RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention);
    IntendMoveForward(RightThrow.Z);
}
