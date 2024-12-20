#include "kernel.h"

void save_app(const char *app_name) {
    // Example: Save app data into a simple in-memory file system (expand later)
    print_string("Saving app ");
    print_string(app_name);
    print_string(" to /apps folder...\n");
}

void load_apps_from_folder() {
    // Load installed apps into memory (future implementation)
    print_string("Loading apps from /apps folder...\n");
}
