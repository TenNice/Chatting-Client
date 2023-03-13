// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CHATTINGTEST_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMyPlayerController();

	UFUNCTION(BlueprintCallable, meta=(KeyWords = "Thread"))
	void CreateThread();

	UFUNCTION(BlueprintCallable, meta = (KeyWords = "Thread"))
	void DeleteThread();

	class MultiThreadTest* Worker;
	
};
