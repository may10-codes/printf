#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
int _printf(const char *format, ...);
void handle_d_i(int fd, int nume);
void print_string(const char *s, int fd, int *num);
void print_binary(unsigned int n, int fd);



#endif
