// Fill out your copyright notice in the Description page of Project Settings.

#define _WINSOCK_DEPRECATED_NO_WARNINGS


#include "MultiThreadTest.h"
#include "HAL/RunnableThread.h"

// window 기본 타입 Hide
#include "Windows/AllowWindowsPlatformTypes.h"

#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>

#include "Windows/HideWindowsPlatformTypes.h"

MultiThreadTest::MultiThreadTest()
{
	// 여기서 실제적으로 쓰레드가 생성이 된다.
	Thread = FRunnableThread::Create(this, TEXT("ChattingThread"));
}

MultiThreadTest::~MultiThreadTest()
{
	if (Thread)
	{
		// 실질적으로 쓰레드의 활동을 멈추고 쓰레드를 지우는 곳이다.
		UE_LOG(LogTemp, Warning, TEXT("Delete thread"));
		Thread->WaitForCompletion();
		Thread->Kill(); // Kill()이 Stop() 호출하네
		delete Thread;
	}

}


// 이 아래부터는 새로운 쓰레드에서 실행된다!


// 쓰레드를 초기화하는 곳이다.
bool MultiThreadTest::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("thread has been initialized"));


	//SOCKET ServerSocket;

	WSADATA wsaData;
	int nRet = WSAStartup(MAKEWORD(2, 2), &wsaData);	// Winsock 초기화
	if (nRet != 0) return false;

	// 소켓 생성
	ServerSocket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
	if (ServerSocket == INVALID_SOCKET) return false;

	// IP, Port 정보 입력
	SOCKADDR_IN ServerAddr;
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_port = htons(8000);
	ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	// 접속
	nRet = connect(ServerSocket, (sockaddr*)&ServerAddr, sizeof(sockaddr));
	if (nRet == SOCKET_ERROR) return false;



	// 여기서 false가 리턴이 되면 쓰레드가 실행되지 않는다.
	return true;
}

// 쓰레드가 실행해야하는 코드가 들어가는 실제적인 부분이다.
uint32 MultiThreadTest::Run()
{
	UE_LOG(LogTemp, Warning, TEXT("Run thread"));

	while (bRunThread)
	{

		char Buffer[1024] = "Hello World!";
		send(ServerSocket, Buffer, sizeof(Buffer), 0);
		
	}

	return 0;
}

void MultiThreadTest::Exit()
{
	if (ServerSocket)
	{
		// Socket 연결을 끊고 Winsock 사용을 종료
		closesocket(ServerSocket);
		WSACleanup();
	}
}

// 이 함수는 새로 만들어진 쓰레드에서 실행되지 않는다.
void MultiThreadTest::Stop()
{
	// 여기서 메모리 사용량을 정리하고 Run() 기능을 중지시킬 수 있다.
	// 이 작업이 완료될 때까지 기본 스레드는 중지된다.

	UE_LOG(LogTemp, Warning, TEXT("Stop thread"));

	bRunThread = false;


}