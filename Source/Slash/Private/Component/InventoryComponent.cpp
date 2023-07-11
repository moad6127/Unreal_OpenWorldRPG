// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/InventoryComponent.h"
#include "Items/Item.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}



AItem* UInventoryComponent::FindMatchingItem(AItem* ItemIn) const
{
	if (ItemIn)
	{
		if (InventoryContents.Contains(ItemIn))
		{
			return ItemIn;
		}
	}
	return nullptr;
}

AItem* UInventoryComponent::FindNextItemByID(AItem* ItemIn) const
{
	if (ItemIn)
	{
		if (const TArray<AItem*>::ElementType* Result = InventoryContents.FindByKey(ItemIn))
		{
			return *Result;
		}
	}
	return nullptr;
}

AItem* UInventoryComponent::FindNextPartialStack(AItem* ItemIn) const
{
	if(const TArray<AItem*>::ElementType * Result =
		InventoryContents.FindByPredicate([&ItemIn](const AItem* InventoryItem)
			{
				return InventoryItem->ID == ItemIn->ID && !InventoryItem->IsFullItemStack();
			}))
	{
		return *Result;
	}
	return nullptr;
}


int32 UInventoryComponent::CalculateWeightAddAmount(AItem* ItemIn, int32 RequestedAddAmount)
{
	const int32 WeightMaxAddAmount = FMath::FloorToInt((GetWeightCapacity() - InventoryTotalWeight) / ItemIn->GetItemSingleWeight());
	
	if (WeightMaxAddAmount >= RequestedAddAmount)
	{
		return RequestedAddAmount;
	}
	return WeightMaxAddAmount;
}

int32 UInventoryComponent::CalculateNumberForFullStack(AItem* StackableItem, int32 InitialrequestedAddAmount)
{
	const int32 AddAmountToMakeFullStack = StackableItem->NumericData.MaxStackSize - StackableItem->Quantity;

	return FMath::Min(InitialrequestedAddAmount, AddAmountToMakeFullStack);
}

void UInventoryComponent::RemoveSingleInstanceOfItem(AItem* ItemToRemove)
{
	InventoryContents.RemoveSingle(ItemToRemove);
	OnInventoryUpdated.Broadcast();
}

int32 UInventoryComponent::RemoveAmountOfItem(AItem* ItemIn, int32 DesiredAmountToRemove)
{
	const int32 ActualAmountToRemove = FMath::Min(DesiredAmountToRemove, ItemIn->Quantity);

	ItemIn->SetQuantity(ItemIn->Quantity - ActualAmountToRemove);

	InventoryTotalWeight -= ActualAmountToRemove * ItemIn->GetItemSingleWeight();
	OnInventoryUpdated.Broadcast();

	return ActualAmountToRemove;
}

void UInventoryComponent::SplitExistingStack(AItem* ItemIn, const int32 AmountToSplit)
{
	if (!(InventoryContents.Num() + 1 > InventorySlotCapacity))
	{
		RemoveAmountOfItem(ItemIn, AmountToSplit);
		AddNewItem(ItemIn, AmountToSplit);
	}
}

FItemAddResult UInventoryComponent::HandleNonStackableItems(AItem* ItemIn)
{
	if (FMath::IsNearlyZero(ItemIn->GetItemSingleWeight()) || ItemIn->GetItemStackWeight() < 0)
	{
		return FItemAddResult::AddedNone(FText::Format(
			FText::FromString("Could not add {0} to the inventory. Item has invalid weight value"), ItemIn->TextData.Name));
	}

	if (InventoryTotalWeight + ItemIn->GetItemSingleWeight() > GetWeightCapacity())
	{
		return FItemAddResult::AddedNone(FText::Format(
			FText::FromString("Could not add {0} to the inventory. Item would overflow weight limit"), ItemIn->TextData.Name));

	}

	if (InventoryContents.Num() + 1 > InventorySlotCapacity)
	{
		return FItemAddResult::AddedNone(FText::Format(
			FText::FromString("Could not add {0} to the inventory. All Inventory slots are full"), ItemIn->TextData.Name));

	}

	AddNewItem(ItemIn, 1);
	
	return FItemAddResult::AddedAll(1, FText::Format(
		FText::FromString("Successfully added {0} to the Inventory."), ItemIn->TextData.Name));

}

int32 UInventoryComponent::HandleStackableItems(AItem* ItemIn, int32 RequestedAddAmount)
{
	return int32();
}

FItemAddResult UInventoryComponent::HandleAddItem(AItem* InputItem)
{
	if (GetOwner())
	{
		const int32 InitialRequestedAddAmount = InputItem->Quantity;

		//non statck
		if (!InputItem->NumericData.bIsStackable)
		{
			return HandleNonStackableItems(InputItem);
		}

		//stackable
		const int32 StackableAmountAdded = HandleStackableItems(InputItem, InitialRequestedAddAmount);

		if (StackableAmountAdded == InitialRequestedAddAmount)
		{
			return FItemAddResult::AddedAll(InitialRequestedAddAmount, FText::Format(
				FText::FromString("Successfully added {0} {1} to the Inventory."),
				InitialRequestedAddAmount,
				InputItem->TextData.Name));

		}
		
		if (StackableAmountAdded < InitialRequestedAddAmount && StackableAmountAdded > 0)
		{
			return FItemAddResult::AddedPartial(StackableAmountAdded, FText::Format(
				FText::FromString("Partial amount of {0} added to the inventory, Numer added = {1}"),
				InputItem->TextData.Name,
				StackableAmountAdded));
		}

		if (StackableAmountAdded <= 0)
		{
			return FItemAddResult::AddedNone(FText::Format(
				FText::FromString("Couldn't add {0} to the inventory. No remaining inventory slots, or invaild ietm."),
				InputItem->TextData.Name));
		}
	}

	check(false);
	return FItemAddResult::AddedNone(FText::FromString("TryAddItem fallthrough error. GetOwner() check somehow failed."));
}

void UInventoryComponent::AddNewItem(AItem* Item, const int32 AmountToAdd)
{
	AItem* NewItem;

	if (Item->bIsCopy || Item->bIsPickup)
	{
		NewItem = Item;
		NewItem->ResetItemFlags();
	}
	else
	{
		NewItem = Item->CreateItemCopy();
	}

	NewItem->OwningInventory = this;
	NewItem->SetQuantity(AmountToAdd);

	InventoryContents.Add(NewItem);
	InventoryTotalWeight += NewItem->GetItemStackWeight();
	OnInventoryUpdated.Broadcast();

}





