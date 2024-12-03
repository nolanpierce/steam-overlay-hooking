#include "steam.h"

HRESULT(__fastcall* steam_hook)(
    u64 src,
    u64 dst,
    u64 original_function,
    int a4
) = nullptr;

bool steam::prepare()
{
    u64 handle = (u64)GetModuleHandleA(_("GameOverlayRenderer64.dll"));
    if (!handle) return false;

    u64 steam_hooking_function = *(u64*)(handle + 0x88BD0);
    if (!steam_hooking_function) return false;

    //this is our hooking function
    steam_hook = decltype(steam_hook)(steam_hooking_function);

    return steam_hook != nullptr;
}

int steam::create_hook(void* dst, void* src, void* original)
{
    if (!dst || !src || !original) return -1; //invalid params
    if (!steam_hook)               return -1;

    return steam_hook((u64)dst, (u64)src, (u64)original, 1);
}

