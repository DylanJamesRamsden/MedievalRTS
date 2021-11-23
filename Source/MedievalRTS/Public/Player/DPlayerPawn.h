// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Components/DCameraMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "DPlayerPawn.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class MEDIEVALRTS_API ADPlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADPlayerPawn();

protected:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComp;
	
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UDCameraMovementComponent* CameraMovementComp;

	UPROPERTY(EditAnywhere)
	bool bDebugCamera = false;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void DrawCameraPositionDebug() const;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
