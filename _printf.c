#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - function that prints the same as printf in standard lib
 * @format: input of the function
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list va;
	int prChar = 0;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(va, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			prChar++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}

			if (*format == '%')
			{
				write(1, format, 1);
				prChar++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(va, int);

				write(1, &c, 1);
				prChar++;
			}
			else if (*format == 's')
			{
				char *stg = va_arg(va, char *);
				int strLen = 0;

				while (stg[strLen] != '\0')
				{
					strLen++;
				}
				write(1, stg, strLen);
				prChar += strLen;
			}
			else if(*format == 'd' || *format == 'i')
			{
				int num = va_arg(va, int);
				char numStr[12];

				int numLen = sprintf(numStr, "%d", num);
				write(1, numStr, numLen);
				prChar += numLen;
			}
		}

		format++;
	}
	va_end(va);
	return (prChar);
}
