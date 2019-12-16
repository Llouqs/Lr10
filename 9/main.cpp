#include <Windows.h>
HINSTANCE hInst;
HWND wnd, button, editBox, label;

LRESULT _stdcall WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	
	switch(uMsg){
	case WM_CREATE:
		label = CreateWindowA("STATIC", "Enter header", WS_VISIBLE|WS_CHILD|SS_CENTER, 5, 5, 390, 20, hWnd, NULL, hInst, 0);
		button = CreateWindowA("BUTTON", "Close", WS_CHILD|WS_VISIBLE|BS_CENTER|BS_VCENTER, 5, 25, 380, 30, hWnd, NULL, hInst, 0);
		editBox = CreateWindowA("EDIT", "", WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|ES_LEFT|WS_BORDER, 5, 60, 380, 100, hWnd, NULL, hInst, 0);
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
		wnd = CreateWindowExA(WS_EX_APPWINDOW, "Окошечко", "Вид из окна",
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