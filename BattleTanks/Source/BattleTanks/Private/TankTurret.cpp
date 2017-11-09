// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Runtime/Engine/Classes/Engine/World.h"
void UTankTurret::Rotate(float RelativeSpeed)
{
	auto clampedSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = clampedSpeed * RotationSpeed * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + RotationChange;
	//UE_LOG(LogTemp, Warning, TEXT(" yaw rotation of turret %f "), NewRotation);
	SetRelativeRotation(FRotator(0, NewRotation, 0));
}
