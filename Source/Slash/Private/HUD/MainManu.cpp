// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/MainManu.h"
#include "Character/SlashCharacter.h"
#include "HUD/ItemDragDropOperation.h"
#include "Items/Item.h"
void UMainManu::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UMainManu::NativeConstruct()
{
	Super::NativeConstruct();

	PlayerCharacter = Cast<ASlashCharacter>(GetOwningPlayerPawn());
}

bool UMainManu::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{

	const UItemDragDropOperation* ItemDragDrop = Cast<UItemDragDropOperation>(InOperation);
	if (PlayerCharacter && ItemDragDrop->SourceItem)
	{
		PlayerCharacter->DropItem(ItemDragDrop->SourceItem, ItemDragDrop->SourceItem->Quantity);
		return true;
	}
	return false;
}
