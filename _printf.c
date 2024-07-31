#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string composed of zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    int count = 0;
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
                    count += write(1, &c, 1);
                    break;
                }
                case 's':
                {
                    char *str = va_arg(args, char *);
                    if (!str)
                        str = "(null)";
                    while (*str)
                        count += write(1, str++, 1);
                    break;
                }
                case '%':
                    count += write(1, "%", 1);
                    break;
                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    char *str = convert_to_string(num, 10, 0);
                    if (!str)
                        return (-1);
                    while (*str)
                        count += write(1, str++, 1);
                    break;
                }
                case 'u':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    char *str = convert_to_string(num, 10, 0);
                    if (!str)
                        return (-1);
                    while (*str)
                        count += write(1, str++, 1);
                    break;
                }
                case 'o':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    char *str = convert_to_string(num, 8, 0);
                    if (!str)
                        return (-1);
                    while (*str)
                        count += write(1, str++, 1);
                    break;
                }
                case 'x':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    char *str = convert_to_string(num, 16, 0);
                    if (!str)
                        return (-1);
                    while (*str)
                        count += write(1, str++, 1);
                    break;
                }
                case 'X':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    char *str = convert_to_string(num, 16, 1);
                    if (!str)
                        return (-1);
                    while (*str)
                        count += write(1, str++, 1);
                    break;
                }
                default:
                    count += write(1, "%", 1);
                    count += write(1, p, 1);
                    break;
            }
        }
        else
        {
            count += write(1, p, 1);
        }
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

