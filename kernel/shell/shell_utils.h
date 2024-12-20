#ifndef SHELL_UTILS_H
#define SHELL_UTILS_H

#include <stddef.h> // Include this for size_t

void print_string(const char *str);
void get_input(char *buffer, size_t size);
void parse_command(const char *input, char **args);
void execute_command(char **args);

#endif // SHELL_UTILS_H