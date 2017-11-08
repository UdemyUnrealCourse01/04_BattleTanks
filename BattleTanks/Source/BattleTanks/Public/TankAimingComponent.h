// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	// Called every frame
	void AimAt(FVector AimLocation , float LaunchSpeed);
	void MoveTurret(FVector AimDirection);
	void SetBarrel(UTankBarrel* BarrelTSet);
	void SetTurret(UTankTurret* TurretToSet);
protected:
	

private: 
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	
};
