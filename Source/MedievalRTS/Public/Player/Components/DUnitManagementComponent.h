// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Units/DUnit.h"

#include "DUnitManagementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MEDIEVALRTS_API UDUnitManagementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDUnitManagementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	TArray<ADUnit*> Units;

	UPROPERTY()
	TArray<ADUnit*> SelectedUnits;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Used when spawning
	void AddUnit(ADUnit* NewUnit);

	void RemoveUnit(ADUnit* UnitToRemove);

	//Used when selecting
	TArray<ADUnit*> GetSelectedUnits() const;
	
	int GetNumberOfSelectedUnits() const;
	
	void AddSelectedUnit(ADUnit* SelectedUnit);

	void RemoveSelectedUnit(ADUnit* UnitToRemove);

	void ClearSelectedUnits();
};
