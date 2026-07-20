# 🖨️ ft_printf — Custom `printf` Implementation

> 42 Barcelona — **ft_printf** project.
> A reimplementation of `printf` as a static library (`libftprintf.a`), supporting the
> mandatory conversions: `%c %s %p %d %i %u %x %X %%`.

---

## ⚙️ Build

From the repository root:

```bash
make            # Build libftprintf.a
make clean      # Remove object files
make fclean     # Remove object files, libftprintf.a and the test/demo binaries
make re         # Full rebuild
make asan       # Rebuild with AddressSanitizer / UBSan flags
```

---

## 🧪 Running the tests

All correctness tests live in the `tests/` folder — one file per conversion
(`test_char.c`, `test_string.c`, `test_int.c` + `test_int_edge.c`, `test_unsigned.c`,
`test_hex.c`, `test_pointer.c`, `test_percent.c`), sharing a small framework
(`test_utils.h` / `test_utils.c`) that:

1. redirects `stdout` to a temp file around each `ft_printf` call,
2. computes the expected output with `snprintf` (the real libc formatter),
3. compares both the output **and** the return value,
4. prints a colored `[PASS]` / `[FAIL]` per case, plus a final summary.

### Run everything

```bash
make tests
```

This builds `libftprintf.a`, compiles every file in `tests/` against it, links the
`tests/tester` binary, and runs it right away. Example output:

```
========================================
        FT_PRINTF TEST SUITE
========================================

-- %c tests --
  [PASS] %c letter
  [PASS] %c digit
  [PASS] %c space

-- %s tests --
  [PASS] %s word
  ...

========================================
20/20 tests passed
========================================
```

A `[FAIL]` line prints what `ft_printf` actually produced next to what was expected:

```
  [FAIL] %d INT_MIN
        got:      "-2147483647"
        expected: "-2147483648"
        ret ft: 12 | ret real: 11
```

### Run again without rebuilding

```bash
./tests/tester
```

### Add a new test case

Pick the file matching the conversion (e.g. `tests/test_hex.c`), add a new
`static void case_xxx(void)` following the existing pattern, and call it from the
file's `test_x(void)` dispatcher:

```c
static void	case_my_new_case(void)
{
	char	expected[32];
	int		ft_ret;
	int		pf_ret;

	test_before();
	ft_ret = ft_printf("%x", 42u);
	pf_ret = snprintf(expected, sizeof(expected), "%x", 42u);
	test_after("%x my case", ft_ret, pf_ret, expected);
}
```

If you add a brand-new conversion file, remember to:
- declare its `test_x(void)` entry point in `tests/test_utils.h`,
- call it from `tests/main_tests.c`,
- add the new `.c` file to `TEST_SRCS` in the `Makefile`.

---

## 🎮 Manual demo

`make demo` builds a small interactive comparison binary (`main.c` +
`demo_report.c` + `demo_basic.c` + `demo_extra.c`) that runs each conversion once
against a string you pass in, side by side with the real `printf`:

```bash
make demo
./ft_printf "some string"
```

This is meant for quick eyeballing, not for correctness — `make tests` is the
source of truth.

---

## 🧩 Norm

Every file (library, `main.c`, `demo_*.c`, and everything under `tests/`) passes
**42 Norminette**. Run it from the project root:

```bash
norminette .
```
