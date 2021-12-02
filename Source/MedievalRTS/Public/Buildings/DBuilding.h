// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/DSelectable.h"

#include "DBuilding.generated.h"

UCLASS()
class MEDIEVALRTS_API ADBuilding : public AActor, public IDSelectable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADBuilding();

protected:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMeshComp;
	
	UPROPERTY(VisibleAnywhere)
	UDecalComponent* SelectionDecal;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//virtual void Selected() override;
	void Selected_Implementation() override;

	void Deselected_Implementation() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
