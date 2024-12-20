#include "python_runner.h"
#include "shell_utils.h"  // Include your shell utility header
#include <string.h>       // For strcmp

void shell() {
    char input[128];
    char *args[16];
    while (1) {
        print_string("> ");
        get_input(input, sizeof(input));
        parse_command(input, args);
        // Detect Python script or REPL
        if (is_python_script(args[0])) {
            run_python_script(args[0]);  // Execute Python script
        } else if (strcmp(args[0], "python") == 0) {
            run_python_interpreter();   // Launch Python REPL
        } else {
            execute_command(args);      // Execute other shell commands
        }
    }
}