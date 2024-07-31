#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
char *convert_to_string(unsigned int num, int base, int uppercase);
void convert_non_printable(char c, char *buffer, int *index);

#endif /* MAIN_H */

