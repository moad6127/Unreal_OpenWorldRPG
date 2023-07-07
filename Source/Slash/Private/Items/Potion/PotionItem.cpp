// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Potion/PotionItem.h"
#include "Interfaces/PickupInterface.h"

APotionItem::APotionItem()
{
	PrimaryActorTick.bCanEverTick = false;
}

void APotionItem::BeginPlay()
{
	Super::BeginPlay();
	InitializePickup(AItem::StaticClass(), ItemQuantity);
}

void APotionItem::InitializePickup(const TSubclassOf<AItem> BaseClass, const int32 InQuantity)
{
	if (ItemDataTable && !DesiredItemID.IsNone())
	{
		const FItemData* ItemData = ItemDataTable->FindRow<FItemData>(DesiredItemID, DesiredItemID.ToString());

		ItemReference = NewObject<AItem>(this, BaseClass);

		ItemReference->ID = ItemData->ID;
		ItemReference->ItemType = ItemData->ItemType;
		ItemReference->ItemQuality = ItemData->ItemQuality;
		ItemReference->NumericData = ItemData->NumericData;
		ItemReference->TextData = ItemData->TextData;
		ItemReference->AssetData = ItemData->AssetData;

		InQuantity <= 0 ? ItemReference->SetQuantity(1) : ItemReference->SetQuantity(InQuantity);

		ItemMesh->SetStaticMesh(ItemData->AssetData.Mesh);

		UpdateInteractableData();
		
	}
}

void APotionItem::InitializeDrop(AItem* ItemToDrop, const int32 InQuantity)
{
	ItemReference = ItemToDrop;

	InQuantity <= 0 ? ItemReference->SetQuantity(1) : ItemReference->SetQuantity(InQuantity);

	ItemReference->NumericData.Weight = ItemToDrop->GetItemSingleWeight();
	ItemMesh->SetStaticMesh(ItemToDrop->AssetData.Mesh);

	UpdateInteractableData();
}

void APotionItem::BeginFocus()
{
	if (ItemMesh)
	{
		ItemMesh->SetRenderCustomDepth(true);
	}
}

void APotionItem::EndFocus()
{
	if (ItemMesh)
	{
		ItemMesh->SetRenderCustomDepth(false);
	}
}

void APotionItem::Interact(ASlashCharacter* PlayerCharacter)
{
	if (PlayerCharacter)
	{
		TakePickup(PlayerCharacter);
	}
}

void APotionItem::UpdateInteractableData()
{
	InstanceIteractableData.InteractableType = EInteractableType::EIT_Pickup;
	InstanceIteractableData.Action = ItemReference->TextData.InteractionText;
	InstanceIteractableData.Name = ItemReference->TextData.Name;
	InstanceIteractableData.Quantity = ItemReference->Quantity;
	InteractableData = InstanceIteractableData;
}

void APotionItem::TakePickup(const ASlashCharacter* Taker)
{
	if (!IsPendingKillPending())
	{
		if (ItemReference)
		{
			//if(UInventoryComponent* PlyerInventory = Taker->GetInventory())

			
		}
	}
}

void APotionItem::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	const FName ChangePropertyName = PropertyChangedEvent.Property ? FName(PropertyChangedEvent.Property->GetName()) : NAME_None;

	if (ChangePropertyName == GET_MEMBER_NAME_CHECKED(APotionItem, DesiredItemID))
	{
		if (ItemDataTable)
		{
			if (const FItemData* ItemData = ItemDataTable->FindRow<FItemData>(DesiredItemID, DesiredItemID.ToString()))
			{
				ItemMesh->SetStaticMesh(ItemData->AssetData.Mesh);
			}
		}
	}

}
