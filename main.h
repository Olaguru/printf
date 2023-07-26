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
} cf;

int _printf(const char *format, ...);
int spec_match(char, va_list);
int stringlen(char *string);


/* in write_functions.c file */
int _printint(va_list);
int string_printer(va_list);
int print_character(va_list);
int my_putchar(char);
int dee_puts(char *str);

/* in specifiers.c file */
int to_binary(va_list);
int print_unsigned_int(va_list);
int print_unsigned_oct(va_list);
int print_adress(va_list);
int hex_lower(va_list);
int hex_UPPER(va_list);

int print_address_me(va_list ptr);
int print_hexadecimal(unsigned int, int);
int characters_np(va_list str);
int 13rot(va_list);
int rev_string(va_list);

#endif
