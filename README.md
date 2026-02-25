# 🖨️ ft_printf
![42 School](https://img.shields.io/badge/-School-000000?style=flat-square&logo=42&logoColor=white) <br>
**ft_printf** is a custom reimplementation of the standard C **`printf`** function.  
It formats and prints output to **stdout** using **variadic arguments** (`va_list`), mimicking the core behavior of `printf`.

---

## ✅ Return value

- Returns the **total number of characters printed**.
- If an error occurs, it returns a **negative value**.

---

## 🔧 Supported specifiers

| Specifier | Description |
|---------:|-------------|
| `%c` | Character |
| `%s` | String (`char *`) |
| `%p` | Pointer (hex address) |
| `%d` / `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Hexadecimal (lowercase) |
| `%X` | Hexadecimal (uppercase) |
| `%%` | Prints a `%` |

---

## 🛠️ Makefile

```bash
make
make clean
make fclean
make re
```

---

## ▶️ Example

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s (%d)\n", "world", 42);
    return (0);
}
```

---

## 👤 Author

**ItsVaguayo**
