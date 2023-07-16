// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryItemSubSlot.generated.h"


class UButton;
class AItem;
UCLASS()
class SLASH_API UInventoryItemSubSlot : public UUserWidget
{
	GENERATED_BODY()


public:

	UPROPERTY(VisibleAnywhere, Category = "Inventory Slot")
	AItem* ItemReference;

	UPROPERTY(meta = (BindWidget))
	UButton* UseButton;

	UFUNCTION()
	void UseButtonClick();

protected:
	virtual void NativeConstruct() override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;

};
