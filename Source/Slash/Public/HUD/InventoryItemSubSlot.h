// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryItemSubSlot.generated.h"


class UButton;
UCLASS()
class SLASH_API UInventoryItemSubSlot : public UUserWidget
{
	GENERATED_BODY()


public:
	UButton* UseButton;


	void ButtonClick();
};
