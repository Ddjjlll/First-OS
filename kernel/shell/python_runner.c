#include "../kernel.h"
#include <stddef.h> // For NULL

void run_python_interpreter() {
    const char *argv[] = {"/apps/python/python.exe", NULL}; // Ensure the first argument is the executable
    exec("/apps/python/python.exe", argv); // Execute the Python interpreter
}

void run_python_script(const char *script_path) {
    const char *argv[] = {"/apps/python/Python313/python.exe", script_path, NULL}; // Pass the script path
    exec("/apps/python/python.exe", argv); // Pass the script to the interpreter
}