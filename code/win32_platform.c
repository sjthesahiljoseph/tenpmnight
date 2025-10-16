
#include <windows.h>


LRESULT window_callback(
	[in] WNDPROC lpPrevWndFunc,
	[in] HWND    hWnd,
	[in] UINT    Msg,
	[in] WPARAM  wParam,
	[in] LPARAM  lParam
	) {



}


int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {


	WNDCLASSA window_class = {0};

	window_class.style = CS_HREDRAW|CS_VREDRAW;
	window_class.lpfnWndProc = window_callback;
	window_class.lpClassName = "TenPmNight Window Class";
	window_class.cbClsExtra;
	window_class.cbWndExtra;
	window_class.hInstance;
	window_class.hIcon;
	window_class.hCursor;
	window_class.hbrBackground;
	window_class.lpszMenuName;
	window_class.lpszClassName;

	RegisterClassA(
		[in] const WNDCLASSA *lpWndClass
		);

	HWND CreateWindowExA(0, window_class.lpClassName, LPCSTR lpWindowName,
						 DWORD dwStyle, int X, int Y, int nWidth, int nHeight,
						 HWND hWndParent, HMENU hMenu, HINSTANCE hInstance,
						 LPVOID lpParam
		);

	

}




