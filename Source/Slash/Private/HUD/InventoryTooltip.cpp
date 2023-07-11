// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/InventoryTooltip.h"
#include "HUD/InventoryItemSlot.h"
#include "Items/Item.h"
#include "Components/TextBlock.h"

void UInventoryTooltip::NativeConstruct()
{
	Super::NativeConstruct();

	AItem* ItemBeingHovered = InventorySlotBeingHovered->GetItemReference();
	switch (ItemBeingHovered->ItemType)
	{
	case EItemType::EIT_Weapon:
		break;
	case EItemType::EIT_Pickups:
		ItemType->SetText(FText::FromString("Consumable"));
		DamageValue->SetVisibility(ESlateVisibility::Collapsed);
		ArmorRating->SetVisibility(ESlateVisibility::Collapsed);
		SellValue->SetVisibility(ESlateVisibility::Collapsed);
		break;
	case EItemType::EIT_AutoPickups:
		break;
	default:
		break;
	}
	ItemName->SetText(ItemBeingHovered->TextData.Name);
	DamageValue->SetText(FText::AsNumber(0));
	ArmorRating->SetText(FText::AsNumber(0));
	UsageText->SetText(ItemBeingHovered->TextData.UsageText);
	ItemDescription->SetText(ItemBeingHovered->TextData.Description);
	SellValue->SetText(FText::AsNumber(ItemBeingHovered->ItemStatistics.SellValue));
	StackWeightValue->SetText(FText::AsNumber(ItemBeingHovered->GetItemStackWeight()));
	if (ItemBeingHovered->NumericData.bIsStackable)
	{
		StackSizeText->SetText(FText::AsNumber(ItemBeingHovered->NumericData.MaxStackSize));
	}
	else
	{
		StackSizeText->SetVisibility(ESlateVisibility::Collapsed);
	}

}
