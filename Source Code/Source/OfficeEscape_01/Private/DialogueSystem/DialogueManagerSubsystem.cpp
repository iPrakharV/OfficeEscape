// Created By Hollow Game Studios


#include "DialogueSystem/DialogueManagerSubsystem.h"

#include "TimerManager.h" // Include TimerManager.h for FTimerHandle

#include "OfficeGameInstance.h"

UDialogueManagerSubsystem::UDialogueManagerSubsystem(): CurrentNodeIndex(0)
{
	UE_LOG(LogTemp, Warning, TEXT("DialogManagerSubsystem started"));
}


UDialogueRenderer* UDialogueManagerSubsystem::GetRender()
{
	UE_LOG(LogTemp, Log, TEXT("Finding Dialogue Renderer..."))
	UWorld* World = GetWorld();
	if (World)
	{
		UE_LOG(LogTemp, Log, TEXT("Found World..."))

		UDialogueRenderer* DialogueRenderer = World->GetSubsystem<UDialogueRenderer>();
		if (DialogueRenderer)
		{
			UE_LOG(LogTemp, Log, TEXT("Renderer found!"))

			// Now you have a reference to your subsystem, and you can access its functions and properties
			// ...
			return DialogueRenderer;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to get subsystem instance"));
			return nullptr;
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get world"));
		return nullptr;
	}
}

void UDialogueManagerSubsystem::StartDialogue(TArray<FDialogueNode>& Nodes)
{
	UE_LOG(LogTemp, Warning, TEXT("Initiating and Saving Dialogue Nodes"));
	DialogueNodes = Nodes;
	CurrentNodeIndex = 0;

	// Start displaying dialogue lines
	ShowNextDialogueLine();
}

// FDialogueNode UDialogueManagerSubsystem::HandleChoice(TArray<FDialogueChoice> Choices)
// {
// }

void UDialogueManagerSubsystem::ShowDialogue(const FString& Speaker, const FString& Message)
{
	if(GetRender())
	{
		UE_LOG(LogTemp, Log, TEXT("%s: %s"), *Speaker, *Message);
		GetRender()->DisplayDialogue(Speaker, Message);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to GetRender"));
	}
}
void UDialogueManagerSubsystem::ShowNextDialogueLine()
{
	UE_LOG(LogTemp, Log, TEXT("ShowNextDialogueLine called"))
	if (CurrentNodeIndex < DialogueNodes.Num())
	{
		// Get the current node
		CurrentNode = &DialogueNodes[CurrentNodeIndex];
		// Display the dialogue line
		ShowDialogue(CurrentNode->Speaker, CurrentNode->DialogueText);
		// Set the delay time between lines (adjust as needed)
		float DelaySeconds = CurrentNode->DelayTime;
		// Set the function to be called after the delay
		FTimerDelegate TimerDelegate = FTimerDelegate::CreateUObject(this, &UDialogueManagerSubsystem::ShowNextDialogueLine);
		GetWorld()->GetTimerManager().SetTimer(DelayTimerHandle, TimerDelegate, DelaySeconds, false);
		UE_LOG(LogTemp, Log, TEXT("Waiting for %f"), DelaySeconds)

		// Increment the index for the next line
		++CurrentNodeIndex;
	}
	else
	{
		// Dialogue is finished, do any cleanup or handle completion
		OnDialogueFinished();
	}
}

void UDialogueManagerSubsystem::OnDialogueFinished()
{
	// This function is called when the entire dialogue is finished
	// You can implement any logic here to handle completion, such as ending the conversation, triggering events, etc.
	UE_LOG(LogTemp, Warning, TEXT("TimeUp: Dialogue finished!"));
	if(GetRender()) GetRender()->ClearScreen();
}
