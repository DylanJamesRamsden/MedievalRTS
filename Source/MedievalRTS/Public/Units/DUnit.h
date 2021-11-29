// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Interfaces/DSelectable.h"
#include "GameFramework/Character.h"
#include "DUnit.generated.h"

UCLASS()
class MEDIEVALRTS_API ADUnit : public ACharacter, public IDSelectable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADUnit();

protected:

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

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};
