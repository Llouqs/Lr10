#include <Windows.h>

LRESULT _stdcall WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	switch(uMsg){
	case WM_CREATE:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default: return DefWindowProcA(hWnd, uMsg, wParam, lParam);
	}
}

int _stdcall WinMain(HINSTANCE hinstance, HINSTANCE hPrevInst, LPSTR CmdLine, int ShowCmd){
	WNDCLASSEXA  window;
	ZeroMemory(&window, sizeof window);
	window.cbSize = sizeof(WNDCLASSEXA);
	window.lpszClassName = "Окошечко";
	window.hInstance = hinstance;
	window.lpfnWndProc = WndProc;
	window.style = CS_HREDRAW | CS_VREDRAW;
	window.hCursor = LoadCursor(NULL, IDC_ARROW);
	window.hbrBackground = GetSysColorBrush(COLOR_BTNFACE);
	if (RegisterClassExA(&window)!=0)
	{
		HWND wnd = CreateWindowExA(WS_EX_APPWINDOW, "Окошечко", "Вид из окна",
								   WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU, CW_USEDEFAULT,
								   0, 400, 200, NULL, NULL, hinstance, NULL);
		if (wnd!=NULL)
		{
			ShowWindow(wnd, ShowCmd);
			UpdateWindow(wnd);
			MSG msg;
			while(GetMessageA(&msg, NULL, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
	}
	return 0;
}