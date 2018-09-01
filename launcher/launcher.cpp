// launcher.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include <Windows.h>
#include <stdio.h>
#include <shlwapi.h>
#include <psapi.h>
#include <tchar.h>
#include <string>

int find_target_pid(const wchar_t* exe) {
	DWORD pids[1024], cbNeeded, cProcesses;
	unsigned int i;

	if (!EnumProcesses(pids, sizeof(pids), &cbNeeded))
	{
		return 1;
	}

	cProcesses = cbNeeded / sizeof(DWORD);

	// Print the name and process identifier for each process.

	int target_pid = -1;
	for (i = 0; i < cProcesses; i++)
	{
		if (pids[i] != 0)
		{
			TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

			HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
				PROCESS_VM_READ,
				FALSE, pids[i]);

			// Get the process name.

			if (NULL != hProcess)
			{
				HMODULE hMod;
				DWORD cbNeeded;

				if (EnumProcessModules(hProcess, &hMod, sizeof(hMod),
					&cbNeeded))
				{
					GetModuleBaseName(hProcess, hMod, szProcessName,
						sizeof(szProcessName) / sizeof(TCHAR));

					if (!wcscmp(szProcessName, exe)) {
						target_pid = pids[i];
					}
				}
			}

			CloseHandle(hProcess);
		}
	}

	return target_pid;
}

// Unicode nonsense
std::string wstring_to_string(LPCTSTR inp) {
	std::wstring wstr(inp);
	std::string temp(wstr.length(), ' ');
	std::copy(wstr.begin(), wstr.end(), temp.begin());
	return temp;
}

int hax() {


	// Path to the DLL which is in the same directory as the launcher EXE
	HMODULE hModule = GetModuleHandleW(NULL);
	TCHAR wpath[MAX_PATH];
	GetModuleFileNameW(hModule, wpath, MAX_PATH);
	PathRemoveFileSpec(wpath);
	wcscat(wpath, L"\\payload.dll");

	// Those functions are WSTR only, but we need a plain CSTR to copy to the victim.
	std::string spath = wstring_to_string(wpath);
	const CHAR* path = spath.c_str();

	printf("DLL path: %s\n", path);

	
	//char path[] = "D:\\Storage\\Hax\\pwnadventure\\Injector\\Debug\\payload.dll";

	/*
	* Get process handle passing in the process ID.
	*/
	int procID = find_target_pid(L"PwnAdventure3-Win32-Shipping.exe");
	printf("Found target process: %d\n", procID);


	HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);
	if (process == NULL) {
		printf("Error: the specified process couldn't be found.\n");
		return 1;
	}
	

	/*
	* Get address of the LoadLibrary function.
	*/
	LPVOID addr = (LPVOID)GetProcAddress(GetModuleHandle(L"kernel32.dll"), "LoadLibraryA");
	if (addr == NULL) {
		printf("Error: the LoadLibraryA function was not found inside kernel32.dll library.\n");
	}

	/*
	* Allocate new memory region inside the process's address space.
	*/
	LPVOID arg = (LPVOID)VirtualAllocEx(process, NULL, strlen(path)+1, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (arg == NULL) {
		printf("Error: the memory could not be allocated inside the chosen process.\n");
	}

	printf("Argument string allocated in target process: 0x%p\n", arg);

	/*
	* Write the argument to LoadLibraryA to the process's newly allocated memory region.
	*/
	int n = WriteProcessMemory(process, arg, path, strlen(path)+1, NULL);
	if (n == 0) {
		printf("Error: there was no bytes written to the process's address space.\n");
	}

	printf("Argument string copied to target process\n");

	/*
	* Call LoadLibraryA() to inject our DLL into the process's address space.
	*/
	HANDLE threadID = CreateRemoteThread(process, NULL, 0, (LPTHREAD_START_ROUTINE)addr, arg, NULL, NULL);
	if (threadID == NULL) {
		printf("Error: the remote thread could not be created.\n");
	}
	else {
		printf("Success: the remote thread was successfully created.\n");
	}

	/*
	* Cleanup
	*/
	CloseHandle(process);

	return 0;
}

int main(int argc, _TCHAR* argv[]) {
	hax();
	getchar();

}