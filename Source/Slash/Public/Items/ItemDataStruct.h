#pragma once

#include "Coreminimal.h"
#include "Engine/DataTable.h"
#include "ItemDataStruct.generated.h"



UENUM()
enum class EItemQuality : uint8
{
	EIQ_Shoddy UMETA(DisplayName = Shoddy),
	EIQ_Common UMETA(DisplayName = Common),
	EIQ_Quality UMETA(DisplayName = Quality),
	EIQ_Masterwork UMETA(DisplayName = Masterwork),
	EIQ_Grandmaster UMETA(DisplayName = Grandmaster)
};

UENUM()
enum class EItemType : uint8
{
	EIT_Weapon UMETA(DisplayName = Weapon),
	EIT_Pickups UMETA(DisplayName = Pickups),
	EIT_AutoPickups UMETA(DisplayName = AutoPickups),
};

USTRUCT()
struct FItemStatistics
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	float RestorationAmount;

	UPROPERTY(EditAnywhere)
	float SellValue;
};

USTRUCT()
struct FItemTextData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	FText Name;

	UPROPERTY(EditAnywhere)
	FText Description;

	UPROPERTY(EditAnywhere)
	FText InteractionText;

	UPROPERTY(EditAnywhere)
	FText UsageText;
};

USTRUCT()
struct FItemNumericData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	float Weight;

	UPROPERTY(EditAnywhere)
	int32 MaxStackSize;

	UPROPERTY(EditAnywhere)
	bool bIsStackable;

};

USTRUCT()
struct FItemAssetData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	UTexture2D* Icon;

	UPROPERTY(EditAnywhere)
	UStaticMesh* Mesh;
};

USTRUCT()
struct FItemData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Item Data")
	FName ID;

	UPROPERTY(EditAnywhere, Category = "Item Data")
	EItemType ItemType;

	UPROPERTY(EditAnywhere, Category = "Item Data")
	EItemQuality ItemQuality;

	UPROPERTY(EditAnywhere, Category = "Item Data")
	FItemStatistics ItemStatistics;

	UPROPERTY(EditAnywhere, Category = "Item Data")
	FItemTextData TextData;

	UPROPERTY(EditAnywhere, Category = "Item Data")
	FItemNumericData NumericData;

};


