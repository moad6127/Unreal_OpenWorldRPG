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


	AItem* FindMatchingItem(AItem* ItemIn) const;
	AItem* FindNextItemByID(AItem* ItemIn) const;
	AItem* FindNextPartialStack(AItem* ItemIn)const;
	void RemoveSingleInstanceOfItem(AItem ItemIn);
	int32 RemoveAmountOfItem(AItem* ItemIn, int32 DesiredAmountToRemove);
	void SplitExistingStack(AItem* ItemIn, const int32 AmountToSprit);

protected:
	virtual void BeginPlay() override;

	float InventoryTotalWeight;

	TArray<TObjectPtr<AItem>> InventoryContents;

public:
	//FORCEINLINE float GetInventoryTotalWeight() const {};
	//FORCEINLINE float GetWeightCapacity() const {};
	//FORCEINLINE int32 GetSlotCapacity() const {};
	//FORCEINLINE TArray<AItem*> GetInventoryContents() const {};

	//FORCEINLINE void SetSlotCapacity(const int32 NewSloCapacity) {};
	//FORCEINLINE void SetWeightCapacity(const float NewWeightCapacity) {};
};
