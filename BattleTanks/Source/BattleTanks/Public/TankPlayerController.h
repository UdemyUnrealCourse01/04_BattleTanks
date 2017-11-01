// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
class ATank;

UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	ATank* controlledTank;
	ATank* getControlledTank() const;
	void BeginPlay() override;
	void Tick(float DeltaTime) override;
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector &HitLocation);
private:
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5; // specified by us in the PlayerUI widget when we set the crosshair at 50% location of the widget 
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;// same but 33% in y direction
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 100000;
};
