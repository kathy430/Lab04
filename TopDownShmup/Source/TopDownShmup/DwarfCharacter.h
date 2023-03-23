// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyCharacter.h"
#include "DwarfCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNSHMUP_API ADwarfCharacter : public AEnemyCharacter
{
	GENERATED_BODY()
	
public:
	// sets default values for this character's properties
	ADwarfCharacter();

	UPROPERTY(EditDefaultsOnly)
	UAnimMontage* AttackAnim;

	// attack functions
	void StartAttack();
	void StopAttack();

	// override TakeDamage
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

private:
	UPROPERTY(EditAnywhere)
	float Health;

	UPROPERTY(EditAnywhere)
	float AttackDamage;
};
