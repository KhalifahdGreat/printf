#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
char *convert_to_string(unsigned long num, int base, int uppercase);
void convert_non_printable(char c, char *buffer, int *index);
char *convert_pointer_to_string(void *ptr);
int handle_flags(const char **format);
int handle_length_modifier(const char **format);

#endif /* MAIN_H */

