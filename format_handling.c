#include "main.h"

/**
 * handle_print - Right printing function
 * @b: conversion specifier
 * Return: pointer to the matching print function
 */

int (*handle_print(char b))(va_list, fmtflags_t *)
{
	fmtprint_h func_arr[] = {
		{'i', integer_print},
		{'s', str_print},
		{'c', char_print},
		{'d', integer_print},
		{'u', unsigned_int_print},
		{'x', print_hex_lower},
		{'X', print_hex_upper},
		{'b', print_base_two},
		{'o', print_base_eight},
		{'%', percent_print},
		{'p', pointer_print},
		{'S', nonprint_char},
		{'r', reverse_str},
		{'R', rot13_print}
	};
	int fmtflags = 14;

	int a;

	for (a = 0 ; a < fmtflags ; a++)
		if (func_arr[a].c == b)
			return (func_arr[a].s);
	return (NULL);
}

/**
 * handle_flag - non-custom specifiers
 * @b: character holding flag specifier
 * @s: structure flags
 * Return: it is 1
 */

int handle_flag(char b, fmtflags_t *s)
{
	int j = 0;

	switch (b)
	{
		case '+':
			s->plus = 1;
			j = 1;
			break;
		case ' ':
			s->space = 1;
			j = 1;
			break;
		case '#':
			s->hash = 1;
			j = 1;
			break;
		case '-':
			s->minus = 1;
			j = 1;
			break;
		case '0':
			s->zero = 1;
			j = 1;
			break;
	}
	return (j);
}

