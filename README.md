# 🧠 42 Master — My Common Core Guide

> 📍 **42 Barcelona** — Student: **Alex García** (`agarcia2`)  
> 🚀 If you are new to **42**, you can use this repository as a **real project roadmap**: what each project is, what it evaluates, and how to approach it.

---

## 📖 Who is this repository for?

This repo is mainly meant for:

- 👶 **New 42 students** starting the Common Core who want a global view.
- 🔁 Students who have already done some projects and want to **revisit concepts or compare approaches**.
- 👀 Candidates curious about what you actually do at 42 and what C / Unix level is expected.

It is not the official **subject** of any project, but you can use it as a companion while you read each PDF.

---

## 🗺️ How to use this roadmap

- Progress **by ranks** (`Rank 0`, `Rank 1`, etc.), just like on the intra.
- In each rank, open the folder and read its `README.md` to understand:
  - Which project(s) it includes.
  - Which skills you will practice.
  - Tips and common mistakes.
- Then open the project folder itself (for example `Rank 0/LibFT`) and read its specific README.
- Always keep the **official subject PDF open**: you will find context here, not the exact rules.

---

## 📖 About This Repository

**42_Master** is my main Common Core repository.  
It contains all projects from the **42 Common Core**, structured as independent modules and submodules.  
Each project is (or will be) its own GitHub repository; this repo connects them all as a single roadmap.

Here you can see my progression from low‑level C to systems and some full‑stack projects, following the 42 methodology:
> _“Learning to learn, debugging to survive.”_

---

## 🧭 Common Core Progress (Project map)

| Rank | Project | Description | Language | Status |
|:----:|:---------|:-------------|:----------|:--------:|
| 00 | [LibFT](https://github.com/AlexGRDev/LibFT) | Custom implementation of libc functions. | C | 100/100 |
| 01 | [Get Next Line]() | Read a line from a file descriptor. | C |  In Progress  |
| 01 | [FT Printf](https://github.com/AlexGRDev/printf) | Reimplementation of printf. | C |  In Progress |
| 01 | [Born2BeRoot]() | Linux system administration project. | Bash / Debian | In Progress |
| 02 | [Pipex]() | UNIX pipe and process management. | C |  |
| 02 | [Push Swap]() | Stack sorting algorithm challenge. | C | |
| 02 | [So Long]() | 2D game with pathfinding using MLX. | C | |
| 03 | [Philosophers]() | Multithreading and synchronization. | C | |
| 03 | [Minishell]() | Building a mini Unix shell. | C | |
| 04 | [Cub3D]() | 3D raycasting engine. | C | |
| 04 | [MiniRT]() | Simple ray tracer with lights and shadows. | C | |
| 04 | [NetPractice]() | Networking and IP routing exercises. | Networking | |
| 05 | [CPP Modules]() | Introduction to Object-Oriented Programming. | C++ | |
| 05 | [Inception]() | Docker-based virtualization and DevOps. | Docker / Bash | |
| 05 | [Webserv]() | HTTP server in C++. | C++ | |
| 05 | [Ft_Transcendence]() | Full-stack multiplayer pong with NestJS. | TS / Docker / SQL | | 

---

## 🧠 Skills & Topics Covered (What you will learn)

| Category | Keywords |
|:----------|:----------|
| 🧮 **C Programming** | Pointers, Memory Management, Recursion, Parsing |
| ⚙️ **System & Unix** | Processes, File Descriptors, Pipes, Signals |
| 🧵 **Concurrency** | Threads, Mutexes, Race Conditions |
| 🧰 **Algorithms** | Sorting, Searching, Pathfinding |
| 🖥️ **Graphics** | MLX42, Raycasting, Raytracing |
| 🌐 **Networking** | IP, TCP, HTTP, Sockets |
| 💾 **DevOps** | Docker, Nginx, System Administration |
| 💻 **C++ / OOP** | Inheritance, Polymorphism, Encapsulation |
| 🚀 **Full Stack** | TypeScript, NestJS, PostgreSQL, Docker Compose |

---

## 🧱 Tech Stack

| Tool | Purpose |
|:------|:--------|
| 🐚 Bash / Zsh | Command-line and automation scripts |
| 🧰 Makefile | Project building and compilation |
| 🧠 C / C++ | Core programming languages |
| 🐳 Docker | Virtualized environments |
| 🧩 Git / GitHub | Version control & collaboration |
| 🧵 Pthreads | Multithreading and concurrency |
| 🖼️ MiniLibX | 2D graphics rendering for games |
| ⚙️ Valgrind | Memory leak testing |
| 🧪 Norminette | Code style checker (42 standard) |

---

## 💡 General tips for the Common Core

- ⚖️ **Time management**: do not underestimate “small” projects like `libft` or `ft_printf`. They are the base of almost everything.
- 📏 **Run Norminette often**: get used to running it regularly, not only at the end.
- 🧪 **Test more than the subject examples**: empty inputs, `NULL`, large numbers, system errors, etc.
- 🧼 **Zero leaks**: use `valgrind` from the beginning, not only on the last day.
- 🤝 **Peer‑evals**: prepare a short explanation of your design and a few quick examples to show.
- 📚 **Read the whole subject** before coding: many failures come from not reading the constraints carefully.

---

## 🏁 Setup (clone with submodules)

```bash
git clone --recurse-submodules git@github.com:AlexGRDev/42_Master.git
