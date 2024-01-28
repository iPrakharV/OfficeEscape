// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DialogueTriggerComponent.generated.h"

class UDialogueManagerSubsystem;
class UDialogueManager;
struct FDialogueNode;
/*
 * Dialogue Choice Structure
 */
USTRUCT(BlueprintType)
struct FDialogueChoice
{
	GENERATED_BODY();
	UPROPERTY(EditAnywhere)
	FString Text;
	UPROPERTY(EditAnywhere)
	bool bOpen;
	UPROPERTY(EditAnywhere)
	bool bChosen;
	
	TObjectPtr<FDialogueNode> NextDialogue;
};


/**
 * Dialogue Node Structure
 */
USTRUCT(BlueprintType)
struct FDialogueNode
{
	GENERATED_BODY();
	UPROPERTY(EditAnywhere)
	FString Speaker;

	UPROPERTY(EditAnywhere)
	FString DialogueText;
	
	UPROPERTY(EditAnywhere)
	bool bSeen;

	UPROPERTY(EditAnywhere)
	bool bHasChoice{false};

	UPROPERTY(EditAnywhere)
	float DelayTime{15.f};

	UPROPERTY(EditAnywhere)
	TArray<FDialogueChoice> Choices;
};


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class OFFICEESCAPE_01_API UDialogueTriggerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	void GetDialogueManager();
	// Sets default values for this component's properties
	UDialogueTriggerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
	void TriggerDialogue();
protected:
	UPROPERTY(BlueprintReadOnly, Category="Dialogue")
	TObjectPtr<UDialogueManagerSubsystem> DialogueManager;
	UPROPERTY(EditAnywhere, Category="Dialogue")
	bool bEnabled;
	UPROPERTY(EditAnywhere, Category="Dialogue")
	TArray<FDialogueNode> DialogueNodes;
	

};
