// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "MultiThreadTest.h"

UMyGameInstance::UMyGameInstance()
{
	
}

void UMyGameInstance::Init()
{
	Super::Init();
}

void UMyGameInstance::CreateThread()
{
	Worker = new MultiThreadTest;
}

void UMyGameInstance::DeleteThread()
{
	Worker->Stop();
	delete Worker;
}
