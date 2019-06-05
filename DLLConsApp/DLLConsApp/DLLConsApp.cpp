// DLLConsApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include <stdio.h>
#include <iostream>

using namespace std;
typedef void(__stdcall *PGetGroupAndName)();

int main()
{
	//	������������ ����������� DLL (��������)
	HINSTANCE hDll = LoadLibrary(L"MyDLL.dll");
	//	��������� ������ ���������� ����������
	if (hDll == NULL)
	{
		cout << "Error!" << endl;
		return 1;
	}
	//	����������� ����������, ������� ����� ����������� �� ���������� �������
	PGetGroupAndName GetGroupAndName;
	//	���������� �������� ����������
	GetGroupAndName = (PGetGroupAndName)GetProcAddress(hDll, "_GetGroupAndName");
	//	������������� �������
	(*GetGroupAndName)();
	//	��������� ����������
	FreeLibrary(hDll);

}	
