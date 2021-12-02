// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Buildings/DBuilding.h"
#include "Components/ActorComponent.h"
#include "DBuildingManagementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MEDIEVALRTS_API UDBuildingManagementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDBuildingManagementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	TArray<ADBuilding*> Buildings;
	
	UPROPERTY()
	TArray<ADBuilding*> SelectedBuildings;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Used when spawning
	void AddBuilding(ADBuilding* NewBuilding);

	void RemoveBuilding(ADBuilding* BuildingToRemove);

	//Used when selecting
	TArray<ADBuilding*> GetSelectedBuildings() const;
	
	int GetNumberOfSelectedBuildings() const;
	
	void AddSelectedBuilding(ADBuilding* SelectedBuilding);

	void RemoveSelectedBuilding(ADBuilding* BuildingToRemove);

	void ClearSelectedBuildings();
};
