// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Engine/World.h "

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true; // TODO should it tick ? 

	// ...
}



void UTankAimingComponent::AimAt(FVector AimLocation , float LaunchSpeed)
{
	//auto ControlledTankName = GetOwner()->GetName();
	//auto BarrelLocation = Barrel->GetComponentLocation().ToString();
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	FVector EndLocation = AimLocation;
	bool CalculatedAimDirection = UGameplayStatics::SuggestProjectileVelocity(this,
		OutLaunchVelocity,
		StartLocation,
		EndLocation,
		LaunchSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if (CalculatedAimDirection)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto Time = GetWorld()->GetRealTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f , %s Firing at Direction of : %s"), Time ,*GetOwner()->GetName() , *AimDirection.ToString());
		MoveBarrel(AimDirection);
	}
	else {
		auto Time = GetWorld()->GetRealTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f ,%s haven't found a target "), Time , *GetOwner()->GetName());

	}
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	auto BarrelRotation = Barrel->GetForwardVector().Rotation();
	auto AimAsRotation = AimDirection.Rotation();
	auto DeltaRotation = AimAsRotation - BarrelRotation;
	Barrel->Elevate(5);
}

void UTankAimingComponent::SetBarrel(UTankBarrel * BarrelTSet)
{
	Barrel = BarrelTSet;

}

