#include <Windows.h>





void real_entry() {
	DisableThreadLibraryCalls(GetModuleHandleA(NULL));
	
	//here are our hooks




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