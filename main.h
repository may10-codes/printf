#ifndef MAIN_H

#include <stdarg.h>
#include <unistd.h>
int _printf(const char *format, ...);
void handle_d_i(int fd, int nume);
void print_string(const char *s, int fd, int *num);
void print_binary(unsigned int n, int fd);
int print_unsigned(unsigned int n, int (*write_func)(int fd, const void *buf, size_t n));



#endif
