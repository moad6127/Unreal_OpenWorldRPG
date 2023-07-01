// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class AItem;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SLASH_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInventoryComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;
	void AddNewItem(AItem* Item, const int32 AmountToAdd);

	float InventoryTotalWeight;
	int32 InventorySlotsCapacity;
	float InventoryWeightCapacity;

	TArray<TObjectPtr<AItem>> InventoryContents;

public:
	FORCEINLINE float GetInventoryTotalWeight() const { return InventoryTotalWeight; }
	FORCEINLINE float GetWeightCapacity() const { return InventoryWeightCapacity; }
	FORCEINLINE int32 GetSlotCapacity() const { return InventorySlotsCapacity; }
	FORCEINLINE TArray<AItem*> GetInventoryContents() const { return InventoryContents; }

	FORCEINLINE void SetSlotCapacity(const int32 NewSlotCapacity) { InventorySlotsCapacity = NewSlotCapacity; };
	FORCEINLINE void SetWeightCapacity(const float NewWeightCapacity) { InventoryWeightCapacity = NewWeightCapacity; };
};
