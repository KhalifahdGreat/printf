#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string composed of zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    int count = 0, buffer_index = 0;
    char buffer[BUFFER_SIZE];
    va_list args;
    const char *p;

    if (!format)
        return (-1);

    va_start(args, format);

    for (p = format; *p; p++)
    {
        if (*p == '%')
        {
            p++;
            switch (*p)
            {
                case 'c':
                {
                    char c = va_arg(args, int);
                    buffer[buffer_index++] = c;
                    break;
                }
                case 's':
                {
                    char *str = va_arg(args, char *);
                    if (!str)
                        str = "(null)";
                    while (*str)
                        buffer[buffer_index++] = *str++;
                    break;
                }
                case 'S':
                {
                    char *str = va_arg(args, char *);
                    if (!str)
                        str = "(null)";
                    while (*str)
                    {
                        if ((*str > 0 && *str < 32) || *str >= 127)
                        {
                            convert_non_printable(*str, buffer, &buffer_index);
                        }
                        else
                        {
                            buffer[buffer_index++] = *str;
                        }
                        str++;
                    }
                    break;
                }
                case 'p':
                {
                    void *ptr = va_arg(args, void *);
                    char *str = convert_pointer_to_string(ptr);
                    if (!str)
                        return (-1);
                    while (*str)
                        buffer[buffer_index++] = *str++;
                    break;
                }
                case '%':
                    buffer[buffer_index++] = '%';
                    break;
                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    char *str = convert_to_string(num, 10, 0);
                    if (!str)
                        return (-1);
                    while (*str)
                        buffer[buffer_index++] = *str++;
                    break;
                }
                case 'u':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    char *str = convert_to_string(num, 10, 0);
                    if (!str)
                        return (-1);
                    while (*str)
                        buffer[buffer_index++] = *str++;
                    break;
                }
                case 'o':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    char *str = convert_to_string(num, 8, 0);
                    if (!str)
                        return (-1);
                    while (*str)
                        buffer[buffer_index++] = *str++;
                    break;
                }
                case 'x':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    char *str = convert_to_string(num, 16, 0);
                    if (!str)
                        return (-1);
                    while (*str)
                        buffer[buffer_index++] = *str++;
                    break;
                }
                case 'X':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    char *str = convert_to_string(num, 16, 1);
                    if (!str)
                        return (-1);
                    while (*str)
                        buffer[buffer_index++] = *str++;
                    break;
                }
                default:
                    buffer[buffer_index++] = '%';
                    buffer[buffer_index++] = *p;
                    break;
            }
        }
        else
        {
            buffer[buffer_index++] = *p;
        }

        if (buffer_index >= BUFFER_SIZE - 1)
        {
            write(1, buffer, buffer_index);
            count += buffer_index;
            buffer_index = 0;
        }
    }

    if (buffer_index > 0)
    {
        write(1, buffer, buffer_index);
        count += buffer_index;
    }

    va_end(args);
    return (count);
}

/**
 * convert_to_string - Converts an unsigned integer to a string
 * @num: The unsigned integer to convert
 * @base: The base to convert the integer to
 * @uppercase: Flag indicating if the conversion is for uppercase hex
 *
 * Return: A pointer to the converted string
 */
char *convert_to_string(unsigned int num, int base, int uppercase)
{
    static char buffer[50];
    char *ptr = &buffer[49];
    char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    *ptr = '\0';

    if (num == 0)
    {
        *--ptr = '0';
        return (ptr);
    }

    while (num != 0)
    {
        *--ptr = digits[num % base];
        num /= base;
    }

    return (ptr);
}

/**
 * convert_non_printable - Converts non-printable characters to \xHH format
 * @c: The non-printable character
 * @buffer: The buffer to write the converted string
 * @index: The current index in the buffer
 */
void convert_non_printable(char c, char *buffer, int *index)
{
    const char *hex_digits = "0123456789ABCDEF";
    buffer[(*index)++] = '\\';
    buffer[(*index)++] = 'x';
    buffer[(*index)++] = hex_digits[(c >> 4) & 0xF];
    buffer[(*index)++] = hex_digits[c & 0xF];
}

/**
 * convert_pointer_to_string - Converts a pointer to a string
 * @ptr: The pointer to convert
 *
 * Return: A pointer to the converted string
 */
char *convert_pointer_to_string(void *ptr)
{
    static char buffer[50];
    unsigned long addr = (unsigned long)ptr;
    char *digits = "0123456789abcdef";
    char *ptr_str = &buffer[49];

    *ptr_str = '\0';

    if (addr == 0)
    {
        *--ptr_str = '0';
        *--ptr_str = 'x';
        *--ptr_str = '0';
        return (ptr_str);
    }

    while (addr != 0)
    {
        *--ptr_str = digits[addr % 16];
        addr /= 16;
    }

    *--ptr_str = 'x';
    *--ptr_str = '0';

    return (ptr_str);
}

