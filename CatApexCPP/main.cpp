#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "proc_help.h"
#include "DriverHelp.h"
#include "DrawEng.h"
#include "hackerThreads.h"
#include <atlstr.h>

HANDLE gamePid;
__int64 hGameModule;
int fontSize;
HWND hGameWind;

int main() {
	initColor();
	initConfig();
	initMenu();
	const char *mySys = "C:\\catdrv.sys";
	bool hDriver = loadDrv(mySys);
	printf("%s\n", mySys);
	if (!hDriver) {
		MessageBoxA(nullptr, "��װ��������ʧ��, ����ɱ������Ƿ����ػ��ظ�����", nullptr, 0);
		return -1;
	}
	printf("OK\n");
	hGameWind = 0;
	while (!hGameWind) {
		hGameWind = FindWindowA("Respawn001", "Apex Legends");
		Sleep(100);
	}
	gamePid = (HANDLE)GetProcessIDByName("r5apex.exe");
	if (!gamePid) {
		MessageBoxA(nullptr, "����ID��ȡ�����������Ľ������Ƿ�Ϊr5apex.exe", nullptr, 0);
		return -1;
	}
	printf("����ID: %p\n", gamePid);
	hGameModule = getBaseModule((HANDLE)gamePid);
	printf("ģ���ַ: %lld\n", hGameModule);
	ShowWindow(hGameWind, 9);
	fontSize = 64;
	startThreads();
	StartDraw(0);

}