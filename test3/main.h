#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <stdarg.h>

/**
* struct charfun - contains specifier and its corresponding func
* @specifier: The specifier character
* @ptr: the function pointer to the corresponding printing function
*/
typedef struct charfun
{
	char *specifier;
	int (*ptr)(va_list);
} specfunc;

int _printf(const char *format, ...);
int my_putchar(char);
int dee_puts(char *string);
int put_int(int num);
int spec_select(char sw, va_list myargs);


int _printchar(va_list c);
int _printstring(va_list strng);
#endif /* _MAIN_H_ */
