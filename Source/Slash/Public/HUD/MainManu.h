// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainManu.generated.h"

class ASlashCharacter;

UCLASS()
class SLASH_API UMainManu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	ASlashCharacter* PlayerCharacter;
protected:

	virtual void NativeOnInitialized() override;
	virtual void NativeConstruct() override;
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;

};
