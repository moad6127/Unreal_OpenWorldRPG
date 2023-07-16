// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/InventoryItemSubSlot.h"
#include "Components/Button.h"
#include "Items/Item.h"
#include "Items/Potion/PotionItem.h"
#include "Character/SlashCharacter.h"


void UInventoryItemSubSlot::NativeConstruct()
{
	Super::NativeConstruct();

	OwningCharacter = Cast<ASlashCharacter>(GetOwningPlayerPawn());

	UseButton->OnClicked.AddDynamic(this, &UInventoryItemSubSlot::UseButtonClick);
}

void UInventoryItemSubSlot::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseLeave(InMouseEvent);
	RemoveFromParent();
}


void UInventoryItemSubSlot::UseButtonClick()
{
	if (ItemReference && OwningCharacter)
	{
		APotionItem* Potion = NewObject<APotionItem>(ItemReference->StaticClass());
		if (Potion)
		{
			Potion->Use(OwningCharacter);
		}
		ItemReference->Use(OwningCharacter);
		
	}
}



