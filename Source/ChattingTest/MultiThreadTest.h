// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include <Windows/MinWindows.h>
#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>

/**
 * 
 */
class CHATTINGTEST_API MultiThreadTest : public FRunnable
{
public:
	MultiThreadTest();
	~MultiThreadTest();

	// 아래 3개의 함수는 따로 호출하지 않고 자동적으로 동작할 것이다.
	// 쓰레드를 할당할 함수이다.
	bool Init() override;
	// 쓰레드를 활용해서 할 일을 넣을 함수이다.
	uint32 Run() override;
	// 스레드가 언제 종료되어야 하는지 알 때 사용, Run()에서 호출한다.
	void Stop() override;

	void Exit() override;

	SOCKET ServerSocket;

private:
	// 쓰레드를 핸들링할 변수이다.
	class FRunnableThread* Thread;
	// RUN 함수 활용할 변수이다.
	bool bRunThread;

};
