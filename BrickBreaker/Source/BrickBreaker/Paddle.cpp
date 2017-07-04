// Fill out your copyright notice in the Description page of Project Settings.

#include "Paddle.h"


// Sets default values
APaddle::APaddle()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Set this pawn to be controlled by the lowest-numbered player
    AutoPossessPlayer = EAutoReceiveInput::Player0;

    // Create a dummy root component we can attach things to.
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    RootComponent->SetMobility(EComponentMobility::Movable);

    // Create a paddle mesh
    PaddleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PaddleComponent"));
    PaddleComponent->SetupAttachment(RootComponent);

    RootComponent->SetMobility(EComponentMobility::Movable);
}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void APaddle::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Handle movement based on our "MoveX" axes
    PaddleComponent->SetPhysicsLinearVelocity(FVector(CurrentVelocity * DeltaTime * 500.f));
}

// Called to bind functionality to input
void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Respond when our "fire" key is pressed or released.
    InputComponent->BindAction("Fire", IE_Pressed, this, &APaddle::FireBall);

    // Respond every frame to the values of our two movement axes, "MoveX" and "MoveY".
    InputComponent->BindAxis("MoveHorizontal", this, &APaddle::Move_XAxis);

}

void APaddle::Move_XAxis(float AxisValue)
{
    // Move at 100 units per second forward or backward
    CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 200.0f;
}

void APaddle::FireBall()
{
}

