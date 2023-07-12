// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/DragDropOperation.h"
#include "ItemDragDropOperation.generated.h"

/**
 * 
 */
class AItem;
class UInventoryComponent;

UCLASS()
class SLASH_API UItemDragDropOperation : public UDragDropOperation
{
	GENERATED_BODY()

public:

	UPROPERTY()
	AItem* SourceItem;

	UPROPERTY()
	UInventoryComponent* SourceInventory;
};
