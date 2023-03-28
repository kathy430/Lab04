// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Engine/TargetPoint.h>
#include "DwarfCharacter.h"
#include "SpawnManager.generated.h"

UCLASS()
class TOPDOWNSHMUP_API ASpawnManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpawnManager();

	UPROPERTY(EditAnywhere, Category = Spawn)
		TArray<ATargetPoint*> targetPoints;

	UPROPERTY(EditAnywhere, Category = Spawn)
		TSubclassOf<ADwarfCharacter> Character;

	UPROPERTY(EditAnywhere, Category = Spawn)
		float minSpawnTime;

	UPROPERTY(EditAnywhere, Category = Spawn)
		float maxSpawnTime;

	void SpawnCharacter();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	ACharacter* TheDwarf;
	ADwarfCharacter* ADwarf = Cast<ADwarfCharacter>(TheDwarf);
};