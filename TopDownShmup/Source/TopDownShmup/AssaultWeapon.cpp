// Fill out your copyright notice in the Description page of Project Settings.


#include "AssaultWeapon.h"

// sets default values
AAssaultWeapon::AAssaultWeapon()
{
	FireRate = 0.05f;
	WeaponRange = 10000.0f;
}

// override on start fire
void AAssaultWeapon::OnStartFire()
{
	Super::OnStartFire();

	// call weapon trace every fire rate seconds
	GetWorldTimerManager().SetTimer(WeaponTimerHandle, this, &AAssaultWeapon::WeaponTrace, FireRate, true);
}

// override on stop fire
void AAssaultWeapon::OnStopFire()
{
	Super::OnStopFire();

	// end weapon trace call
	GetWorldTimerManager().ClearTimer(WeaponTimerHandle);
}

void AAssaultWeapon::WeaponTrace()
{
	static FName WeaponFireTag = FName(TEXT("WeaponTrace"));
	static FName MuzzleSocket = FName(TEXT("MuzzleFlashSocket"));

	// Start from the muzzle's position
	FVector StartPos = WeaponMesh->GetSocketLocation(MuzzleSocket);
	// Get forward vector of MyPawn
	FVector Forward = MyPawn->GetActorForwardVector();
	// Calculate end position
	FVector EndPos = StartPos + Forward.GetSafeNormal() * WeaponRange;
	// Perform line trace to retrieve hit info
	FCollisionQueryParams TraceParams(WeaponFireTag, true, GetInstigator());

	// This fires the ray and checks against all objects w/ collision
	FHitResult Hit(ForceInit);
	GetWorld()->LineTraceSingleByObjectType(Hit, StartPos, EndPos,
		FCollisionObjectQueryParams::AllObjects, TraceParams);

	// Did this hit anything?
	if (Hit.bBlockingHit)
	{
		// spawn impact particle at hit location
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HitEffect, Hit.Location);
	}
}