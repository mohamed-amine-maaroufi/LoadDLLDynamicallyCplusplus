// dllmain.cpp : Définit le point d'entrée de l'application DLL.
#include "pch.h"
#include "C_DllPathData.h"
#include "dllMain.h"
#include "C_ClassWillBeExported.h"
#include <iostream>

using namespace std;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		
		break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
		break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


void clientMessage()
{
	cout << "BEGIN - export function : clientMessage" << endl;

	C_ClassWillBeExported::createInstance().message();

	cout << "END - export function : clientMessage" << endl;

}
