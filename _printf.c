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

