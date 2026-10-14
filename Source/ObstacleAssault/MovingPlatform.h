// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	bool ShouldPlatformReturn(const FVector& NewLocation) const;
	float GetDistanceMoved() const;

public:
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	FVector MoveVelocity;

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	float MaxMoveDistance { 0 };

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	FRotator RotationVelocity;

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	bool bPauseAtTurnaround { false };

	UPROPERTY(EditAnywhere, Category = "Moving Platform", meta = (EditCondition = "bPauseAtTurnaround"))
	float ReturnWaitTime { 1.0f };

private:
	FVector StartLocation;
	float CurrentWaitTimer { 0.0f };
};
