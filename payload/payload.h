#pragma once
#include <fcntl.h>


extern bool shutdown;
extern FILE* LOG;

DWORD __stdcall payload_main_loop(LPVOID);