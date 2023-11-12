#include "main.h"

/**
 * print_hex_lower - printing hexadecimal base number in lowercase
 * @k: variable argument
 * @s: structure flags
 * Return: characters printed
 */

int print_hex_lower(va_list k, fmtflags_t *s)
{
	unsigned int dgt = va_arg(k, unsigned int);
	char *string = _sprintf(dgt, 16, 1);
	int sum = 0;

	if (s->hash == 1 && string[0] != '0')
		sum += _puts(string);
	return (sum);
}

/**
 * print_hex_upper - printing hexadecimal base number
 * @k: variable argument
 * @s: structure flags
 * Return: characters printed
 */

int print_hex_upper(va_list k, fmtflags_t *s)
{
	unsigned int dgt = va_arg(k, unsigned int);
	char *string = _sprintf(dgt, 16, 0);
	int sum = 0;

	if (s->hash == 1 && string[0] != '0')
		sum += _puts("0X");
	sum += _puts(string);
	return (sum);
}

/**
 * print_base_two - printing a number in binary
 * @k: variable argument
 * @s: structure flags
 * Return: characters printed
 */

int print_base_two(va_list k, fmtflags_t *s)
{
	unsigned int dgt = va_arg(k, unsigned int);
	char *string = _sprintf(dgt, 2, 0);

	(void)s;
	return (_puts(string));
}

/**
 * print_base_eight - printing a number in base 8
 * @k: variable argument
 * @s: structure flags
 * Return: characters printed
 */

int print_base_eight(va_list k, fmtflags_t *s)
{
	unsigned int dgt = va_arg(k, unsigned int);
	char *string = _sprintf(dgt, 8, 0);
	int sum = 0;

	if (s->hash == 1 && string[0] != '0')
		sum += _putchar('0');
	sum += _puts(string);
	return (sum);
}

/**
 * _sprintf - converting number and base to string
 * @dgt: number
 * @base: base
 * @lowercase: flag if hexadecimal value need to be lowercase
 * Return: pointer
 */

char *_sprintf(unsigned long int dgt, int base, int lowercase)
{
	static char *represent;
	static char buffer[50];
	char *pointer;

	represent = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	pointer = &buffer[49];

	*pointer = '\0';

	do {
		*--pointer = represent[dgt % base];
		dgt /= base;
	} while (dgt != 0);
	return (pointer);
}
