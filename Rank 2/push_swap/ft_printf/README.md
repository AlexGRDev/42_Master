# 🖨️ ft_printf — Reimplementation of printf (Rank 1)

> **Rank 1** project in 42: re‑implement a reduced version of `printf` in C.  
> This guide is for students facing the project for the first time.

---

## 👤 Who is this README for?

- Students doing **ft_printf** for the first time in Rank 1.  
- Anyone who wants a **quick overview** of what the project expects before diving into the subject.  
- People who already passed ft_printf and want a **summary of the key ideas**.

---

## 🗺️ How to use this project

- Read this README together with the **official ft_printf subject**.  
- Use it to understand what is being evaluated, which specifiers you need, and how to structure your code.  
- Come back to the testing section when you are close to submitting, to double‑check your coverage.

---

## 🎯 What this project evaluates

In `ft_printf` you will mainly work on:

- Using **variadic functions** (`va_list`, `va_start`, `va_arg`, `va_end`).
- Organizing a project into **multiple .c files** with a single `ft_printf.c` as the main entry point.
- Handling **format specifiers** and different types (`char`, `string`, integers, hex, pointers).
- Being careful with the **return value**: you must return the exact number of printed characters.
- Strictly following the **subject constraints** (allowed functions, use of `write`, etc.).

---

## 🧩 Required format specifiers

Typically, the 42 subject asks for at least these formats (double‑check your PDF in case it changes):

- `%c` → a single character.
- `%s` → a string (`char *`).
- `%p` → a pointer printed in hexadecimal with `0x` prefix.
- `%d` / `%i` → signed decimal integer.
- `%u` → unsigned decimal integer.
- `%x` / `%X` → hexadecimal integer (lowercase / uppercase).
- `%%` → prints a literal `%`.

A good strategy is to have **one helper function per type** (`ft_putstr`, `ft_putnbr`, `ft_printhex`, `ft_printptr`, etc.) and a small dispatcher function that decides which one to call based on the format character.

---

## 🚀 How to start the project

1. **Read the whole subject** and highlight:
   - List of required format specifiers.
   - Allowed/forbidden functions.
   - Rules about the return value.
2. Design a minimal structure:
   - `ft_printf.c` with the main loop over the format string.
   - A `formats` (or similar) function that, given a char (`c`, `s`, `d`, etc.), calls the right helper.
   - Helpers split into different files (`ft_putnbr.c`, `ft_printhex.c`, ...).
3. Start with **simple cases** (`%c`, `%%`, `%s`) before moving to integers and pointers.
4. Create your own `main.c` that always compares your function with the real `printf`.

---

## 🛠️ Basic Makefile commands

### Top-level ft_printf library

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

- Create several small `main.c` files that compare your `ft_printf` with the real `printf` for different formats and edge cases.
- Do not stop at the subject examples: test empty strings, `NULL`, negative values, `0`, maximum and minimum values, etc.
- For the oral defense, have a small `main.c` ready that shows **several formats in a single call** and how you handle the return value.
