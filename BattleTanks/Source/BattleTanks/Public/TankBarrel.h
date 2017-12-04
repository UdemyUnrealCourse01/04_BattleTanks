// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 for min elevation , +1 for maxElevation
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 5; //sensible default value
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxElevationAngle = 30;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinElevationAngle = 0;
};
