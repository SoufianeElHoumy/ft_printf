*This project has been created as part of the 42 curriculum by soel-hou.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the C standard library function `printf`.
The goal of the project is to learn how variadic functions work in C (`<stdarg.h>`),
how to parse a format string, and how to build a small, clean, reusable library
(`libftprintf.a`) without using the original `printf` family.

The function has the following prototype:

```c
int ft_printf(const char *format, ...);
```

It writes the formatted output to the standard output and returns the number of
characters printed (or `-1` on error).

### Supported conversions

| Specifier | Description                                          |
|-----------|------------------------------------------------------|
| `%c`      | A single character                                   |
| `%s`      | A string (prints `(null)` if the pointer is `NULL`)  |
| `%p`      | A pointer in hexadecimal (`(nil)` if `NULL`)         |
| `%d`      | A signed decimal integer                             |
| `%i`      | A signed decimal integer                             |
| `%u`      | An unsigned decimal integer                          |
| `%x`      | An unsigned integer in lowercase hexadecimal         |
| `%X`      | An unsigned integer in uppercase hexadecimal         |
| `%%`      | A literal percent sign                               |

### Project structure

| File           | Role                                                                 |
|----------------|----------------------------------------------------------------------|
| `ft_printf.c`  | Main function: reads the format string and dispatches conversions    |
| `ft_printf.h`  | Prototypes and includes                                              |
| helper `.c` files | `ft_putchar`, `ft_putstr`, `ft_putnbr`, `ft_puthex`, `ft_putptr`  |
| `Makefile`     | Builds `libftprintf.a`                                               |

## Instructions

### Compilation

From the root of the repository:

```bash
make
```

This produces the static library `libftprintf.a`. Other rules:

```bash
make clean    # remove object files
make fclean   # remove object files and libftprintf.a
make re       # fclean + make
```

### Usage

Include the header in your code and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
	int	len;

	len = ft_printf("Hello %s, you are %d years old! (%x)\n", "42", 7, 255);
	ft_printf("Printed %d characters\n", len);
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
./test
```

Expected output:

```
Hello 42, you are 7 years old! (ff)
Printed 36 characters
```

## Algorithm and data structure

### Algorithm

`ft_printf` uses a **single left-to-right pass** over the format string:

1. Walk through `format` one character at a time.
2. If the character is not `%`, write it directly and add 1 to the counter.
3. If it is `%`, read the next character (the specifier) and call
   `check_format`, which dispatches to the right helper function.
4. If the format string ends right after a `%`, the loop stops.
5. When the end of the string is reached, return the counter.

**Why this approach?** The mandatory part does not need flags, width, or
precision, so the specifier is always exactly one character after `%`. A simple
linear scan is the easiest to read and to maintain. It runs in O(n) time over
the length of the format string, uses no dynamic memory allocation, and
therefore cannot leak.

### Number conversion

Numbers are printed **recursively**: each function divides the number by its
base (10 for `ft_putnbr`, 16 for `ft_puthex` and `ft_putptr`), prints the
higher digits first through the recursive call, then prints the current digit.
For hexadecimal, the digit is taken from a base string
(`"0123456789abcdef"` or `"0123456789ABCDEF"`).

**Why this approach?** Recursion produces the digits in the correct order
without a temporary buffer. Passing the base string as a parameter lets
`ft_puthex` handle both `%x` and `%X`, and lets `ft_putptr` reuse the lowercase
base. `ft_putnbr` takes a `long`, so `%d`/`%i` (an `int`) and `%u` (an
`unsigned int`) both fit without overflow, and negating `INT_MIN` is safe.
`%x` and `%X` stay in `unsigned int`, and pointers are converted to
`unsigned long`, so no value is wrongly treated as negative.
Like glibc, `%s` with `NULL` prints `(null)` and `%p` with `NULL` prints `(nil)`.

### Data structure

No custom data structure is needed. The only state is:

- a `va_list` that gives access to the variable arguments,
- an `int` counter, passed by pointer to every helper, that accumulates the
  number of printed characters.

**Why this approach?** Passing the counter by pointer keeps every helper small
(one job each) and avoids global variables, which are forbidden by the Norm.

## Resources

### References

- `man 3 printf`, `man 3 stdarg`, `man 2 write`
- [GNU C Library manual: Variadic Functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
- [cppreference: `printf` format specifiers](https://en.cppreference.com/w/c/io/fprintf)
- [cppreference: `va_list`, `va_start`, `va_arg`, `va_end`](https://en.cppreference.com/w/c/variadic)