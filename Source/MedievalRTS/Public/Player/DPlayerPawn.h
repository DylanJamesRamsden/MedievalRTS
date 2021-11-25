// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "DPlayerPawn.generated.h"

class USpringArmComponent;
class UCameraComponent;
/**
 * 
 */
UCLASS()
class MEDIEVALRTS_API ADPlayerPawn : public ADefaultPawn
{
	GENERATED_BODY()

	public:

	ADPlayerPawn();

	protected:

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(EditAnywhere, Category = "Camera|Zoom")
	float ZoomSpeed;

	UPROPERTY(EditAnywhere, Category = "Camera|Zoom")
	float MinZoomDistance;

	UPROPERTY(EditAnywhere, Category = "Camera|Zoom")
	float MaxZoomDistance;

	UPROPERTY()
	float ZoomDirection;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MouseMovement();

	void Zoom(float Value);

	void CameraSmoothZoom(float DeltaTime);

	public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
