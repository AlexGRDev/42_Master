# 🧭 Rank 1 — Foundations in C & Unix

> Part of the **42_Master** journey — early projects that solidify C fundamentals, Unix basics, and independent problem‑solving.

---

## 📚 Overview

This directory contains the **Rank 1** projects from the 42 cursus.  
They are the first “big” steps after `libft` and focus on:

- Writing larger C programs split across multiple files.  
- Understanding how the Unix environment works (files, processes, permissions).  
- Learning to read, debug, and iterate on your own code.

---

## 📂 Projects in Rank 1

> The exact list can vary by campus; these are the most common Rank 1 projects.

| Project | Description | Language | Status |
|:--------|:------------|:---------|:-------|
| **[ft_printf](https://github.com/AlexGRDev/printf)** | Custom implementation of a subset of `printf`. | C | In Progress |
| **Get Next Line** | Read a line from a file descriptor, one call at a time. | C | In Progress |
| **Born2beroot** | Configure and harden a Debian-based virtual machine. | Bash / Debian | In Progress |

As you complete each project, you can update this table with final status (e.g. `100/100`) and repository links.

---

## 🎯 What you learn in this rank

### 🔡 ft_printf
- Advanced use of **variadic functions**: `va_list`, `va_start`, `va_arg`, `va_end`.  
- Organizing a C project into **multiple source files** with a central **Makefile**.  
- Implementing and handling format specifiers:  
  `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p`, `%%`.  
- Returning the **exact number of printed characters** and handling edge cases.

### 📜 Get Next Line
- Managing **buffers** and incremental reads with `read()`.  
- Careful **dynamic memory** handling and avoiding leaks.  
- Designing functions that **keep state between calls** while staying reusable.

### 🖥️ Born2beroot
- Basic **system administration**: users, groups, SSH, sudo, firewall (UFW), etc.  
- Managing **services**, logs, and simple monitoring tools.  
- Following a long, constraint-heavy **subject** and documenting configuration choices.

---

## 🚀 How to use this folder

- Each project lives in its own subdirectory (e.g. `ft_printf/`).  
- For C projects, a typical workflow is:
  - `cd <project>`  
  - `make` to build the library or binary.  
  - Run your own `main.c` or provided tester to try the project.
- This `README.md` is meant to give a **high-level view** of Rank 1;  
  each project’s own README can go into build details, usage, and edge cases.

Feel free to expand this file as you progress: add screenshots, notes on what was hardest, or links to external testers and resources.
