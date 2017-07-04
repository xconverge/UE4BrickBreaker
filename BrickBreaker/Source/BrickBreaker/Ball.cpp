// Fill out your copyright notice in the Description page of Project Settings.

#include "Ball.h"

static float k_defaultBallSpeed = 750.0f;

// Sets default values
ABall::ABall()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Create a dummy root component we can attach things to.
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    RootComponent->SetMobility(EComponentMobility::Movable);

    // Create a paddle mesh
    BallComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallComponent"));
    BallComponent->SetupAttachment(RootComponent);

    RootComponent->SetMobility(EComponentMobility::Movable);
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
    Super::BeginPlay();
    FVector startingVelocity = FVector(k_defaultBallSpeed, -k_defaultBallSpeed, 0.0);
    BallComponent->SetPhysicsLinearVelocity(startingVelocity);
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector clampedVelocity = ConstrainTo(BallComponent->GetPhysicsLinearVelocity(), FMath::DegreesToRadians(45.0f), k_defaultBallSpeed);
    //BallComponent->SetPhysicsLinearVelocity(clampedVelocity);
     UE_LOG(LogTemp, Warning, TEXT("loc %s"), *BallComponent->GetComponentLocation().ToString());
}

 FVector ABall::ConstrainTo(FVector inputVector, float snapAngle, float maxVelocity) {

     float   angle = FMath::Acos(FVector::DotProduct(inputVector, FVector::UpVector));

     //if (angle < snapAngle / 2.0f) {                        // Cannot do cross product 
     //UE_LOG(LogTemp, Warning, TEXT("aaa %f"),angle);
     //    return FVector::UpVector * inputVector.Size();     //   with angles 0 & 180
     //}                                          
     //if (angle > 180.0f - snapAngle / 2.0f) {
     //UE_LOG(LogTemp, Warning, TEXT("bbb %f "),angle);
     //    return FVector::UpVector * -inputVector.Size();
     //}


     //float t = round(angle / snapAngle);
     //float deltaAngle = (t * snapAngle) - angle;

     //FVector axis = FVector::CrossProduct(inputVector.UpVector, inputVector);
     //FQuat q(axis, deltaAngle);

     //FVector outputVector = q * inputVector;

     UE_LOG(LogTemp, Warning, TEXT("ccc %f %s"),angle, *inputVector.ToString());

     return inputVector;
 }

