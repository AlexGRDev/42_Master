# Rank 1

This directory gathers the **Rank 1** projects from the 42 cursus. These are the first “big” exercises after `libft`, and they are designed to strengthen your C skills, your Unix knowledge, and your ability to work more independently.

## Rank 1 projects

> Note: the exact list can vary by campus, but the most common projects are:

- **ft_printf**  
  Your own implementation of a simplified `printf`.
  - What you learn:
    - Advanced use of **variadic functions** (`va_list`, `va_start`, `va_arg`, `va_end`).
    - How to organize a C project across **multiple source files** with a **Makefile**.
    - Handling format specifiers (`%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p`, `%%`).
    - Error handling and counting how many characters are written.

- **get_next_line** *(usually appears in this rank as well)*  
  A function that reads from a file descriptor or `stdin` **line by line**.
  - What you learn:
    - Managing **buffers** and reading with `read()`.
    - Working with **dynamic memory** and avoiding leaks.
    - Designing reusable functions that keep state between calls.

- **Born2beroot** *(a system project, not written in C)*  
  Setting up a Linux virtual machine following strict security and administration rules.
  - What you learn:
    - Basic **system administration** concepts (users, groups, SSH, sudo, UFW, etc.).
    - Managing **services**, logs, and simple monitoring tools.
    - Reading and following a long **subject** with many constraints.

As you add more Rank 1 projects to this `Rank 1` directory, you can extend this `README.md` to include:

- A short description of each project.
- What you personally learned or found difficult in each one.
- How to compile, run, and test each project.
