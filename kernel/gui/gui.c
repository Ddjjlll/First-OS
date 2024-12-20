#include "../kernel.h"
#include <stdint.h> // Include this header for uint8_t

// Function prototypes
void put_pixel(int x, int y, uint8_t color);
void draw_text(int x, int y, const char *text, uint8_t color);
int mouse_clicked_on(int x1, int y1, int x2, int y2); // Assuming this function exists

// Draw a filled rectangle
void draw_rectangle(int x, int y, int width, int height, uint8_t color) {
    for (int i = y; i < y + height; i++) {
        for (int j = x; j < x + width; j++) {
            put_pixel(j, i, color);
        }
    }
}

// Draw a window with a title
void draw_window(int x, int y, int width, int height, const char *title) {
    // Draw the window frame
    draw_rectangle(x, y, width, height, 0x07); // Gray background
    draw_rectangle(x, y, width, 20, 0x0F);    // White title bar
    // Display the title
    draw_text(x + 5, y + 5, title, 0x00); // Black text
}

// Draw a button
void draw_button(int x, int y, int width, int height, const char *label, uint8_t color) {
    draw_rectangle(x, y, width, height, color); // Button background
    draw_text(x + width / 4, y + height / 4, label, 0x0F); // Button label
}

// Draw text (simple implementation)
void draw_text(int x, int y, const char *text, uint8_t color) {
    while (*text) {
        put_pixel(x, y, color); // Placeholder (expand to real font rendering)
        x += 8; // Move to the next character position
        text++;
    }
}

// Check if the mouse is clicking on a button
int is_button_clicked(int x, int y, int width, int height) {
    return mouse_clicked_on(x, y, x + width, y + height);
}

// Draw a simple scrollbar
void draw_scrollbar(int x, int y, int height, int position, int max_position) {
    draw_rectangle(x, y, 10, height, 0x07); // Scrollbar background
    int knob_height = (height / max_position);
    draw_rectangle(x, y + position * knob_height, 10, knob_height, 0x03); // Scrollbar knob
}
