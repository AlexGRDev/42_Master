# 🧠 Rank 0 — First Steps in C: Libft

> Starting point of the **42 Common Core**.  
> In this rank there is only one mandatory project: **Libft**.

---

## 👤 Who is this README for?

- If this is your **first serious C project**, this file is for you.  
- If you come from the **Piscine** and have not done much “real” C yet, this is a guide so you do not get lost.  
- If you already finished Libft, you can use this as a **quick recap** of what to focus on.

---

## 🗺️ How to use this rank

- Start here to understand **what Libft is and why it matters** for later projects.  
- Then go into `Rank 0/LibFT/` and read its README for more **project‑specific details** (build, contents, testing, etc.).  
- Keep the **official Libft subject PDF** open while you work; use this README as extra guidance, not a replacement.

---

## 📚 What is Rank 0?

Rank 0 is your first serious contact with **C** and with the 42 methodology.  
Here you learn to:

- Work on your own project from scratch.  
- Understand how the **standard C library functions** really work.  
- Manage **memory manually** (no helpers, no STL, no external libraries).  
- Compile and organize your code as a **static library** (`libft.a`).

This rank is the foundation for many later projects (`ft_printf`, `get_next_line`, `push_swap`, etc.).

---

## 📂 Project in Rank 0

| Project | Description | Language | Status |
|:--------|:------------|:---------|:-------|
| **Libft** | Reimplementation of basic libc functions plus custom utilities, all packed into a static library. | C | 100/100 |

Inside `LibFT/` you will find the full implementation of the project, with its `Makefile` and all required `.c` / `.h` files.

---

## ⚙️ What you do in Libft

In Libft you rewrite many classic C functions and add some general‑purpose helpers:

- Character checks (`ft_isalpha`, `ft_isdigit`, ...).  
- Memory handling (`ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_calloc`, ...).  
- String handling (`ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strncmp`, ...).  
- Type conversion (`ft_atoi`, `ft_itoa`, ...).  
- Extra helpers for strings and file descriptors (`ft_split`, `ft_substr`, `ft_strjoin`, `ft_putstr_fd`, ...).

The goal is not just to "copy" libc, but to **understand its behavior**, edge cases, and to learn how to design reusable functions.

---

## ✅ Checklist before submitting Libft

Before you submit / run Moulinette, check:

- [ ] The `Makefile` builds **`libft.a`** with a plain `make` command.
- [ ] You do not use **forbidden functions** (only what the subject allows).
- [ ] Everything compiles with `-Wall -Wextra -Werror` **with zero warnings**.
- [ ] Your functions behave like the real **libc** ones for the cases in the subject.
- [ ] There are **no memory leaks** (check with `valgrind`).
- [ ] `libft.h` only exposes what is needed and has no duplicates.

---

## ⚙️ Compilation

From inside the `LibFT/` directory you typically use:

```bash
make        # Build libft.a
make clean  # Remove object files
make fclean # Remove object files and libft.a
make re     # Rebuild everything from scratch
```

You can then link `libft.a` into your other C projects.

---

## 🧠 What you learn in Rank 0

- Solid **C fundamentals**:  
  - Pointers, arrays, and string handling.  
  - Basic types, casting, and control flow.  
  - Header files, includes, and function prototypes (`libft.h`).  
  - Using a `Makefile` to compile multiple `.c` files into one library.  
- **Memory management**:  
  - Allocating and freeing memory correctly with `malloc` / `free`.  
  - Avoiding leaks and invalid accesses.  
- **Project organization**:  
  - Splitting code across multiple `.c` and `.h` files.  
  - Building a **static library** (`ar rcs libft.a`).  
  - Writing and using a basic **Makefile**.
- **Norminette and good practices**:  
  - Respecting the 42 norm (function length, naming, formatting).  
  - Writing readable and consistent code from the beginning.

Everything you learn here is reused directly in the following ranks: your `libft` becomes your personal **toolbox**.

Working through the actual functions also teaches a lot in practice:
- Implementing `ft_split` forces you to think carefully about allocation, freeing on errors, and how to represent arrays of strings.
- Writing `ft_itoa` and `ft_atoi` makes you deal with numeric edge cases, signs, and overflow behavior.
- Recreating functions like `ft_strlcpy`, `ft_strlcat` and `ft_strncmp` trains you to reason about buffer sizes and off‑by‑one errors.
- Functions such as `ft_memcpy`, `ft_memmove` and `ft_memchr` help you visualize memory as raw bytes instead of just strings.

---

## ⚠️ Common pitfalls

- Not freeing memory in functions like `ft_split` when something fails.
- Assuming inputs will never be `NULL` or empty strings.
- Not matching the exact behavior of libc (for example in `ft_memmove`, `ft_strlcpy`, etc.).
- Using global variables to “fix” design problems.
- Having a `Makefile` that does not follow the subject rules.

---
