// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/SlashOverlay.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void USlashOverlay::SetHealthBarPercent(float Percent)
{
	if (HealthProgressBar)
	{
		HealthProgressBar->SetPercent(Percent);
	}
}

void USlashOverlay::SetStaminaBarPercent(float Percent)
{
	if (StaminaProgressBar)
	{
		StaminaProgressBar->SetPercent(Percent);
	}
}

void USlashOverlay::SetGold(int32 Gold)
{
	if (GoldCount)
	{
		const FText GoldText = FText::FromString(FString::Printf(TEXT("%d"), Gold));
		GoldCount->SetText(GoldText);
	}
}

void USlashOverlay::SetSoul(int32 Soul)
{
	if (SoulCount)
	{
		const FText SoulText = FText::FromString(FString::Printf(TEXT("%d"), Soul));
		SoulCount->SetText(SoulText);
	}
}
