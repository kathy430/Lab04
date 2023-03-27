// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TopDownShmupPlayerController.h"
#include "TopDownShmup.h"
#include "TopDownShmupCharacter.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

ATopDownShmupPlayerController::ATopDownShmupPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void ATopDownShmupPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		//MoveToMouseCursor();
	}

	// update actor rotation based on mouse
	UpdateMouseLook();
}

void ATopDownShmupPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// support touch devices 
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &ATopDownShmupPlayerController::MoveToTouchLocation);
	InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &ATopDownShmupPlayerController::MoveToTouchLocation);

	// set up movement
	InputComponent->BindAxis("MoveForward", this, &ATopDownShmupPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ATopDownShmupPlayerController::MoveRight);

	// set up gun control
	InputComponent->BindAction("Fire", IE_Pressed, this, &ATopDownShmupPlayerController::OnStartFire);
	InputComponent->BindAction("Fire", IE_Released, this, &ATopDownShmupPlayerController::OnStopFire);
}

void ATopDownShmupPlayerController::MoveToMouseCursor()
{
	// Trace to see what is under the mouse cursor
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(Hit.ImpactPoint);
	}
}

void ATopDownShmupPlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void ATopDownShmupPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const Pawn = GetPawn();
	if (Pawn)
	{
		float const Distance = FVector::Dist(DestLocation, Pawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
        if (Distance > 120.0f)
		{
            UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
	}
}

// moves character forward/backward
void ATopDownShmupPlayerController::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		APawn* const Pawn = GetPawn();
		if (Pawn)
		{
			Pawn->AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);
		}
	}
}

// moves character left/right
void ATopDownShmupPlayerController::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		APawn* const Pawn = GetPawn();
		if (Pawn)
		{
			Pawn->AddMovementInput(FVector(0.0f, 1.0f, 0.0f), Value);
		}
	}
}

// changes the direction the character faces based on mouse location
void ATopDownShmupPlayerController::UpdateMouseLook()
{
	if (IsLookInputIgnored())
	{
		// if look input is ignored leave function
		return;
	}
	
	APawn* const Pawn = GetPawn();
	if (Pawn)
	{
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);
		if (Hit.bBlockingHit)
		{
			// get new direction
			FVector newDirection = Hit.ImpactPoint - Pawn->GetActorLocation();
			newDirection.Z = 0.0f;
			newDirection = newDirection.GetSafeNormal();

			// get new rotation and set it
			FRotator newRotation = newDirection.Rotation();
			Pawn->SetActorRotation(newRotation);
		}
	}
}

// calls on start fire on character
void ATopDownShmupPlayerController::OnStartFire()
{
	// get the pawn
	APawn* const Pawn = GetPawn();
	if (Pawn)
	{
		// cast to character class type
		ATopDownShmupCharacter* MyCharacter = Cast<ATopDownShmupCharacter>(Pawn);

		// if player is dead, don't let player fire
		if (MyCharacter->IsDead())
		{
			return;
		}
		MyCharacter->OnStartFire();
	}
}

// calls on stop fire on character
void ATopDownShmupPlayerController::OnStopFire()
{
	// get the pawn
	APawn* const Pawn = GetPawn();
	if (Pawn)
	{
		// cast to character class type
		ATopDownShmupCharacter* MyCharacter = Cast<ATopDownShmupCharacter>(Pawn);

		//  if player is dead, don't let player fire/stop firing
		if (MyCharacter->IsDead())
		{
			return;
		}
		MyCharacter->OnStopFire();
	}
}