#include "main.h"

/**
 * reverse_str - Printing a string in reverse
 * @k: variable argument
 * @s: structure flags
 * Return: the lengthof printed string
 */

int reverse_str(va_list k, fmtflags_t *s)
{
	int a = 0;
	int d;
	char *b = va_arg(k, char *);

	(void)s;
	if (b == NULL)
		b = "(null)";

	while (b[a])
		a++;
	for (d = a - 1 ; d >= 0 ; d--)
		_putchar(b[d]);
	return (a);
}

/**
 * nonprint_char - Printing non printable characters
 * @k: variable argument
 * @s: structure flags
 * Return: characters
 */

int nonprint_char(va_list k, fmtflags_t *s)
{
	int a;
	int sum = 0;
	char *j;
	char *b = va_arg(k, char *);

	(void)s;
	if (b == NULL)
		return (_puts("(null)"));

	for (a = 0 ; b[a] ; a++)
	{
		if (b[a] > 0 && (b[a] < 32 || b[a] >= 127))
		{
			_puts("\\x");
			sum += 2;
			j = _sprintf(b[a], 16, 0);
			if (!j[1])
				sum += _putchar('0');
			sum += _puts(j);
		}
		else
			sum += _putchar(b[a]);
	}
	return (sum);
}

/**
 * pointer_print - Printing memory address
 * @k: variable argument
 * @s: structure flags
 * Return: characters printed
 */

int pointer_print(va_list k, fmtflags_t *s)
{
	char *b;
	unsigned long int ui = va_arg(k, unsigned long int);
	int sum = 0;

	(void)s;
	if (!ui)
		return (_puts("(nil)"));
	b = _sprintf(ui, 16, 1);
	sum = sum + _puts("0x");
	sum = sum + _puts(b);
	return (sum);
}

/**
 * percent_print - Printing the percent sign
 * @k: variable argument
 * @s: structure flags
 * Return: characters printed
 */

int percent_print(va_list k, fmtflags_t *s)
{
	(void)k;
	(void)s;

	return (_putchar('%'));
}

