printf project:

Custom printf: Section 0

Overview

This section introduces the custom printf function, which serves as a rudimentary implementation of the standard printf function in C. The custom _printf function utilizes the va_list data structure to handle variable arguments and processes format specifiers to print characters, strings, and integer values.

Function Prototype
int _printf(const char *format, ...)

Parameters
format: A pointer to the format string, which contains formatting instructions and data types to be printed.
...: A variable argument list containing values to be formatted and printed according to the format string.

Return Value
The total number of characters printed by the function.

Function Implementation
The implementation of the _printf function follows a structured approach:
Variable Declaration: Declare variables to store character, string, and file descriptor (fd) values.
Argument Parsing: Initialize a va_list object using va_start() and advance the format pointer (format).
Format Specifier Processing: While the format string is not empty, iterate through it character by character:
a. Character Specifier: If %c is encountered, extract the character from the argument list and write it to the standard output using write().
b. String Specifier: If %s is encountered, extract the string from the argument list and write it to the standard output using write() while checking for the end-of-string character (\0).
c. Percentage Specifier: If % is encountered, write the literal % character to the standard output using write().
d. Non-Specifier: If none of the above conditions are met, write the current character from the format string to the standard output using write().
Argument List Termination: Terminate the va_list object using va_end().
Function Return: Return the total number of characters printed by the function.
