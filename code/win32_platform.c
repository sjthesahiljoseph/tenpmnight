

#include "utils.c"


#include <windows.h>

struct {
	// platform non-specific.
	int width;
	int height;
	u32 *pixels;
	// platform specific.
	BITMAPINFO bitmap_info;

} typedef Render_Buffer;

/* struct { */
/* 	int width; */
/* 	int height; */
/* 	u32 *pixels; */
/* 	BITMAPINFO bitmap_info; */
/* } typedef Game_Render_Buffer; */

global_variable Render_Buffer render_buffer;

#include "software_rendering.c"

internal
LRESULT window_callback(HWND window, UINT message, WPARAM w_param, LPARAM l_param) {

	LRESULT result = 0;

	switch (message) {
		
	case WM_CLOSE:
	case WM_DESTROY: {
		
		running = false;
		
	} break;

	case WM_SIZE: {

		RECT rect;

		GetWindowRect(window, &rect);

		render_buffer.width = rect.right - rect.left;
		render_buffer.height = rect.bottom - rect.top;

		if (render_buffer.pixels) {
			VirtualFree(render_buffer.pixels, 0, MEM_RELEASE);
		}

		render_buffer.pixels = VirtualAlloc(0, (sizeof(u32) * (render_buffer.width * render_buffer.height)),
											MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

		render_buffer.bitmap_info.bmiHeader.biSize = sizeof(render_buffer.bitmap_info.bmiHeader);
		render_buffer.bitmap_info.bmiHeader.biWidth = render_buffer.width;
		render_buffer.bitmap_info.bmiHeader.biHeight = render_buffer.height;
		render_buffer.bitmap_info.bmiHeader.biPlanes = 1;
		render_buffer.bitmap_info.bmiHeader.biBitCount = 32;
		render_buffer.bitmap_info.bmiHeader.biCompression = BI_RGB;
		render_buffer.bitmap_info.bmiHeader.biSizeImage = 0;
		
		
		
	} break;

	default: {
		
		result = DefWindowProcA(window, message, w_param, l_param);

	} break;

	}
		

	return result;
}



int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

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
								  WS_VISIBLE|WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
								  1280, 720, 0, 0, 0, 0);
	
	HDC hdc = GetDC(window);

	while (running) {
		
		MSG message;

		while (PeekMessageA(&message, window, 0, 0, PM_REMOVE)) {

			TranslateMessage(&message); 
            DispatchMessage(&message); 


		}

		clear_screen(0xff40ff40);

		StretchDIBits(hdc, 0, 0, render_buffer.width, render_buffer.height, 0, 0,
					  render_buffer.width, render_buffer.height, render_buffer.pixels,
					  &render_buffer.bitmap_info, DIB_RGB_COLORS, SRCCOPY);

		
	}


	return 0;
}


