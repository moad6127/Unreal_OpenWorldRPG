// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/InventoryPanel.h"
#include "Character/SlashCharacter.h"
#include "Component/InventoryComponent.h"
#include "HUD/InventoryItemSlot.h"
#include "Components/TextBlock.h"
#include "Components/WrapBox.h"
#include "HUD/ItemDragDropOperation.h"

void UInventoryPanel::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	PlayerCharacter = Cast<ASlashCharacter>(GetOwningPlayerPawn());
	if (PlayerCharacter)
	{
		InventoryReference = PlayerCharacter->GetInventory();
		if (InventoryReference)
		{
			InventoryReference->OnInventoryUpdated.AddUObject(this, &UInventoryPanel::RefreshInventory);
			SetInfoText();
		}
	}
}

void UInventoryPanel::SetInfoText() const
{
	const FString WeightValue = { FString::SanitizeFloat(InventoryReference->GetInventoryTotalWeight()) + "/" +
	FString::SanitizeFloat(InventoryReference->GetWeightCapacity()) };

	const FString CapacityValue = { FString::FromInt(InventoryReference->GetInventoryContents().Num()) + "/" +
	FString::FromInt(InventoryReference->GetSlotCapacity()) };

	WeigthInfo->SetText(FText::FromString(WeightValue));
	CapacityInfo->SetText(FText::FromString(CapacityValue));
}


void UInventoryPanel::RefreshInventory()
{
	if (InventoryReference && InventorySlotClass)
	{
		InventoryPanel->ClearChildren();
		for (AItem* const& InventoryItem : InventoryReference->GetInventoryContents())
		{
			UInventoryItemSlot* ItemSlot = CreateWidget<UInventoryItemSlot>(this, InventorySlotClass);
			ItemSlot->SetItemReference(InventoryItem);

			InventoryPanel->AddChildToWrapBox(ItemSlot);
		}

		SetInfoText();
	}
}

bool UInventoryPanel::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	const UItemDragDropOperation* ItemDragDrop = Cast<UItemDragDropOperation>(InOperation);
	if (ItemDragDrop->SourceItem && InventoryReference)
	{
		//returning true will stop the drop operation at this widet
		return true;
	}
	//returning false will cause the drop operation to fall through the underlying widget
	return false;
}
