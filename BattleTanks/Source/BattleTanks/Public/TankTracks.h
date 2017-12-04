// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTracks.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankTracks : public UStaticMeshComponent
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float throttle);
		// MAx Force per track
		UPROPERTY(EditDefaultsOnly , Category = Moving)
		float TrackMaxDrivingForce = 400000; // assume force = mass * acceleration (40000 * 10 )
	
};
