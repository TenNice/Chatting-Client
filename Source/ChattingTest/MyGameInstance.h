// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "Components/Widget.h"

#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CHATTINGTEST_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UMyGameInstance();

	virtual void Init() override;

	UFUNCTION(BlueprintCallable, meta = (KeyWords = "Thread"))
	void CreateThread();

	UFUNCTION(BlueprintCallable, meta = (KeyWords = "Thread"))
	void DeleteThread();

	class MultiThreadTest* Worker;
	
};
