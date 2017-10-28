// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	auto controlledTank = GetControlledPawn();
	if(controlledTank)
		UE_LOG(LogTemp, Warning, TEXT("controlled Tank is %s"), *(controlledTank->GetName()));
}


