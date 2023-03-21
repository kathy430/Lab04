// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIEnemyController.h"
#include "Kismet/GameplayStatics.h"
#include "AIDwarfController.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNSHMUP_API AAIDwarfController : public AAIEnemyController
{
	GENERATED_BODY()
	
public:
	// override OnPossess function
	virtual void OnPossess(APawn* Pawn) override;

	// override BeginPlay function
	virtual void BeginPlay() override;

	// override OnMoveCompleted function
	virtual void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result) override;

	// pointer to dwarf
	APawn* MyDwarf;
};
