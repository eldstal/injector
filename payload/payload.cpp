// payload.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <stdio.h>

#include "game.h"
#include "payload.h"

bool shutdown;

FILE* LOG;


// Known global state variables of the game
char* BASE;
struct World **GameWorld;
struct GameAPI ** Game;
struct MasterServerConnection** g_masterServer;
struct GameServerConnection** g_gameServer;
bool* g_adminCharacter;


void setup_pointers() {

	HMODULE game_logic_dll = GetModuleHandle(L"GameLogic.dll");
	BASE = (char*)game_logic_dll;

	fprintf(LOG, "GameLogic base address: %p!\r\n", game_logic_dll);

	GameWorld = (struct World**) (BASE + 0x97d7c);
	Game = (struct GameAPI**) (BASE + 0x97d80);
	g_masterServer = (struct MasterServerConnection**) (BASE + 0x97d84);
	g_adminCharacter = (bool*)(BASE + 0x97d93);
	g_gameServer = (struct GameServerConnection**)(BASE + 0x97d94);

}

DWORD __stdcall payload_main_loop(LPVOID args) {

	fprintf(LOG, "Payload thread starting\r\n");
	fflush(LOG);


	setup_pointers();

	shutdown = false;
	while (!shutdown && *GameWorld == NULL) {
		Sleep(1000);
		fprintf(LOG, "Waiting for a game to start...\r\n");
		fflush(LOG);
	}

	if (*GameWorld != NULL) {
		fprintf(LOG, "Found a game world object at %p!\r\n", *GameWorld);
		fflush(LOG);
	}


	while (!shutdown) {
		*g_adminCharacter = true;
		
		
	}

	fprintf(LOG, "Payload thread terminating\r\n");
	fclose(LOG);

	return 0;
}