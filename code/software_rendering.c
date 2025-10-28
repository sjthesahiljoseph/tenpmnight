
internal void
clear_screen(u32 color) {
	u32 *pixel = render_buffer.pixels;

	for (int y = 0; y < render_buffer.height; y++) {
		for (int x = 0; x < render_buffer.width; x++) {
			*pixel++ = color;
		}	
	}
}

internal void
draw_rect_in_pixels(int x0, int y0, int x1, int y1, u32 color) {

	for (int y = y0; y < y1; y++) {
		u32 *pixel = render_buffer.pixels + x0 + render_buffer.width * y;
		for (int x = x0; x < x1; x++) {
			*pixel++ = color;
		}	
	}
}


