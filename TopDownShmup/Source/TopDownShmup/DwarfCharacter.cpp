// Fill out your copyright notice in the Description page of Project Settings.


#include "DwarfCharacter.h"
#include "AIDwarfController.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "TopDownShmupCharacter.h"

// sets default values
ADwarfCharacter::ADwarfCharacter()
{
	AIControllerClass = AAIDwarfController::StaticClass();
	Health = 20.0f;
	AttackDamage = 10.0f;
}

// start dwarf attack
void ADwarfCharacter::StartAttack()
{
	// set timer to damage 
	GetWorldTimerManager().SetTimer(AttackTimerHandle, this, &ADwarfCharacter::AttackPlayer, PlayAnimMontage(AttackAnim), true);
}

// stop dwarf attack
void ADwarfCharacter::StopAttack()
{
	StopAnimMontage();
	GetWorldTimerManager().ClearTimer(AttackTimerHandle);
}

// attack player and call take damage on player
void ADwarfCharacter::AttackPlayer()
{
	// get player character
	ATopDownShmupCharacter* PlayerCharacter = Cast<ATopDownShmupCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	// call take damage if player exists
	if (PlayerCharacter)
	{
		PlayerCharacter->TakeDamage(AttackDamage, FDamageEvent(), GetInstigatorController(), this);
	}
}

float ADwarfCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	if (ActualDamage > 0.0f)
	{
		// TODO: Add a debug message on screen to know dwarf got hit
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(3, 1.f, FColor::Yellow, FString::Printf(TEXT("You hit the dwarf")));
		}

		//Reduce health points
		Health -= ActualDamage;
		if (Health <= 0.0f)
		{
			// We're dead
			SetCanBeDamaged(false); // Don't allow further damage
			// TODO: Process death
			// Stop attack animation,
			StopAttack();
			// Remove the dwarf from the world
			GetWorldTimerManager().SetTimer(DeathTimerHandle, this, &ADwarfCharacter::Dying, PlayAnimMontage(DeathAnim), false);
		}
	}

	return ActualDamage;
}

// destroys dwarf character and stops death animation
void ADwarfCharacter::Dying()
{
	Destroy();
	StopAnimMontage(DeathAnim);
	GetWorldTimerManager().ClearTimer(DeathTimerHandle);
}