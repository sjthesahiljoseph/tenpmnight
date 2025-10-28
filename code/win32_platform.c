

#include <windows.h>

LRESULT window_callback(HWND window, UINT message, WPARAM w_param, LPARAM l_param) {

	return DefWindowProcA(window, message, w_param, l_param);
}



int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
			LPSTR lpCmdLine, int nShowCmd) {

	WNDCLASSA window_class = {0};

	window_class.style = CS_HREDRAW|CS_VREDRAW;
	window_class.lpfnWndProc = window_callback;
	window_class.cbClsExtra = 0;
	window_class.cbWndExtra = 0;
	window_class.hInstance = hInstance;
	window_class.hIcon = 0;
	window_class.hCursor = 0;
	window_class.hbrBackground = 0;
	window_class.lpszMenuName = 0;
	window_class.lpszClassName = "sj the sahil joseph's tenpmnight";
/*
	RegisterClassA(
		[in] const WNDCLASSA *lpWndClass
		);

	HWND window = CreateWindowExA(0, window_class.lpszClassName,
								  LPCSTR lpWindowName, DWORD dwStyle,
								  int X, int Y,
								  int nWidth, int nHeight,
								  HWND hWndParent, HMENU hMenu,
								  HINSTANCE hInstance, LPVOID lpParam);
	*/

	return 0;
}


