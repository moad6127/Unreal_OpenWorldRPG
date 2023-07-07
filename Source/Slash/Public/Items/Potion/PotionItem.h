// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "PotionItem.generated.h"

/**
 * 
 */

class UDataTable;

UCLASS()
class SLASH_API APotionItem : public AItem
{
	GENERATED_BODY()

public:
	APotionItem();
	/**
	* PickupItemValue
	*/
	UPROPERTY(EditInstanceOnly, Category = "Item DataBase")
	UDataTable* ItemDataTable;

	UPROPERTY(EditInstanceOnly, Category = "Item DataBase")
	FName DesiredItemID;

	UPROPERTY(VisibleAnywhere, Category = "Item DataBase")
	AItem* ItemReference;

	UPROPERTY(EditInstanceOnly, Category = "Item DataBase")
	int32 ItemQuantity;

	UPROPERTY(VisibleInstanceOnly, Category = "Item DataBase")
	FInteractableData InstanceIteractableData;

	void InitializePickup(const TSubclassOf<AItem> BaseClass, const int32 InQuantity);

	void InitializeDrop(AItem* ItemToDrop, const int32 InQuantity);

	virtual void BeginFocus() override;
	virtual void EndFocus() override;
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = Potion)
	float HealAmount;


	virtual void Interact(class ASlashCharacter* PlayerCharacter) override;
	void UpdateInteractableData();

	void TakePickup(const ASlashCharacter* Taker);

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif 
public:

	FORCEINLINE float GetHealAmount() const { return HealAmount; }

	FORCEINLINE AItem* GetItemData() { return ItemReference; }
};
