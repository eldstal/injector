// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <stdio.h>
#include "payload.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{



    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		MessageBox(
			NULL,
			L"Payload loaded.",
			L"Oh yeah",
			MB_ICONEXCLAMATION | MB_OK
		);

		// TODO: Start main loop
		break;

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
		break;

    case DLL_PROCESS_DETACH:

		// TODO: Terminate main loop here
		MessageBox(
			NULL,
			L"Payload terminating.",
			L"Oh no!",
			MB_ICONEXCLAMATION | MB_OK
		);
        break;
    }
    return TRUE;
}

