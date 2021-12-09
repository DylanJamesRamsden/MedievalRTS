// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DGameTimerWidget.h"

#include "Kismet/GameplayStatics.h"

FString UDGameTimerWidget::GetGameTimeAsString() const
{
	const int GameTime = (int)(UGameplayStatics::GetTimeSeconds(GetWorld()));

	const int32 GameTimeSeconds = GameTime % 60;

	const int32 GameTimeMinutes = GameTime / 60;;

	return (GameTimeMinutes < 10 ? "0" + FString::FromInt(GameTimeMinutes) : FString::FromInt(GameTimeMinutes)) + ":" +
		(GameTimeSeconds < 10 ? "0" + FString::FromInt(GameTimeSeconds) : FString::FromInt(GameTimeSeconds));
}
