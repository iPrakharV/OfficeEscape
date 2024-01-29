// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueSystem/DialogueRenderer.h"


#include "Blueprint/UserWidget.h"
#include "DialogueSystem/RenderComponent.h"

#include "Kismet/GameplayStatics.h" // Include this for UGameplayStatics
#include "OfficeEscape_01/TP_ThirdPerson/TP_ThirdPersonCharacter.h"


UDialogueRenderer::UDialogueRenderer()
{
	
}



void UDialogueRenderer::DisplayDialogue(const FString& Speaker, const FString& Message)
{
	
	if (UWorld* World = GetWorld())
	{
		ATP_ThirdPersonCharacter* PlayerCharacter = Cast<ATP_ThirdPersonCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		if (PlayerCharacter && PlayerCharacter->DialogueRenderComponent)
		{
			PlayerCharacter->DialogueRenderComponent->DisplayDialogue(Speaker, Message);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get world!"));
	}
}

void UDialogueRenderer::DisplayChoices(const TArray<FString>& Choices)
{
}

void UDialogueRenderer::ClearScreen()
{
	UE_LOG(LogTemp, Warning, TEXT("Clearing Screen"));
	if (UWorld* World = GetWorld())
	{
		ATP_ThirdPersonCharacter* PlayerCharacter = Cast<ATP_ThirdPersonCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		if (PlayerCharacter && PlayerCharacter->DialogueRenderComponent)
		{
			PlayerCharacter->DialogueRenderComponent->ClearScreen();
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get world!"));
	}
}
