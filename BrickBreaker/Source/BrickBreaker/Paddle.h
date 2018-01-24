// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Paddle.generated.h"

UCLASS()
class BRICKBREAKER_API APaddle : public APawn
{
    GENERATED_BODY()

public:
    // Sets default values for this pawn's properties
    APaddle();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    //Input functions
    void Move_XAxis(float AxisValue);
    void FireBall();



    UPROPERTY(EditAnywhere)
    UStaticMeshComponent* PaddleComponent;

    //Input variables
    FVector CurrentVelocity;
};
