#include "../kernel.h"
#define KEYBOARD_PORT 0x60
#define ENTER_KEY 0x1C
#define BACKSPACE_KEY 0x0E

// Keyboard buffer to store user input
char keyboard_buffer[256];
int buffer_index = 0;

// Keyboard interrupt handler
void keyboard_interrupt_handler() {
    unsigned char scancode = inb(KEYBOARD_PORT);
    
    // Convert scancode to ASCII (simple US keyboard mapping)
    if (scancode & 0x80) {
        // Key released (not handled here)
    } else {
        char c = scancode_to_ascii(scancode);
        if (c == '\n') {
            keyboard_buffer[buffer_index] = '\0';
            buffer_index = 0; // Reset buffer index after Enter key
        } else if (c == '\b') {
            if (buffer_index > 0) {
                buffer_index--; // Move back in the buffer
            }
        } else {
            if (buffer_index < sizeof(keyboard_buffer) - 1) {
                keyboard_buffer[buffer_index++] = c; // Add character to buffer
            }
        }
    }
}

// Simple US keyboard scancode-to-ASCII converter
char scancode_to_ascii(unsigned char scancode) {
    static char keymap[128] = {
        0,  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
        '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
        0,   'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',  0,
        '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,   '*',  0, ' '
    };

    if (scancode < sizeof(keymap)) {
        return keymap[scancode];
    }
    return 0; // Return null character for unmapped scancodes
}

// Reads input into a buffer (blocks until Enter is pressed)
void get_input(char *buffer, int max_length) {
    while (1) {
        if (keyboard_buffer[0] != '\0') {
            int i;
            for (i = 0; keyboard_buffer[i] != '\0' && i < max_length - 1; i++) {
                buffer[i] = keyboard_buffer[i];
            }
            buffer[i] = '\0'; // Null-terminate the buffer
            keyboard_buffer[0] = '\0'; // Clear the keyboard buffer
            buffer_index = 0; // Reset buffer index
            break;
        }
    }
}