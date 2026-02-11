*This project has been created as part of the 42 curriculum by agarcia2.*

# Rank 0 — First Steps in C

## Description

Rank 0 marks the beginning of the 42 Common Core.
Its only mandatory project is **Libft**, a reimplementation of essential C standard library functions and additional utilities reused across future projects.

The rank provides the foundations for pointers, memory management, static libraries, and clean coding under the Norm.

---

# How to Use This Rank

Rank 0 contains one main directory:

```
Rank 0/
└── LibFT/
```

Inside it you will find:
- A complete README with build/run instructions
- All required `.c` and `.h` files
- The mandatory Makefile that builds `libft.a`

It is recommended to keep the official subject PDF open during development.

---

# Project Overview

| Project | Description | Language | Status |
|--------|-------------|----------|--------|
| Libft | Reimplementation of core libc functions and additional utilities as a static library. | C | Completed |

---

# What You Do in Libft

### Character checks
ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint

### Memory functions
ft_memset, ft_bzero, ft_memcpy, ft_memmove, ft_memchr, ft_memcmp, ft_calloc

### String functions
ft_strlen, ft_strdup, ft_strlcpy, ft_strlcat, ft_strchr, ft_strrchr, ft_strncmp, ft_strnstr, ft_atoi

### Additional utilities
ft_substr, ft_strjoin, ft_strtrim, ft_split, ft_itoa

### Functional tools
ft_strmapi, ft_striteri

### File descriptor output
ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd

### Linked list utilities
ft_lstnew, ft_lstadd_front, ft_lstsize, ft_lstlast, ft_lstadd_back,
ft_lstdelone, ft_lstclear, ft_lstiter, ft_lstmap

---

# Checklist Before Submitting

- Makefile builds `libft.a`
- Compiles with `-Wall -Wextra -Werror` and no warnings
- No forbidden functions used
- No memory leaks
- No global variables
- Bonus files end in `_bonus.c`

---

# Compilation

```bash
make
make clean
make fclean
make re
```

To link:

```bash
cc main.c libft.a -o program
```

---

# What You Learn in Rank 0

- Pointers, arrays, memory and strings
- How static libraries work
- Clean multi‑file project structure
- Using and writing a Makefile
- Memory safety and debugging with Valgrind
- Norminette discipline

---

# Common Pitfalls

- Forgetting to free allocations in `ft_split`
- Incorrect NULL handling
- Using glibc vs BSD variants of strlcpy/strlcat incorrectly
- Makefile relinks or does not produce libft.a
- Submitting unused files

---

# Resources

- C manual pages
- Standard library documentation
- libft subject PDF

---

# AI Usage Statement

AI was used exclusively for documentation formatting and improving clarity.
All reasoning, implementation, debugging and testing were performed manually.

---
