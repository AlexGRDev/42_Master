# 🧠 Libft — Custom C Standard Library

> 42 Barcelona — **Libft** project (Rank 0).  
> A small, self‑contained implementation of core C standard library functions plus extra utilities.

---

## 📚 Overview

This directory contains the **Libft** project, the first mandatory assignment in the 42 Common Core.  
The goal is to re‑implement part of the C standard library and a set of extra helpers that will be
reused in many later projects (`ft_printf`, `get_next_line`, `push_swap`, etc.).

Key ideas:

- Work directly with **pointers**, **arrays**, and **manual memory management**.
- Understand how common libc functions behave, including edge cases.
- Build a **static library** (`libft.a`) that you can link against from any C program.

---

## ⚙️ Build

From this `LibFT/` directory:

```bash
make            # Build libft.a
make clean      # Remove object files
make fclean     # Remove object files and libft.a
make re         # Full rebuild
```

The build uses `gcc` with:

- `-Wall -Wextra -Werror`

so the code must compile **without warnings**.

---

## 🧩 Contents

### Part 1 — libc reimplementation

Core functions that mirror the behavior of their standard C counterparts:

- Character checks: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- Case conversion: `ft_toupper`, `ft_tolower`
- String length: `ft_strlen`
- Memory: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
- Strings: `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`
- Conversion: `ft_atoi`

These functions are intended to behave like the original libc versions (undefined behavior
remains undefined, as in the real C library).

### Part 2 — Extra utilities

Higher‑level helpers commonly used across 42 projects:

- String allocation: `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`
- Functional-style string processing: `ft_strmapi`, `ft_striteri`
- File‑descriptor I/O: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

These are 42‑specific utilities, designed to be small, predictable building blocks for future work.

---

## 🧪 Testing & guarantees

- Part 1 functions have been **manually compared against the standard C library** (`strlen`, `memcmp`,
  `strncmp`, `strnstr`, `atoi`, etc.) on representative inputs.
- Edge cases:
  - `ft_itoa` handles **`INT_MIN`** safely by working internally with a `long`.
  - `ft_split` handles **empty strings**, strings with only delimiters, and allocation failures
    without leaking memory.
- All code is written to comply with **42 Norminette** constraints, including the
  **25‑line limit per function** (helpers are extracted when necessary).

Local ad‑hoc test programs were used during development but are not kept in the final repository
so the project tree stays clean for evaluation.

---

## 🔗 Using libft in another project

Example minimal usage from a separate C file:

```c
#include "LibFT/libft.h"

int main(void)
{
    char *s = ft_strdup("Hello from libft!\n");

    if (!s)
        return (1);
    ft_putstr_fd(s, 1);
    free(s);
    return (0);
}
```

Compile and link against `libft.a` (from the repository root, adjust paths as needed):

```bash
cc main.c LibFT/libft.a -o main
./main
```