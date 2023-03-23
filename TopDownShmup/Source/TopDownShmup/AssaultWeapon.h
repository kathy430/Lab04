// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "TimerManager.h"
#include "AssaultWeapon.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNSHMUP_API AAssaultWeapon : public AWeapon
{
	GENERATED_BODY()

public:
	// sets default values
	AAssaultWeapon();

	// override OnStartFire() and OnStopFire()
	virtual void OnStartFire() override;
	virtual void OnStopFire() override;

protected:
	// fires a ray from assault rifle
	void WeaponTrace();

private:
	// assault weapon firing
	UPROPERTY(EditAnywhere)
	float FireRate;
	UPROPERTY(EditAnywhere)
	float WeaponRange;
	UPROPERTY(EditDefaultsOnly, Category = Effects)
	UParticleSystem* HitEffect;

	FTimerHandle WeaponTimerHandle;

	UPROPERTY(EditAnywhere)
	float AttackDamage;
};
