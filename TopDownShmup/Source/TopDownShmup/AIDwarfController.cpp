// Fill out your copyright notice in the Description page of Project Settings.


#include "AIDwarfController.h"
#include "Kismet/GameplayStatics.h"
#include "DwarfCharacter.h"
#include "TopDownShmupCharacter.h"

// sets default values for the AI dwarf controller
AAIDwarfController::AAIDwarfController()
{
	MaxRange = 150.0f;
}

// called when the game starts or when spawned
void AAIDwarfController::BeginPlay()
{
	Super::BeginPlay();

	// set dwarf to start state
	SetCurrentDwarfState(EDwarfState::EStart);
}

//  called every frame
void AAIDwarfController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	// if current state is start
	if (GetCurrentDwarfState() == EDwarfState::EStart)
	{
		// change current state to chasing
		SetCurrentDwarfState(EDwarfState::EChasing);
	}

	// if current state is attack
	if (GetCurrentDwarfState() == EDwarfState::EAttacking)
	{
		// get current distance between the player and dwarf
		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		CurrentRange = (PlayerPawn->GetActorLocation() - DwarfPawn->GetActorLocation()).Size();
		// if range is larger than max range
		if (CurrentRange > MaxRange)
		{
			// cast pawn to dwarf character to stop attack animation
			ADwarfCharacter* MyDwarf = Cast<ADwarfCharacter>(DwarfPawn);
			MyDwarf->StopAttack();

			// change current state to chase
			SetCurrentDwarfState(EDwarfState::EChasing);
		}

		// cast player pawn to a top down shmup character
		ATopDownShmupCharacter* ThePlayer = Cast<ATopDownShmupCharacter>(PlayerPawn);
		// if player is dead, stop attack animation
		if (ThePlayer)
		{
			if (ThePlayer->IsDead())
			{
				// cast pawn to dwarf character to stop attack animation
				ADwarfCharacter* MyDwarf = Cast<ADwarfCharacter>(DwarfPawn);
				MyDwarf->StopAttack();
			}
		}
	}

	if (GetCurrentDwarfState() == EDwarfState::EDead)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(6, 1.0f, FColor::Green, FString::Printf(TEXT("Dwarf dead")));
		}
	}
}

void AAIDwarfController::OnPossess(APawn* Pawn)
{
	Super::OnPossess(Pawn);

	// store pointer to current dwarf
	DwarfPawn = Pawn;
}

// change what the dwarf does after reaching the player's pawn
void AAIDwarfController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	Super::OnMoveCompleted(RequestID, Result);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, FString::Printf(TEXT("move completed")));
	}

	// change current state to attack
	SetCurrentDwarfState(EDwarfState::EAttacking);
}

// returns current dwarf state
EDwarfState AAIDwarfController::GetCurrentDwarfState() const
{
	return CurrentDwarfState;
}

// sets new dwarf state
void AAIDwarfController::SetCurrentDwarfState(EDwarfState NewState)
{
	// set new state
	CurrentDwarfState = NewState;

	// handle new state
	HandleNewState(CurrentDwarfState);
}

void AAIDwarfController::HandleNewState(EDwarfState NewState)
{
	switch (NewState)
	{
		case EDwarfState::EStart:
		{

		}
		break;
		case EDwarfState::EChasing:
		{
			// tell dwarf to move to player's pawn
			APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
			MoveToActor(PlayerPawn);
		}
		break;
		case EDwarfState::EAttacking:
		{
			// cast pawn to dwarf character
			ADwarfCharacter* MyDwarf = Cast<ADwarfCharacter>(DwarfPawn);
			// tell dwarf to start attack animation
			MyDwarf->StartAttack();
		}
		break;
		case EDwarfState::EDead:
		{

		}
		break;
		default:
		case EDwarfState::EUnknown:
		{

		}
		break;
	}
}