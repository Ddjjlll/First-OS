#include <windows.h> // Include the Windows API header
#include <stdio.h>

void load_windows_shared_library(const char *filename) {
    HMODULE handle = LoadLibraryA(filename); // Load the shared library
    if (handle == NULL) {
        printf("Failed to load shared library.\n");
    } else {
        printf("Shared library loaded successfully.\n");
        // Optionally, you can get a function from the library using GetProcAddress
        // and later free the library with FreeLibrary(handle);
        // FreeLibrary(handle); // Call this when you're done with the library
    }
}