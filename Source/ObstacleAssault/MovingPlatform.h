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

	/** Velocity vector determining movement direction and speed */
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	FVector MoveVelocity;

	/** Maximum distance the platform can travel before reversing */
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	float MaxMoveDistance { 0 };

	/** Angular velocity determining rotation axis and speed */
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	FRotator RotationVelocity;

	/** If enabled, the platform will pause briefly when reaching the turnaround point */
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	bool bPauseAtTurnaround { false };

	/** Duration in seconds to wait at each turnaround point */
	UPROPERTY(EditAnywhere, Category = "Moving Platform", meta = (EditCondition = "bPauseAtTurnaround", ClampMin = "0.0"))
	float TurnaroundWaitTime { 1.0f };

private:
	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	bool ShouldPlatformReturn(const FVector& NewLocation) const;
	float GetDistanceMoved() const;

	FVector StartLocation;
	float CurrentWaitTimer { 0.0f };
};
