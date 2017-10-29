// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "DrawDebugHelpers.h"
void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	controlledTank = getControlledTank();
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}
void ATankPlayerController::AimTowardsCrosshair()
{
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		if (controlledTank)
		{
			controlledTank->AimAt(HitLocation);
		}
	}
}
bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation)
{
	// find crosshair pixel coordinates 
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY  * CrossHairYLocation);

	// converting screen location to world space
	FVector WorldLocation, WorldDirection;
	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, WorldDirection);
	//UE_LOG(LogTemp, Warning, TEXT("Camera's World Location : %s , World Direction : %s"), *WorldLocation.ToString(), *WorldDirection.ToString());

	//line trace through that lookDirection
	FVector Start = WorldLocation;
	FVector End = Start + WorldDirection*LineTraceRange;
	FHitResult Hit;

	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility))
	{ 
		HitLocation = Hit.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}
ATank* ATankPlayerController::getControlledTank() const{
	return Cast<ATank>(GetPawn());
}
