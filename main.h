#ifndef MAIN_H

#include <stdarg.h>
#include <unistd.h>
int _printf(const char *format, ...);
void print_binary(unsigned int n, int fd);
void print_string(const char *s, int fd, int *num);
void handle_d_i(int fd, va_list alx);




#endif
