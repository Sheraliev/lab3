// DLLConsApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include <stdio.h>
#include <iostream>

using namespace std;
typedef void(__stdcall *PGetGroupAndName)();
void GetInfo()
{
	cout << "Ural Federal University"
}


int main()
{
	//	Динамическое подключение DLL (загрузка)
	HINSTANCE hDll = LoadLibrary(L"MyDLL.dll");
	//	Обработка случая отсутствия библиотеки
	if (hDll == NULL)
	{
		cout << "Error!" << endl;
		return 1;
	}
	//	Определение переменных, которые будут указателями на вызываемые функции
	PGetGroupAndName GetGroupAndName;
	//	Присвоение значений переменным
	GetGroupAndName = (PGetGroupAndName)GetProcAddress(hDll, "_GetGroupAndName");
	//	Использование функций
	cout << "Hello!!"
		GetInfo();
	(*GetGroupAndName)();
	//	Выгружаем библиотеку
	FreeLibrary(hDll);

}	
