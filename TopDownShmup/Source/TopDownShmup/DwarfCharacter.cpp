// Fill out your copyright notice in the Description page of Project Settings.


#include "DwarfCharacter.h"
#include "AIDwarfController.h"

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
	PlayAnimMontage(AttackAnim);
}

// stop dwarf attack
void ADwarfCharacter::StopAttack()
{
	StopAnimMontage();
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
			// Unposses the AI controller,
			AController* AIController = GetController();
			if (AIController)
			{
				AIController->UnPossess();
			}
			// Remove the dwarf from the world
			Destroy();
		}
	}

	return ActualDamage;
}