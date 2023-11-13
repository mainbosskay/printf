#include "main.h"

/**
 * _printf - Printing formatted output
 * @format: pointer containing characters
 * @...: list for more arguments
 * Return: total characters printed
 */

int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, fmtflags_t *);
	const char *b;
	va_list ags;
	fmtflags_t fmtflags = {0, 0, 0, 0, 0};

	int sum = 0;

	va_start(ags, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (b = format ; *b ; b++)
	{
		if (*b == '%')
		{
			b++;
			if (*b == '%')
			{
				sum += _putchar('%');
				continue;
			}
			while (handle_flag(*b, &fmtflags))
				b++;
			pfunc = handle_print(*b);
			sum += (pfunc)
				? pfunc(ags, &fmtflags)
				: _printf("%%%c", *b);
		}
		else
			sum += _putchar(*b);
	}
	_putchar(-1);
	va_end(ags);
	return (sum);
}
