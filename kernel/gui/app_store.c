#include "../kernel.h"
#include "app.h"

#define STORE_BG_COLOR 0x1F // Blue background
#define BUTTON_COLOR 0x03   // Blue button
#define APPS_PER_PAGE 5     // Number of apps displayed per page

StoreApp store_apps[MAX_STORE_APPS] = {
    {"Chrome", "A lightweight browser.", install_chrome},
    {"Calculator", "Perform basic calculations.", calculator_app},
    {"Settings", "Manage system settings.", settings_app},
    {"Paint", "A simple drawing app.", NULL},
    {"Notes", "A simple note-taking app.", NULL},
    {"Terminal", "Command line interface.", NULL},
    {"Music", "Music player app.", NULL},
};
int num_store_apps = 7;

// Draw the store page with scrolling support
void draw_store_page(int start_index) {
    clear_screen_vga(STORE_BG_COLOR);
    draw_window(50, 50, 500, 400, "App Store");

    for (int i = 0; i < APPS_PER_PAGE && (start_index + i) < num_store_apps; i++) {
        int app_index = start_index + i;
        int y = 100 + i * 50;
        draw_text(60, y, store_apps[app_index].name, 0x0F); // App name
        draw_text(60, y + 15, store_apps[app_index].description, 0x0F); // App description
        draw_button(400, y, 80, 30, "Install", BUTTON_COLOR); // Install button
    }

    // Draw navigation buttons if necessary
    if (start_index > 0) {
        draw_button(200, 350, 80, 30, "Prev", BUTTON_COLOR);
    }
    if (start_index + APPS_PER_PAGE < num_store_apps) {
        draw_button(300, 350, 80, 30, "Next", BUTTON_COLOR);
    }
}

// Store application logic with scrolling
void store_app() {
    int start_index = 0;
    draw_store_page(start_index);

    while (1) {
        for (int i = 0; i < APPS_PER_PAGE && (start_index + i) < num_store_apps; i++) {
            int y = 100 + i * 50;
            if (is_button_clicked(400, y, 80, 30)) { // Install button clicked
                store_apps[start_index + i].install(); // Install the app
                draw_text(60, 350, "App installed!", 0x0F);
                draw_store_page(start_index); // Refresh the page
            }
        }

        if (is_button_clicked(200, 350, 80, 30) && start_index > 0) {
            start_index -= APPS_PER_PAGE; // Scroll up
            draw_store_page(start_index);
        }

        if (is_button_clicked(300, 350, 80, 30) && start_index + APPS_PER_PAGE < num_store_apps) {
            start_index += APPS_PER_PAGE; // Scroll down
            draw_store_page(start_index);
        }

        // Exit store if top-left corner clicked
        if (mouse_clicked_on(0, 0, 50, 50)) {
            return;
        }
    }
}
