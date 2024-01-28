// Created By Hollow Game Studios

#pragma once

#include "CoreMinimal.h"
#include "DialogueRenderer.h"
#include "DialogueTriggerComponent.h"
#include "Subsystems/WorldSubsystem.h"
#include "DialogueManagerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class OFFICEESCAPE_01_API UDialogueManagerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

	UDialogueManagerSubsystem();
	UDialogueRenderer* GetRender();

private:
	FDialogueNode* CurrentNode{nullptr};
	TArray<FDialogueNode> DialogueNodes;
	int32 CurrentNodeIndex;
protected:
	
	FTimerHandle DelayTimerHandle;
public:
	
	UPROPERTY(EditAnywhere);
	TObjectPtr<UDialogueRenderer> Renderer;
	UFUNCTION(BlueprintCallable, Category="Dialogue")
	void StartDialogue(TArray<FDialogueNode>& Nodes);
	// UFUNCTION(BlueprintCallable, Category="Dialogue")
	// FDialogueNode HandleChoice(TArray<FDialogueChoice> Choices);
	UFUNCTION(BlueprintCallable, Category="Dialogue")
	void ShowDialogue(const FString& Speaker, const FString& Message);
	void ShowNextDialogueLine();
	void OnDialogueFinished();
};
