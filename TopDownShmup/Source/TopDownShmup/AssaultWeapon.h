// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "AssaultWeapon.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNSHMUP_API AAssaultWeapon : public AWeapon
{
	GENERATED_BODY()

public:
	AAssaultWeapon();

	// override OnStartFire() and OnStopFire()
	virtual void OnStartFire() override;
	virtual void OnStopFire() override;
	
	// assault weapon firing
	UPROPERTY(EditAnywhere)
	float FireRate;
	UPROPERTY(EditAnywhere)
	float WeaponRange;
	UPROPERTY(EditDefaultsOnly, Category = Effects)
	UParticleSystem* HitEffect;

protected:
	// fires a ray from assault rifle
	void WeaponTrace();
	FTimerHandle WeaponTimerHandle;
};
