// Created By Hollow Game Studios


#include "DialogueSystem/Widgets/TOTH_HUD.h"


#include "CanvasItem.h"
#include "Engine/Canvas.h"

void ATOTH_HUD::DrawHUD()
{
	Super::DrawHUD();
}

void ATOTH_HUD::DisplayDialogue(const FString& Speaker, const FString& Message)
{
	// Get the canvas
	if (Canvas)
	{
		// Set the font properties
		UFont* Font = GEngine->GetLargeFont();
		FCanvasTextItem TextItem(FVector2D(50, 50), FText::FromString(FString::Printf(TEXT("%s: %s"),
			*Speaker, *Message)), Font, FLinearColor::Black);

		// Draw the text on the canvas
		Canvas->DrawItem(TextItem);
	}
}
