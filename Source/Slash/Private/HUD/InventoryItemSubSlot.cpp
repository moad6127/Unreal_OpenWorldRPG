// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/InventoryItemSubSlot.h"
#include "Components/Button.h"
#include "Items/Item.h"


void UInventoryItemSubSlot::NativeConstruct()
{
	Super::NativeConstruct();
}

void UInventoryItemSubSlot::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseLeave(InMouseEvent);
	RemoveFromParent();
}


void UInventoryItemSubSlot::UseButtonClick()
{

}



