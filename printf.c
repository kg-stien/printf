#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Print to stdout, standard output stream.
 * @format: A character string. 
 *
 * Description: The format string is composed of zero or more directives.
 * Handle the following conversion specifers: c, s, %
 * Return: The number of characters printed (excluding the null byte
 * used to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i, j;
	char *str, ch;

	va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		/* if there is % */
		if (format[i] == '%')
		{
			switch (*++format)
			{
				case 's':
					str = va_arg(ap, char *);
					for (j = 0; str[j] != '\0'; j++)
						_write(str[j]);
					break;
				case 'c':
					ch = va_arg(ap, int);
					_write(ch);
					break;
				default:
					_write(*format);
					break;
			}
		}	
		if (format[i] != '%')
		{
			_write(format[i]);
			continue;
		}
	}

	va_end(ap);
	return (*format);
}
