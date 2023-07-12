// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/InventoryItemSlot.h"
#include "HUD/InventoryTooltip.h"
#include "HUD/DragItemVisual.h"
#include "HUD/ItemDragDropOperation.h"
#include "Items/Item.h"
#include "Components/Border.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UInventoryItemSlot::NativeOnInitialized()
{
    Super::NativeOnInitialized();
    if (ToolTipClass)
    {
        UInventoryTooltip* ToolTip = CreateWidget<UInventoryTooltip>(this, ToolTipClass);
        ToolTip->InventorySlotBeingHovered = this;
        SetToolTip(ToolTip);
    }
}

void UInventoryItemSlot::NativeConstruct()
{
    Super::NativeConstruct();

    if (ItemReference)
    {
        switch (ItemReference->ItemQuality)
        {
        case EItemQuality::EIQ_Shoddy:
            ItemBorder->SetBrushColor(FLinearColor::Gray);
            break;
        case EItemQuality::EIQ_Common:
            ItemBorder->SetBrushColor(FLinearColor::White);
            break;
        case EItemQuality::EIQ_Quality:
            ItemBorder->SetBrushColor(FLinearColor::Green);
            break;
        case EItemQuality::EIQ_Masterwork:
            ItemBorder->SetBrushColor(FLinearColor::Blue);
            break;
        case EItemQuality::EIQ_Grandmaster:
            ItemBorder->SetBrushColor(FLinearColor(1.f,0.45f,0.f));
            break;
        default:
            break;
        }
        ItemIcon->SetBrushFromTexture(ItemReference->AssetData.Icon);

        if (ItemReference->NumericData.bIsStackable)
        {
            ItemQuantity->SetText(FText::AsNumber(ItemReference->Quantity));
        }
        else
        {
            ItemQuantity->SetVisibility(ESlateVisibility::Collapsed);
        }
    }
}

FReply UInventoryItemSlot::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    FReply Reply = Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);

    if (InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
    {
        return Reply.Handled().DetectDrag(TakeWidget(), EKeys::LeftMouseButton);
    }

    // �������� Ŭ���Ұ�� ����޴� �����

    return Reply.Unhandled();
}

void UInventoryItemSlot::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
    Super::NativeOnMouseLeave(InMouseEvent);
}

void UInventoryItemSlot::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation)
{
    Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);

    if (DragItemVisualClass)
    {
        UDragItemVisual* DragVisual = CreateWidget<UDragItemVisual>(this, DragItemVisualClass);
        DragVisual->ItemIcon->SetBrushFromTexture(ItemReference->AssetData.Icon);
        DragVisual->ItemBorder->SetBrushColor(ItemBorder->GetBrushColor());
        DragVisual->ItemQuantity->SetText(FText::AsNumber(ItemReference->Quantity));

        UItemDragDropOperation* DragItemOperation = NewObject<UItemDragDropOperation>();
        DragItemOperation->SourceItem = ItemReference;
        DragItemOperation->SourceInventory = ItemReference->OwningInventory;

        DragItemOperation->DefaultDragVisual = DragVisual;
        DragItemOperation->Pivot = EDragPivot::TopLeft;

        OutOperation = DragItemOperation;
    }
}

bool UInventoryItemSlot::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
    return Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);
    
}
