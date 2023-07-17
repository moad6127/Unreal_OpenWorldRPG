// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryItemSubSlot.generated.h"


class UButton;
class AItem;
class ASlashCharacter;
UCLASS()
class SLASH_API UInventoryItemSubSlot : public UUserWidget
{
	GENERATED_BODY()


public:

	UPROPERTY(VisibleAnywhere, Category = "Inventory Slot")
	AItem* ItemReference;

	UPROPERTY(VisibleAnywhere, Category = "Inventory Slot")
	ASlashCharacter* OwningCharacter;

	UPROPERTY(meta = (BindWidget))
	UButton* UseButton;

	UPROPERTY(meta = (BindWidget))
	UButton* DropButton;

	UFUNCTION()
	void UseButtonClick();

	UFUNCTION()
	void DropButtonClick();

protected:
	virtual void NativeConstruct() override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;

};
