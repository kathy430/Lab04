// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIEnemyController.h"
#include "AIDwarfController.generated.h"

/**
 * 
 */

// all possible dwarf states
enum class EDwarfState : short
{
	EStart, EChasing, EAttacking, EDead, EUnknown
};

UCLASS()
class TOPDOWNSHMUP_API AAIDwarfController : public AAIEnemyController
{
	GENERATED_BODY()
	
public:
	// called every frame
	virtual void Tick(float DeltaTime) override;

	// override OnPossess function
	virtual void OnPossess(APawn* Pawn) override;

	// override OnMoveCompleted function
	virtual void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result) override;

	// get current dwarf state
	EDwarfState GetCurrentDwarfState() const;

	// set current dwarf state
	void SetCurrentDwarfState(EDwarfState NewState);

	// pointer to dwarf pawn
	APawn* DwarfPawn;

protected:
	// override BeginPlay function
	virtual void BeginPlay() override;

private:
	EDwarfState CurrentDwarfState;

	// handle new dwarf states
	void HandleNewState(EDwarfState NewState);

	// variables to keep track of range between dwarf and player
	float MaxRange = 150.0f;
	float CurrentRange;
};
