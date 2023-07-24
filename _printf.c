#include "main.h"

/**
 * _printf - a function that produces output according to a format
 *
 * @format: format for the output
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
    int my_printf_return = 0;
    va_list myargs;
    char c;
    char *s;

    va_start(myargs, format);

    for (; *format != '\0'; format++)
    {
        if (*format != '%')
        {
            my_putchar(*format);
            my_printf_return++;
        }
        else
        {
            format++;
            switch (*format)
            {
            case 'c':
                c = va_arg(myargs, int);
                my_putchar(c);
                my_printf_return++;
                break;
            case 's':
                s = va_arg(myargs, char *);
                if (s)
                {
                    int len = dee_puts(s);
                    my_printf_return += len;
                }
                break;
            case '%':
                my_putchar('%');
                my_printf_return++;
                break;
            default:
                my_putchar('%');
                my_putchar(*format);
                my_printf_return += 2;
                break;
            }
        }
    }

    va_end(myargs);
    return my_printf_return;
}

