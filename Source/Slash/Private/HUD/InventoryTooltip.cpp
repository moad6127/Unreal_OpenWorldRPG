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

	const FString DamageValueString = { "Damage : " + FString::SanitizeFloat(0.f)};
	DamageValue->SetText(FText::FromString(DamageValueString));

	const FString ArmorValueString = { "Armor : " + FString::SanitizeFloat(0.f) };
	ArmorRating->SetText(FText::FromString(ArmorValueString));

	UsageText->SetText(ItemBeingHovered->TextData.UsageText);
	ItemDescription->SetText(ItemBeingHovered->TextData.Description);

	const FString WeightString = {"Weight :  " + FString::SanitizeFloat(ItemBeingHovered->GetItemStackWeight())};
	StackWeightValue->SetText(FText::FromString(WeightString));

	if (ItemBeingHovered->NumericData.bIsStackable)
	{
		const FString MaxStackSizeString = { "Max Stack Size : " + FString::FromInt(ItemBeingHovered->NumericData.MaxStackSize)};
		MaxStackSize->SetText(FText::FromString(MaxStackSizeString));
	}
	else
	{
		MaxStackSize->SetVisibility(ESlateVisibility::Collapsed);
	}

}
