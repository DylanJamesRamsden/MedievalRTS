// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Core/DEconomy.h"
#include "Core/Enums/DTeam.h"
#include "GameFramework/PlayerState.h"
#include "DPlayerState.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FResourceChanged, EDResource, Resource, int, Value);

UCLASS()
class MEDIEVALRTS_API ADPlayerState : public APlayerState
{
	GENERATED_BODY()

	protected:
	
	UPROPERTY(Replicated)
	TEnumAsByte<EDTeam> Team = Unassigned;

	UPROPERTY()
	FDEconomy Economy;

	UPROPERTY(EditDefaultsOnly, Category = "Player State|Economy")
	FDataTableRowHandle StartingPlayerEconomyRow;

	virtual void BeginPlay() override;

	public:
	void SetTeam(TEnumAsByte<EDTeam> NewTeam);

	UFUNCTION(BlueprintCallable)
	TEnumAsByte<EDTeam> GetTeam() const;

	UPROPERTY(BlueprintAssignable)
	FResourceChanged OnResourceChanged;

	UFUNCTION(BlueprintCallable)
	int GetGold() const;

	UFUNCTION(BlueprintCallable)
	int GetWood() const;

	UFUNCTION(BlueprintCallable)
	int GetFood() const;

	UFUNCTION(BlueprintCallable)
	int GetStone() const;
	
	UFUNCTION(BlueprintCallable)
	void AddResource(TEnumAsByte<EDResource> ResourceType, int Amount);

	UFUNCTION(BlueprintCallable)
	void InitializePlayerEconomy();
};
