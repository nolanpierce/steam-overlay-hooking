#include <Windows.h>
#include <iostream>
#include "types.h"
#include "steam.h"
#include "overlay.h"


void real_entry() {
	DisableThreadLibraryCalls(GetModuleHandleA(NULL));
	
	AllocConsole();
	freopen_s((FILE**)stdin, "CONIN$", "r", stdin);
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
	freopen_s((FILE**)stderr, "CONOUT$", "w", stderr);

	if (!steam::prepare()) {
		printf("failed to prepare steam hooking method lol\n");
		return;
	}

	u64 handle = (u64)GetModuleHandleA(("GameOverlayRenderer64.dll"));
	if (!handle) {
		printf("failed to fetch steam overlay dll it isnt loaded\n");
		return;
	}

	u64 present_address = *(u64*)(handle + 0x8F160);
	if (!present_address) {
		printf("failed to retrieve the address for present\n");
		return;
	}
	if (!steam::create_hook((void*)present_address, (void*)overlay::present, &o_present_function)) {
		printf("failed to hook steams present for rendering\n");
		return;
	}
		
}

BOOL WINAPI DllMain(
	HINSTANCE instance,
	DWORD reason,
	LPVOID reserved
) {
	
	switch (reason) {
	case DLL_PROCESS_ATTACH:

	}
}