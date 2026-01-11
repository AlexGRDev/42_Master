*This project has been created as part of the 42 curriculum by agarcia2.*

# ft_printf

## Description
This project consists of recreating the standard C library function `printf`.
The goal is to build a static library, `libftprintf.a`, containing a function
`ft_printf()` that mimics the behavior of the original `printf` for a defined
set of format specifiers.

This project introduces the use of variadic functions in C and focuses on
string parsing, formatted output, and modular code design.
Once completed, `ft_printf` can be integrated into `libft` and reused in future
C projects at 42.

---

## Instructions

### Compilation
The project includes a `Makefile` with the mandatory rules:

```bash
make        # Compiles the library libftprintf.a
make clean  # Removes object files
make fclean # Removes object files and the library
make re     # Recompiles the project
```

Compilation is done using:
```
cc -Wall -Wextra -Werror
```

### Usage
Include the header file in your source code:
```c
#include "ft_printf.h"
```

Compile your program with the library:
```bash
cc main.c libftprintf.a
```

Example:
```c

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int	main(int argc, char **argv)
{
	int	ret_ft;
	int	ret_pf;

	ft_printf("+============================+\n");
	ft_printf("| FT_PRINTF TEST BY agarcia2 |\n");
	ft_printf("+============================+\n\n");

	if (argc != 2)
	{
		ft_printf("Usage: ./ft_printf <string>\n");
		return (1);
	}

	ft_printf("+===========+\n");
	ft_printf("| CHAR TEST |\n");
	ft_printf("+===========+\n");
	ret_ft = ft_printf("ft_printf: %c\n", 'A');
	ret_pf = printf("printf   : %c\n", 'A');
	ft_printf("ret ft: %d | ret printf: %d\n\n", ret_ft, ret_pf);

	ft_printf("+=============+\n");
	ft_printf("| STRING TEST |\n");
	ft_printf("+=============+\n");
	ret_ft = ft_printf("ft_printf: %s\n", argv[1]);
	ret_pf = printf("printf   : %s\n", argv[1]);
	ft_printf("ret ft: %d | ret printf: %d\n\n", ret_ft, ret_pf);

	ret_ft = ft_printf("ft_printf NULL: %s\n", (char *)NULL);
	ret_pf = printf("printf   NULL: %s\n", (char *)NULL);
	ft_printf("ret ft: %d | ret printf: %d\n\n", ret_ft, ret_pf);
	
	ft_printf("+=============+\n");
	ft_printf("| INT / DIGIT |\n");
	ft_printf("+=============+\n");
	ret_ft = ft_printf("ft_printf: %d %i\n", INT_MAX, INT_MIN);
	ret_pf = printf("printf   : %d %li\n", INT_MAX, INT_MIN);
	ft_printf("ret ft: %d | ret printf: %d\n\n", ret_ft, ret_pf);

	ft_printf("+===============+\n");
	ft_printf("| UNSIGNED TEST |\n");
	ft_printf("+===============+\n");
	ret_ft = ft_printf("ft_printf: %u\n", -1);
	ret_pf = printf("printf   : %u\n", -1);
	ft_printf("ret ft: %d | ret printf: %d\n\n", ret_ft, ret_pf);
	
	ft_printf("+==========+\n");
	ft_printf("| HEX TEST |\n");
	ft_printf("+==========+\n");
	ret_ft = ft_printf("ft_printf: %x %X\n", 3735928559u, 3735928559u);
	ret_pf = printf("printf   : %x %X\n", 3735928559u, 3735928559u);
	ft_printf("ret ft: %d | ret printf: %d\n\n", ret_ft, ret_pf);
	
	ft_printf("+==============+\n");
	ft_printf("| POINTER TEST |\n");
	ft_printf("+==============+\n");
	ret_ft = ft_printf("ft_printf: %p\n", argv);
	ret_pf = printf("printf   : %p\n", argv);
	ft_printf("ret ft: %d | ret printf: %d\n\n", ret_ft, ret_pf);

	ret_ft = ft_printf("ft_printf NULL: %p\n", NULL);
	ret_pf = printf("printf   NULL: %p\n", NULL);
	ft_printf("ret ft: %d | ret printf: %d\n\n", ret_ft, ret_pf);

	ft_printf("+==============+\n");
	ft_printf("| PERCENT TEST |\n");
	ft_printf("+==============+\n");
	ret_ft = ft_printf("ft_printf: %%\n");
	ret_pf = printf("printf   : %%\n");
	ft_printf("ret ft: %d | ret printf: %d\n\n", ret_ft, ret_pf);

	ft_printf("+====================+\n");
	ft_printf("| END OF TEST SUITE |\n");
	ft_printf("+====================+\n");
	
	return (0);
}
```

---

## Supported Conversions
The `ft_printf` function supports the following format specifiers:

- `%c` : prints a single character
- `%s` : prints a string
- `%p` : prints a pointer address in hexadecimal format
- `%d` : prints a signed decimal number
- `%i` : prints an integer in base 10
- `%u` : prints an unsigned decimal number
- `%x` : prints a hexadecimal number (lowercase)
- `%X` : prints a hexadecimal number (uppercase)
- `%%` : prints a percent sign

---

## Algorithm and Data Structures

### Format Parsing
The function iterates through the format string character by character.

- If the current character is not `%`, it is written directly to standard output.
- When `%` is encountered, the following character is interpreted as a conversion specifier.

### Variadic Arguments
The project uses `<stdarg.h>` to handle a variable number of arguments:
- `va_start` initializes argument processing.
- `va_arg` retrieves each argument according to the detected format.
- `va_end` cleans up once processing is finished.

### Conversion Handling
Each format specifier is handled by a dedicated function, improving readability
and maintainability.
Numeric values are converted using base-specific logic (base 10 or base 16),
and characters are written using the `write()` system call.

### Pointer Formatting
Pointers are printed by:
1. Writing the `"0x"` prefix.
2. Converting the address to a lowercase hexadecimal representation.

### Design Choices
- No buffer management is implemented, as required by the subject.
- The code is modular to allow easy extension (bonus part).
- No unnecessary dynamic memory allocation is used.
- All outputs are written directly to file descriptor `1`.

---

## Resources

### References
- `man 3 printf`
- `man stdarg`
- The C Programming Language – Kernighan & Ritchie
- 42 subject PDF: **ft_printf (version 12.0)**

### AI Usage
AI tools were used exclusively for:
- Understanding and summarizing the project requirements.
- Structuring the  project directory.

AI was **not** used to generate source code, implement algorithms, or debug the
project logic, in accordance with the 42 AI usage guidelines.

---

## Bonus
If implemented, the bonus part extends `ft_printf` with:
- Flags: `-`, `0`, `.`, and minimum field width
- Flags: `#`, `+`, and space

The bonus is evaluated only if the mandatory part is fully correct.

---

## Project Output
The final output of this project is the static library:

```
libftprintf.a
```

located at the root of the repository.

