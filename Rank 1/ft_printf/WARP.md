# WARP.md

This file provides guidance to WARP (warp.dev) when working with code in this repository.

## Key Commands

### Top-level ft_printf library

- Build the `libftprintf.a` static library (default target):
  - `make`
  - `make all`
- Clean object files:
  - `make clean`
- Remove objects and the `libftprintf.a` archive, then rebuild:
  - `make fclean`
  - `make re`

The top-level `Makefile` compiles:
- Core `ft_printf` implementation and helpers (`ft_printf.c`, `ft_putnbr.c`, `ft_putu.c`, `ft_putstr.c`, `ft_printhex.c`, pointer helpers, character helpers).
- Selected `LibFT` functions directly (`LibFT/ft_putchar_fd.c`, `LibFT/ft_strlen.c`) into `libftprintf.a`.

To use this library in a small test program (e.g. `main.c` you create yourself):

```bash
cc main.c -L. -lftprintf -o test_ftprintf
./test_ftprintf
```

### LibFT sublibrary

The `LibFT/` directory is a standalone 42-style libft project with its own `Makefile` that builds `libft.a`.

Common commands from inside `LibFT/` (or with `-C LibFT`):
- Build `libft.a`:
  - `make -C LibFT`
- Clean objects:
  - `make clean -C LibFT`
- Remove objects and archive:
  - `make fclean -C LibFT`
- Full rebuild:
  - `make re -C LibFT`

## High-level Architecture

### Overall layout

- Root library: `libftprintf.a` implements a subset of `printf`-style formatted output.
- Public header: `ft_printf.h` declares the main entry point `ft_printf` and helper functions for each supported conversion.
- Helper source files in the root directory provide printing for different value types:
  - `ft_putstr.c` – prints C strings, handling `NULL` specially (`"(null)"`) and using `ft_strlen` from `LibFT`.
  - `ft_putnbr.c` – prints signed decimal integers with recursive decomposition and explicit handling of `INT_MIN`.
  - `ft_putu.c` – prints unsigned decimal integers recursively.
  - `ft_printhex.c` – prints unsigned integers in hexadecimal using a base string and a small stack buffer for digits.
  - `ft_printptr.c` – prints pointers in `0x...` form, using internal helpers to traverse digits and `ft_putchar_fd` from `LibFT`.
- The `LibFT/` directory contains a full libft implementation (character classification, memory, string utilities, split/join, itoa, etc.), exposed via `LibFT/libft.h`.

### ft_printf flow

- `ft_printf.c` defines the core entry point and a static `formats` dispatcher:
  - `ft_printf(const char *str, ...)` initializes a `va_list`, iterates over the format string, and accumulates the total number of characters written.
  - When it encounters `%`, it advances the format pointer and delegates to `formats` to handle the specific specifier.
- The `formats` function maps conversion specifiers to helper functions, each returning the count of characters printed:
  - `%c` → character helper (single character output).
  - `%s` → `ft_putstr`.
  - `%p` → `ft_printptr` (pointer in hexadecimal with `0x` prefix).
  - `%d` / `%i` → `ft_putnbr` (signed decimal).
  - `%u` → `ft_putu` (unsigned decimal).
  - `%x` / `%X` → `ft_printhex` with the appropriate lowercase/uppercase base string.
  - `%%` → prints a literal `%`.
- Each helper is responsible for writing directly to file descriptor 1 (stdout) and returning the number of bytes written so that `ft_printf` can compute the total return value.

### Dependency structure

- `ft_printf.h` includes standard C headers (`stdlib.h`, `unistd.h`, `stdarg.h`, `stdio.h`) and `./LibFT/libft.h`, making libft utilities available to all helpers.
- `ft_printf.c` also includes `LibFT/libft.h` explicitly and relies on:
  - `ft_strlen` (string length) for format string handling.
  - Character and string output from helpers that ultimately call `write` or `LibFT`’s `ft_putchar_fd`.
- The top-level `Makefile` compiles only a subset of `LibFT` directly into `libftprintf.a`; the full `LibFT` library is available if needed via its own `Makefile` but is not required to link basic `ft_printf` usage.

### Testing and examples

- There is no dedicated tests directory or test runner configured in this repository.
- To exercise behavior, create your own `main.c` in the root (or elsewhere), include `ft_printf.h`, and link against `libftprintf.a` using the commands above.
