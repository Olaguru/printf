# Our printf () function

### Authors
1. Idrees Oladimeji
2. Naheemah Bello

## Description

The format string is a character string, is composed
of zero or more directives

### Usage
like the according main.h library version:

int _printf(const char *format, ...);


## Format Specifiers

A format specifier follows this prototype: `%type`
The following format specifiers are supported:

### Supported Types

* Type   * Output 
|--------|--------|
| d or i | Signed decimal integer |
| u      | Unsigned decimal integer	|
| b      | Unsigned binary |
| o      | Unsigned octal |
| x      | Unsigned hexadecimal integer (lowercase) |
| X      | Unsigned hexadecimal integer (uppercase) |
| c      | Single character |
| s      | String of characters |
| p      | Pointer address |
| %      | A % followed by another % character will write a single % |

### Value Return 
Upon successful return, all functions return the number of characters written, _excluding_ the terminating null character used to end the string. If any error is encountered, `-1` is returned.

## Examples
```c
#include "main.h"

int main()
{
	_printf("Hello world, I'm a %s", "Bello");
	return (0);
}
```
`Hello world, I'm a Bello`

```c
#include "main.h"

int main()
{
	_printf("%S\n", "Best\nSchool!");
	return (0);
}
```
`Best\x0ASchool!`

```c
int _printf(const char *restrict format, ...);
```
