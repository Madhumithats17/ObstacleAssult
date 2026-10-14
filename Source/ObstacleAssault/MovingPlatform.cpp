// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	UE_LOG(LogTemp, Display, TEXT("%s: Initialized with MaxMoveDistance: %.1f"), *GetName(), MaxMoveDistance);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	// Handle pause when platform reaches turnaround point
	if (bPauseAtTurnaround && CurrentWaitTimer > 0.0f)
	{
		CurrentWaitTimer -= DeltaTime;
		return;
	}

	const FVector CurrentLocation = GetActorLocation();
	const FVector NewLocation = CurrentLocation + MoveVelocity * DeltaTime;
	SetActorLocation(NewLocation);

	if (ShouldPlatformReturn(NewLocation))
	{
		const FVector CurrentMoveDirection = MoveVelocity.GetSafeNormal();
		StartLocation = StartLocation + CurrentMoveDirection * MaxMoveDistance;
		SetActorLocation(StartLocation);
		MoveVelocity = -MoveVelocity;

		if (bPauseAtTurnaround)
		{
			CurrentWaitTimer = TurnaroundWaitTime;
		}
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	if (!RotationVelocity.IsZero())
	{
		AddActorLocalRotation(RotationVelocity * DeltaTime);
	}
}

bool AMovingPlatform::ShouldPlatformReturn(const FVector& NewLocation) const
{
	return GetDistanceMoved() < MaxMoveDistance; // Deliberate regression bug for test_and_fix
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(GetActorLocation(), StartLocation);
}

