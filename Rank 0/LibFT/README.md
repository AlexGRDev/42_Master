*This project has been created as part of the 42 curriculum by
agarcia2.*

# Libft

## Description

Libft is the first foundational project in the 42 curriculum.\
Its purpose is to reimplement essential functions from the C standard
library, as well as additional utilities that will be reused throughout
future projects.\
The goal is to build a robust understanding of memory management, string
manipulation, pointers, and low-level logic by recreating these tools
from scratch.

This repository contains the full implementation of the mandatory part
of the project, following all technical and Norm requirements.

------------------------------------------------------------------------

# Instructions

## Compilation

The project provides a `Makefile` with the mandatory rules:

-   `$(NAME)`
-   `all`
-   `clean`
-   `fclean`
-   `re`

The static library produced is:

    libft.a

All `.c` files must compile with the following flags:

    -Wall -Wextra -Werror

The use of `ar` is required for creating the library.\
The use of `libtool` is forbidden.

Global variables and unused files are not allowed.

------------------------------------------------------------------------

# Library Contents

A complete description of all mandatory functions included in this
library.

## Part 1 --- Libc Functions

Reimplemented to behave exactly like their original counterparts (except
being prefixed with `ft_`):

### Character classification

-   `ft_isalpha`
-   `ft_isdigit`
-   `ft_isalnum`
-   `ft_isascii`
-   `ft_isprint`

(Return `1` if true, `0` if false.)

### Memory

-   `ft_memset`
-   `ft_bzero`
-   `ft_memcpy`
-   `ft_memmove`
-   `ft_memchr`
-   `ft_memcmp`
-   `ft_calloc`\
    Must return a freeable pointer even when size is zero.

### Strings

-   `ft_strlen`
-   `ft_strlcpy`
-   `ft_strlcat`
-   `ft_strchr`
-   `ft_strrchr`
-   `ft_strncmp`
-   `ft_strnstr`
-   `ft_strdup`
-   `ft_atoi`

Note: On glibc systems, `strlcpy` and `strlcat` may require
`<bsd/string.h>` and `-lbsd` for comparison.

------------------------------------------------------------------------

## Part 2 --- Additional Functions

### String manipulation

-   `ft_substr`
-   `ft_strjoin`
-   `ft_strtrim`
-   `ft_split`
-   `ft_itoa`

All of these functions allocate memory dynamically and must return
`NULL` on allocation failure.

### Functional operations

-   `ft_strmapi`
-   `ft_striteri`

### File descriptor output

-   `ft_putchar_fd`
-   `ft_putstr_fd`
-   `ft_putendl_fd`
-   `ft_putnbr_fd`

------------------------------------------------------------------------

## Part 3 --- Linked List Functions

This section introduces the `t_list` struct:

``` c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;
```

List utilities included:

-   `ft_lstnew`
-   `ft_lstadd_front`
-   `ft_lstsize`
-   `ft_lstlast`
-   `ft_lstadd_back`
-   `ft_lstdelone`
-   `ft_lstclear`
-   `ft_lstiter`
-   `ft_lstmap`

Memory must be handled correctly, using the provided `del` function
where required.

------------------------------------------------------------------------

# Usage

Example minimal program:

``` c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    printf("%zu\n", ft_strlen("Hello Libft"));
    return 0;
}
```

Compile with:

``` bash
cc main.c libft.a -o test
```

------------------------------------------------------------------------

# Resources

Recommended references:

-   Standard C library documentation
-   man pages: `malloc`, `free`, `write`
-   BSD vs glibc differences (for `strlcpy` / `strlcat`)

### AI Usage Statement

AI was used exclusively for: - Documentation clarification\
- Structuring this README\
- Improving explanations and formatting

All reasoning, implementation, debugging and testing of the code were
performed manually.

------------------------------------------------------------------------

# License

This project follows the rules and evaluation guidelines of 42.\
All functions respect the Norm and must be free of crashes and memory
leaks.
