// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	ControlledTank = getControlledTank();
	LocatedPlayerTank = GetPlayerTank();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (ControlledTank)
	{
		if (LocatedPlayerTank)
		{
			// Move Towards PlayerTank
			ControlledTank->AimAt(LocatedPlayerTank->GetActorLocation());
			// Fire when Ready
		}
	}
}

ATank * ATankAIController::getControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank()
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
