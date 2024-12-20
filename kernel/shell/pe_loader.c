#include "../kernel.h"

void run_windows_file(const char *filename) {
    // Call to Wine or a custom Windows API compatibility layer
    if (wine_exec(filename) == 0) {
        print_string("Windows file executed successfully.\n");
    } else {
        print_string("Failed to execute Windows file.\n");
    }
}
