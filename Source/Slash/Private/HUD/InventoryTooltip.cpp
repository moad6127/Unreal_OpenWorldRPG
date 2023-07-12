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
		ItemType->SetText(FText::FromString("Weapon"));
		ArmorRating->SetVisibility(ESlateVisibility::Collapsed);
		break;

	case EItemType::EIT_Pickups:
		ItemType->SetText(FText::FromString("Consumable"));
		DamageValue->SetVisibility(ESlateVisibility::Collapsed);
		ArmorRating->SetVisibility(ESlateVisibility::Collapsed);
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

	const FString WeightString = {"Weight :  " + FString::SanitizeFloat(ItemBeingHovered->GetItemStackWeight())};
	StackWeightValue->SetText(FText::FromString(WeightString));

	if (ItemBeingHovered->NumericData.bIsStackable)
	{
		MaxStackSize->SetText(FText::AsNumber(ItemBeingHovered->NumericData.MaxStackSize));
		StackSize->SetText(FText::AsNumber(ItemBeingHovered->Quantity));
	}
	else
	{
		MaxStackSize->SetVisibility(ESlateVisibility::Collapsed);
		StackSize->SetVisibility(ESlateVisibility::Collapsed);
	}

}
