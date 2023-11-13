#ifndef header
#define header

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct fmtflags - Structure containing flags
 * @plus: '+' character
 * @space: ' ' character
 * @hash: '#' character
 * @zero: '0' character
 * @minus: '-' character
 */

typedef struct fmtflags
{
	int plus;
	int space;
	int hash;
	int zero;
	int minus;
} fmtflags_t;

/**
 * struct fmtprint - Mapping format specifiers
 * @c: format specifier
 * @s: print function
 */

typedef struct fmtprint
{
	char c;
	int (*s)(va_list ag, fmtflags_t *s);
} fmtprint_h;

/* num_print.c */
int integer_print(va_list k, fmtflags_t *s);
void num_print(int a);
int unsigned_int_print(va_list k, fmtflags_t *s);
int num_count(int c);

/* num_conversion.c */
int print_hex_lower(va_list k, fmtflags_t *s);
int print_hex_upper(va_list k, fmtflags_t *s);
int print_base_two(va_list k, fmtflags_t *s);
int print_base_eight(va_list k, fmtflags_t *s);
char *_sprintf(unsigned long int dgt, int base, int lowercase);

/* _printf.c */
int _printf(const char *format, ...);

/* format_handling.c */
int (*handle_print(char b))(va_list, fmtflags_t *s);
int handle_flag(char b, fmtflags_t *s);

/* char_print.c */
int str_print(va_list k, fmtflags_t *s);
int char_print(va_list k, fmtflags_t *s);
int _putchar(char c);
int _puts(char *str);
int rot13_print(va_list k, fmtflags_t *s);

/* char_manip.c */
int reverse_str(va_list k, fmtflags_t *s);
int nonprint_char(va_list k, fmtflags_t *s);
int pointer_print(va_list k, fmtflags_t *s);
int percent_print(va_list k, fmtflags_t *s);

#endif

