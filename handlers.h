#ifndef HANDLERS_H
#define HANDLERS_H

#include <stdarg.h>
#include "buffer.h"

unsigned char handle_flags(const char *format, char *tmp);
int handle_width(va_list args, const char *format, char *tmp);
int handle_precision(va_list args, const char *format, char *tmp);
unsigned char handle_length(const char *format, char *tmp);
unsigned int (*handle_specifiers(const char *format))(va_list, buffer_t *, unsigned char, int, int, unsigned char);

#endif /* HANDLERS_H */

