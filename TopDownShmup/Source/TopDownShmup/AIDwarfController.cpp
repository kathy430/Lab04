// Fill out your copyright notice in the Description page of Project Settings.


#include "AIDwarfController.h"

void AAIDwarfController::OnPossess(APawn* Pawn)
{
	Super::OnPossess(Pawn);

	// store pointer to current pawn
	MyDwarf = Pawn;
}

void AAIDwarfController::BeginPlay()
{
	Super::BeginPlay();

	// get player's pawn
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	// tell dwarf to move towards player
	MoveToActor(PlayerPawn);
}

void AAIDwarfController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	Super::OnMoveCompleted(RequestID, Result);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, FString::Printf(TEXT("move completed")));
	}
}

EDwarfState AAIDwarfController::GetCurrentDwarfState() const
{
	return CurrentDwarfState;
}

void AAIDwarfController::SetCurrentDwarfState(EDwarfState NewState)
{
	CurrentDwarfState = NewState;
}