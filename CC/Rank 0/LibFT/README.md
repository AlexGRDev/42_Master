# 🧠 Libft — My Own Implementation of libc

> 42 Barcelona Project — Author: **agarcia2**

---

## 📖 Description

**Libft** is the first mandatory project at **42 School**.  
The goal is to reimplement standard C library functions and build additional utilities from scratch.  
This project teaches how to manage memory, strings, and linked lists while understanding low-level behavior in C.

By the end, you will have your **own version of libc**, reusable in all your future C projects.

---

## ⚙️ Compilation

```bash
make            # Compile libft.a
make clean      # Remove object files
make fclean     # Remove object files and libft.a
make re         # Recompile everything from scratch
```
| Nº  | Function                                   | Prototype                                           | Description                                      |
|:---:|:--------------------------------------------|:----------------------------------------------------|:-------------------------------------------------|
| 1   | [`ft_isalpha`](./ft_isalpha.c)             | `int ft_isalpha(int c);`                            | Checks if `c` is an alphabetic character.        |
| 2   | [`ft_isdigit`](./ft_isdigit.c)             | `int ft_isdigit(int c);`                            | Checks if `c` is a decimal digit.                |
| 3   | [`ft_isalnum`](./ft_isalnum.c)             | `int ft_isalnum(int c);`                            | Checks if `c` is alphanumeric.                   |
| 4   | [`ft_isascii`](./ft_isascii.c)             | `int ft_isascii(int c);`                            | Checks if `c` belongs to the ASCII table.        |
| 5   | [`ft_isprint`](./ft_isprint.c)             | `int ft_isprint(int c);`                            | Checks if `c` is printable.                      |
| 6   | [`ft_strlen`](./ft_strlen.c)               | `size_t ft_strlen(const char *s);`                  | Returns the length of a string.                  |
| 7   | [`ft_memset`](./ft_memset.c)               | `void *ft_memset(void *b, int c, size_t len);`      | Fills memory with a constant byte.               |
| 8   | [`ft_bzero`](./ft_bzero.c)                 | `void ft_bzero(void *s, size_t n);`                 | Sets memory to zero.                             |
| 9   | [`ft_memcpy`](./ft_memcpy.c)               | `void *ft_memcpy(void *dst, const void *src, size_t n);` | Copies `n` bytes from `src` to `dst`.      |
| 10  | [`ft_memmove`](./ft_memmove.c)             | `void *ft_memmove(void *dst, const void *src, size_t len);` | Safely copies memory (handles overlap). |
| 11  | [`ft_strlcpy`](./ft_strlcpy.c)             | `size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);` | Copies a string with size limit. |
| 12  | [`ft_strlcat`](./ft_strlcat.c)             | `size_t ft_strlcat(char *dst, const char *src, size_t dstsize);` | Concatenates strings with size limit. |
| 13  | [`ft_toupper`](./ft_toupper.c)             | `int ft_toupper(int c);`                            | Converts a character to uppercase.               |
| 14  | [`ft_tolower`](./ft_tolower.c)             | `int ft_tolower(int c);`                            | Converts a character to lowercase.               |
| 15  | [`ft_strchr`](./ft_strchr.c)               | `char *ft_strchr(const char *s, int c);`            | Locates first occurrence of a character.         |
| 16  | [`ft_strrchr`](./ft_strrchr.c)             | `char *ft_strrchr(const char *s, int c);`           | Locates last occurrence of a character.          |
| 17  | [`ft_strncmp`](./ft_strncmp.c)             | `int ft_strncmp(const char *s1, const char *s2, size_t n);` | Compares two strings up to `n` bytes.  |
| 18  | [`ft_memchr`](./ft_memchr.c)               | `void *ft_memchr(const void *s, int c, size_t n);`  | Searches for a byte in a memory block.           |
| 19  | [`ft_memcmp`](./ft_memcmp.c)               | `int ft_memcmp(const void *s1, const void *s2, size_t n);` | Compares two memory blocks.             |
| 20  | [`ft_strnstr`](./ft_strnstr.c)             | `char *ft_strnstr(const char *haystack, const char *needle, size_t len);` | Searches for a substring.             |
| 21  | [`ft_atoi`](./ft_atoi.c)                   | `int ft_atoi(const char *str);`                     | Converts a string to an integer.                 |
| 22  | [`ft_calloc`](./ft_calloc.c)               | `void *ft_calloc(size_t count, size_t size);`       | Allocates zero-initialized memory.               |
| 23  | [`ft_strdup`](./ft_strdup.c)               | `char *ft_strdup(const char *s1);`                  | Duplicates a string.                             |
