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

		LOG = fopen("hax_log.txt", "w+");
		fprintf(LOG, "Payload DLL process attach\r\n");
		fflush(LOG);
		CreateThread(NULL, 0, &payload_main_loop, NULL, 0, NULL);

		break;

    case DLL_THREAD_ATTACH:
		fprintf(LOG, "Payload DLL thread attach\r\n");
		break;

    case DLL_THREAD_DETACH:
		fprintf(LOG, "Payload DLL thread detach\r\n");
		break;

    case DLL_PROCESS_DETACH:
		fprintf(LOG, "Payload DLL process detach\r\n");
		shutdown = true;

        break;
    }
    return TRUE;
}

