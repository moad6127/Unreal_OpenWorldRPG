// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnInventoryUpdated);

class AItem;

UENUM(BlueprintType)
enum class EItemAddResult : uint8
{
	EIAR_NoItemAdded UMETA(DisplayName = "NoItemAdded"),
	EIAR_PartialAmountItemAdded UMETA(DisplayName = "PartialAmountItemAdded"),
	EIAR_AllItemAdded UMETA(DisplayName = "AllItemAdded")
};

USTRUCT(BlueprintType)
struct FItemAddResult
{
	GENERATED_BODY()

	FItemAddResult() :
		ActualAmountAdded(0),
		OperationResult(EItemAddResult::EIAR_NoItemAdded),
		ResultMessage(FText::GetEmpty())
	{};

	UPROPERTY(BlueprintReadOnly, Category = "Item Add Result")
	int32 ActualAmountAdded;

	UPROPERTY(BlueprintReadOnly, Category = "Item Add Result")
	EItemAddResult OperationResult;
	
	UPROPERTY(BlueprintReadOnly, Category = "Item Add Result")
	FText ResultMessage;

	static FItemAddResult AddedNone(const FText& ErrorText)
	{
		FItemAddResult AddedNoneResult;
		AddedNoneResult.ActualAmountAdded = 0;
		AddedNoneResult.OperationResult = EItemAddResult::EIAR_NoItemAdded;
		AddedNoneResult.ResultMessage = ErrorText;
		return AddedNoneResult;
	};

	static FItemAddResult AddedPartial(const int32 PartialAmountAdded, const FText& ErrorText)
	{
		FItemAddResult AddedPartialResult;
		AddedPartialResult.ActualAmountAdded = PartialAmountAdded;
		AddedPartialResult.OperationResult = EItemAddResult::EIAR_PartialAmountItemAdded;
		AddedPartialResult.ResultMessage = ErrorText;
		return AddedPartialResult;
	};
	static FItemAddResult AddedAll(const int32 AmountAdded, const FText& Message)
	{
		FItemAddResult AddedAllResult;
		AddedAllResult.ActualAmountAdded = AmountAdded;
		AddedAllResult.OperationResult = EItemAddResult::EIAR_AllItemAdded;
		AddedAllResult.ResultMessage = Message;
		return AddedAllResult;
	};
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SLASH_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInventoryComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(Category = "Inventory")
	AItem* FindMatchingItem(AItem* ItemIn) const;
	UFUNCTION(Category = "Inventory")
	AItem* FindNextItemByID(AItem* ItemIn) const;
	UFUNCTION(Category = "Inventory")
	AItem* FindNextPartialStack(AItem* ItemIn) const;

	UFUNCTION(Category = "Inventory")
	FItemAddResult HandleAddItem(AItem* InputItem);

	UFUNCTION(Category = "Inventory")
	void RemoveSingleInstanceOfItem(AItem* ItemToRemove);
	UFUNCTION(Category = "Inventory")
	int32 RemoveAmountOfItem(AItem* ItemIn, int32 DesiredAmountToRemove);
	UFUNCTION(Category = "Inventory")
	void SplitExistingStack(AItem* ItemIn, const int32 AmountToSplit);


	FOnInventoryUpdated OnInventoryUpdated;
protected:
	virtual void BeginPlay() override;

	UFUNCTION(Category = "Inventory")
	FItemAddResult HandleNonStackableItems(AItem* ItemIn);
	UFUNCTION(Category = "Inventory")
	int32 HandleStackableItems(AItem* ItemIn, int32 RequestedAddAmount);
	UFUNCTION(Category = "Inventory")
	int32 CalculateWeightAddAmount(AItem* ItemIn, int32 RequestedAddAmount);
	UFUNCTION(Category = "Inventory")
	int32 CalculateNumberForFullStack(AItem* StackableItem, int32 InitialrequestedAddAmount);

	UFUNCTION(Category = "Inventory")
	void AddNewItem(AItem* Item, const int32 AmountToAdd);

	UPROPERTY(EditAnywhere, Category = "Inventory")
	float InventoryTotalWeight;
	UPROPERTY(EditAnywhere, Category = "Inventory")
	int32 InventorySlotCapacity;
	UPROPERTY(EditAnywhere, Category = "Inventory")
	float InventoryWeightCapacity;

	UPROPERTY(VisibleAnywhere, Category = "Inventory")
	TArray<AItem*> InventoryContents;

public:
	//getter
	UFUNCTION(Category = "Inventory")
	FORCEINLINE float GetInventoryTotalWeight() const { return InventoryTotalWeight; }
	UFUNCTION(Category = "Inventory")
	FORCEINLINE float GetWeightCapacity() const { return InventoryWeightCapacity; }
	UFUNCTION(Category = "Inventory")
	FORCEINLINE int32 GetSlotCapacity() const { return InventorySlotCapacity; }
	UFUNCTION(Category = "Inventory")
	FORCEINLINE TArray<AItem*> GetInventoryContents() const { return InventoryContents; }

	//setter
	UFUNCTION(Category = "Inventory")
	FORCEINLINE void SetSlotCapacity(const int32 NewSlotCapacity) { InventorySlotCapacity = NewSlotCapacity; }
	UFUNCTION(Category = "Inventory")
	FORCEINLINE void SetWeightCapacity(const float NewWeightCapacity) { InventoryWeightCapacity = NewWeightCapacity; }
};
