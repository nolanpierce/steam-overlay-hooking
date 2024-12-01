#include "overlay.h"

WNDPROC						   wndproc_original		= nullptr;
HWND						   window				= 0;
static  bool				   show_menu			= false;
static ID3D11Device*		   device				= nullptr;
static ID3D11DeviceContext*	   context				= nullptr;
static ID3D11RenderTargetView* target_view			= nullptr;
present_function			   o_present_function	= nullptr;

HRESULT __stdcall overlay::present(IDXGISwapChain* swapchain, UINT sync, UINT flags)
{
	if (!device) {

		if (!SUCCEEDED(swapchain->GetDevice(__uuidof(ID3D11Device), (void**)device)))
			return o_present_function(swapchain, sync, flags);

		device->GetImmediateContext(&context);
		DXGI_SWAP_CHAIN_DESC desc;
		swapchain->GetDesc(&desc);

		window = desc.OutputWindow;
		ID3D11Texture2D* buffer;
		swapchain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&buffer);
		device->CreateRenderTargetView(buffer, NULL, &target_view);

		buffer->Release();
		wndproc_original = (WNDPROC)SetWindowLongPtrA(window, GWLP_WNDPROC, (LONG_PTR)wndproc_handler); //need to lazy import all of these win api calls

		auto& io = ImGui::GetIO();
		io.LogFilename = nullptr;
		io.IniFilename = nullptr;

		
		ImGui_ImplWin32_Init(window);
		ImGui_ImplDX11_Init(device, context);
	}

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();

	if (GetAsyncKeyState(VK_INSERT) & 1)
		show_menu ^= 1;

	if (show_menu)
		render_menu();

	return o_present_function(swapchain, sync, flags);
}

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
LRESULT __stdcall overlay::wndproc_handler(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	if (show_menu) {
		return ImGui_ImplWin32_WndProcHandler(hwnd, msg, wparam, lparam);
	}

	return CallWindowProcA(wndproc_original, hwnd, msg, wparam, lparam); //need to lazy import this too
}
