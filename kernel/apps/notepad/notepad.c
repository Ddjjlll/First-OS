#include "../../kernel.h"
#include "../../gui.h"

void notepad_ui() {
    init_graphics();  // Initialize the GUI system

    // Draw Notepad UI
    draw_rectangle(50, 50, 600, 400, 0xFFFFFF); // Background
    draw_text(100, 75, "Notepad", 0x000000);    // Title

    // File menu
    draw_text(75, 120, "File", 0x000000);
    draw_rectangle(70, 130, 80, 30, 0xDDDDDD); // File menu dropdown
    draw_text(75, 135, "Save", 0x000000);

    // Editing area
    draw_rectangle(75, 180, 500, 250, 0xEEEEEE); // Text editing area

    // Wait for user interaction (placeholder)
    wait_for_keyboard_input(); // To be implemented: handle keyboard events
}
