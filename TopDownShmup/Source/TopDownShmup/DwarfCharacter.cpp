// Fill out your copyright notice in the Description page of Project Settings.


#include "DwarfCharacter.h"
#include "AIDwarfController.h"

// sets default values
ADwarfCharacter::ADwarfCharacter()
{
	AIControllerClass = AAIDwarfController::StaticClass();
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