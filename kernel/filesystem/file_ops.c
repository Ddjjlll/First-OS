#include "../kernel.h"

const char *get_file_extension(const char *filename) {
    const char *dot = strrchr(filename, '.');
    return dot ? dot + 1 : "";
}

void handle_file(const char *filename) {
    const char *ext = get_file_extension(filename);

    if (strcmp(ext, "exe") == 0 || strcmp(ext, "dll") == 0) {
        run_windows_file(filename);  // Windows PE support
    } else if (strcmp(ext, "sh") == 0) {
        run_shell_script(filename); // Bash support
    } else if (strcmp(ext, "py") == 0) {
        run_python_script(filename); // Python support
    } else if (strcmp(ext, "so") == 0) {
        load_linux_shared_library(filename); // Linux shared libraries
    } else if (strcmp(ext, "bat") == 0) {
        run_batch_file(filename); // Batch script support
    } else if (strcmp(ext, "ps1") == 0) {
        run_powershell_script(filename); // PowerShell support
    } else {
        print_string("Unsupported file type.\n");
    }
}
