// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	controlledTank = GetPawn();
	if(controlledTank)
		UE_LOG(LogTemp, Warning , TEXT("controlledTank is %s"),(*(controlledTank->GetName())));
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!tickIsworking)
	{
		tickIsworking = true;
		UE_LOG(LogTemp, Warning, TEXT("tick is working"));
	}
}
ATank* ATankPlayerController::getControlledTank() const{
	return Cast<ATank>(GetPawn());
}
