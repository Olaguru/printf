#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

/**
 * struct char_func - structure for specifier and matching function
 * @c: character
 * @ptr: function pointer
*/
typedef struct char_func
{
	char *c;
	int (*ptr)(va_list);
} cf_t;

int _printf(const char *format, ...);
int match_spec(char, va_list);
int _strlen(char *s);


/* in write_functions.c file */
int print_int(va_list);
int print_string(va_list);
int print_char(va_list);
int _putchar(char);
int _puts(char *str);

/* in specifiers.c file */
int to_binary(va_list);
int print_unsigned_int(va_list);
int print_unsigned_oct(va_list);
int print_adress(va_list);
int hex_lower(va_list);
int hex_UPPER(va_list);

/* in functions.c */
int print_hex(unsigned int, int);
int print_address(va_list ptr);
int np_characters(va_list str);
int rot13(va_list);
int reverse_string(va_list);

#endif
