// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SPowerupActor.generated.h"

UCLASS()
class COOPGAME_API ASPowerupActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASPowerupActor();

protected:
	
	// Time between powerup ticks
	UPROPERTY(EditDefaultsOnly, Category = "PowerUps")
	float PowerupInterval;

	// Total times we applythe power effect
	UPROPERTY(EditDefaultsOnly, Category = "PowerUps")
	int32 TotalNrOfTicks;

	FTimerHandle TimerHandle_PowerupTick;

	//Total Number of ticks Applied
	int32 TicksProcessed;

	UFUNCTION()
	void OnTickPowerup();

	//Keeps Stateof the Power-up
	UPROPERTY(ReplicatedUsing = OnRep_PowerupActive)
	bool bIsPowerupActive;

	UFUNCTION()
	void OnRep_PowerupActive();

	UFUNCTION(BlueprintImplementableEvent, Category = "PowerUps")
	void OnPowerupStateChanged(bool bNewIsActive);

public:	
	
	void ActivatePowerup(AActor* ActiveFor);

	UFUNCTION(BlueprintImplementableEvent, Category = "PowerUps")
	void OnActivated(AActor* ActiveFor);

	UFUNCTION(BlueprintImplementableEvent, Category = "PowerUps")
	void OnPowerupTicked();

	UFUNCTION(BlueprintImplementableEvent, Category = "PowerUps")
	void OnExpired();

};
