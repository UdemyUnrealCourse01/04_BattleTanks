// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

private:
	UTankAimingComponent* TankAimingComponent = nullptr;
	UTankBarrel* Barrel = nullptr; // local barrel reference to be used for spawning the projectile
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> Projectile;
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 100000.0;// 100 m /s , TODO Set Default speed to sensible value
	UPROPERTY(EditDefaultsOnly , Category = Firing)
	float ReloadTime = 3;
	float LastFireTime = 0;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable , Category = Setup)
	void SetBarrel(UTankBarrel* BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurret(UTankTurret* TurretToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Fire();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
