// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	APawn* controlledTank;
	ATank* getControlledTank() const;
	bool tickIsworking = false;
	void BeginPlay() override;
	void Tick(float DeltaTime) override;
};
