#include "main.h"

/**
 * str_print - Printing a string
 * @k: variable argument
 * @s: structure flags
 * Return: charaters printed
 */

int str_print(va_list k, fmtflags_t *s)
{
	char *b = va_arg(k, char *);

	(void)s;

	if (!b)
		b = "(null)";
	return (_puts(b));
}

/**
 * char_print - Printing a character
 * @k: variable argument
 * @s: structure flags
 * Return: characters printed
 */

int char_print(va_list k, fmtflags_t *s)
{
	(void)s;
	_putchar(va_arg(k, int));
	return (1);
}

/**
 * _putchar - Writing the character cto stdout
 * @c: character that will be printed
 * Return: it will be 1
 */

int _putchar(char c)
{
	static char buf[1024];
	static int a;

	if (c == -1 || a >= 1024)
	{
		write(1, &buf, a);
		a = 0;
	}
	if (c != -1)
	{
		buf[a] = c;
		a++;
	}
	return (1);
}

/**
 * _puts - Printing a string to stdout
 * @str: string to print
 * Return: characters written
 */

int _puts(char *str)
{
	register int a;

	for (a = 0 ; str[a] != '\0' ; a++)
		_putchar(str[a]);

	return (a);
}

/**
 * rot13_print - Printing a string using rot13
 * @k: variable argument
 * @s: structure flags
 * Return: the length of printed string
 */

int rot13_print(va_list k, fmtflags_t *s)
{
	int a, d;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *b = va_arg(k, char *);

	(void)s;

	for (d = 0; b[d]; d++)
	{
		if (b[d] < 'A' || (b[d] > 'Z' && b[d] < 'a') || b[d] > 'z')
			_putchar(b[d]);
		else
		{
			for (a = 0 ; a <= 52 ; a++)
			{
				if (b[d] == rot13[a])
					_putchar(ROT13[a]);
			}
		}
	}
	return (d);

}

