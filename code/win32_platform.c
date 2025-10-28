

#include <windows.h>

typedef int b32;

#define global_variable static
#define internal static

#define true 1
#define false 0

global_variable b32 running = true;

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

	RegisterClassA(&window_class);


	HWND window = CreateWindowExA(0, window_class.lpszClassName, window_class.lpszClassName,
								  WS_VISIBLE|WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
								  CW_USEDEFAULT,
								  1280, 720, 0, 0, 0, 0);


	return 0;
}


