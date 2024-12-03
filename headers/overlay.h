#pragma once
#include <Windows.h>
#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")
#include "types.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx11.h"
#include "ImGui/imgui_impl_win32.h"
#include  "menu.h"

typedef HRESULT(__stdcall* present_function)(IDXGISwapChain*, UINT, UINT);
extern present_function o_present_function;

namespace overlay {
	HRESULT __stdcall present(IDXGISwapChain* swapchain, UINT sync, UINT flags);
	LRESULT	__stdcall wndproc_handler(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
	bool initialize();
}