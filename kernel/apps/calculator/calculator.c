#include "../../kernel.h"
#include "../../gui.h"

void calculator_ui() {
    init_graphics();  // Initialize the GUI system

    // Create UI components
    draw_rectangle(100, 50, 400, 500, 0xFFFFFF);  // Calculator background
    draw_text(150, 75, "Calculator", 0x000000);   // Title
    draw_rectangle(150, 120, 300, 60, 0xDDDDDD); // Display box
    draw_text(160, 140, "0", 0x000000);          // Default display text

    // Draw buttons
    int button_x = 150, button_y = 200;
    int button_width = 80, button_height = 60;
    char *buttons[] = {"7", "8", "9", "+",
                       "4", "5", "6", "-",
                       "1", "2", "3", "*",
                       "C", "0", "=", "/"};
    for (int i = 0; i < 16; i++) {
        draw_rectangle(button_x, button_y, button_width, button_height, 0xAAAAAA); // Button
        draw_text(button_x + 30, button_y + 20, buttons[i], 0x000000);             // Button label

        button_x += 100;
        if ((i + 1) % 4 == 0) {
            button_x = 150;
            button_y += 80;
        }
    }

    // Wait for user interaction (placeholder)
    wait_for_mouse_click();  // To be implemented: handle mouse events
}
