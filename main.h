#ifndef header
#define header
#include <stdlib.h>
#include <stdlib.h>
#include <stdarg.h>
/**
 * struct fmtflags - This structure contain flags
 * @space: ' ' character
 * @hash: '#' character
 * @plus: '+' character
 */
typedef struct fmtflags
{
	int space;
	int hash;
	int plus;
} fmtflags_t;

/**
 * struct fmtprint - Mapping format specifiers
 * @c: format specifier
 * @s: print function
 */
typedef struct fmtprint
{
	char c;
	int (*s)(va_list arg, fmtflags_t *s);
} fmtprint_h;
int integer_print (va_list k, fmtflags_t *s);
void num_print(int a);
int unsigned_int_print(va_list k, fmtflags_t *s);
int num_count(int c);
int print_hex_lower(va_list k, fmtflags_t *s);
int print_hex_upper(va_list k, fmtflags_t *s);
char *_sprintf(unsigned long int dgt, int base, int lowercase);
int _printf(const char *format, ...);
int (*handle_print(char b)) (va_list, fmtflags_t *s);
int_handle_flag(char b, fmtflags_t *s);
int str_print(va_list k, fmtflags_t *s);
int char_print(va_list k, fmtflags_t *s);
int _putchar(char c);
int _puts(char *str);
int rot13_print(va_list k, fmtflags_t *s);
int reverse_str(va_list k, fmtflags_t *s);
int nonprint_char(va_list k, fmtflags_t *s);
int pointer_print(va_list k, fmtflags_t *s);
int percent_print(va_list k, fmtflags_t *s);
#endif
