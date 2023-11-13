#include "main.h"

/**
 * integer_print - Printing an integer
 * @k: variable argument
 * @s: flags structure
 * Return: characters printed
 */

int integer_print(va_list k, fmtflags_t *s)
{
	int a = va_arg(k, int);

	int result = num_count(a);

	if (s->space == 1 && s->plus == 0 && a >= 0 && s->zero == 1 && s->minus != 1)
		result += _putchar(' ');
	if (s->plus == 1 && a >= 0 && s->zero == 1 && s->minus != 1)
		result += _putchar('+');
	if (a <= 0 && s->zero == 1 && s->minus != 1)
		result++;
	num_print(a);
	return (result);
}

/**
 * num_print - looping an integer and printing all digits
 * @a: integer
 * Return: it is void
 */

void num_print(int a)
{
	unsigned int b;

	if (a < 0)
	{
		_putchar('-');
		b = -a;
	}
	else
		b = a;
	if (b / 10)
		num_print(b / 10);
	_putchar((b % 10) + '0');
}

/**
 * unsigned_int_print - Printing unsigned int
 * @k: variable argument
 * @s: structure flags
 * Return: characters printed
 */

int unsigned_int_print(va_list k, fmtflags_t *s)
{
	unsigned int ui = va_arg(k, unsigned int);
	char *string = _sprintf(ui, 10, 0);

	(void)s;
	return (_puts(string));
}

/**
 * num_count - Number of digits in an integer
 * @c: Integer
 * Return: number of digits
 */

int num_count(int c)
{
	unsigned int t = 0;
	unsigned int ui;

	if (c < 0)
		ui = c * -1;
	else
		ui = c;
	while (ui != 0)
	{
		ui /= 10;
		t++;
	}
	return (t);
}

