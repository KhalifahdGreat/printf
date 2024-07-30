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
                    char *str = convert_to_string(num, 10);
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
 * convert_to_string - Converts an integer to a string
 * @num: The integer to convert
 * @base: The base to convert the integer to
 *
 * Return: A pointer to the converted string
 */
char *convert_to_string(int num, int base)
{
    static char buffer[50];
    char *ptr = &buffer[49];
    int is_negative = 0;

    *ptr = '\0';

    if (num == 0)
    {
        *--ptr = '0';
        return (ptr);
    }

    if (num < 0 && base == 10)
    {
        is_negative = 1;
        num = -num;
    }

    while (num != 0)
    {
        int rem = num % base;
        *--ptr = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num /= base;
    }

    if (is_negative)
        *--ptr = '-';

    return (ptr);
}

