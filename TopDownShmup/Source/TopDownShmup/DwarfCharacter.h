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
	void AttackPlayer();

	// override TakeDamage
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	// death animation
	UPROPERTY(EditDefaultsOnly)
	UAnimMontage* DeathAnim;
	void StartDeath();
	bool IsDead();

private:
	UPROPERTY(EditAnywhere)
	float Health;

	UPROPERTY(EditAnywhere)
	float AttackDamage;

	bool Dead;

	FTimerHandle AttackTimerHandle;
	FTimerHandle DeathTimerHandle;
};
