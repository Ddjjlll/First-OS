#ifndef PYTHON_RUNNER_H
#define PYTHON_RUNNER_H

// Function to run the Python interpreter
void run_python_interpreter();

// Function to run a Python script
void run_python_script(const char *script_path);

// Function to check if the input is a Python script
int is_python_script(const char *input);

// Add other relevant function declarations here

#endif // PYTHON_RUNNER_H