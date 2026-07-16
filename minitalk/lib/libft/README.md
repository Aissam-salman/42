# libft

Collection of C utility functions (42 project). Implements string/memory helpers, character checks, and a simple linked-list API.

## Build

```bash
make
```
Produces `libft.a` in this directory.

## Use in your project

```c
#include "libft.h"

int main(void)
{
    char *copy = ft_strdup("hello");
    ft_striteri(copy, [](unsigned int i, char *c){ (void)i; *c = ft_toupper(*c); });
    ft_putendl_fd(copy, 1);
    free(copy);
    return 0;
}
```

Compile and link with the library:

```bash
gcc -Wall -Wextra -Werror your_file.c -L. -lft
```

## Optional: generate HTML docs with Doxygen

If you want browsable docs (requires `doxygen` installed):

```bash
cd libft
doxygen
firefox html/index.html
```

## Structure

- Core libc-like functions: `ft_atoi`, `ft_calloc`, `ft_mem*`, `ft_str*`, `ft_is*`, `ft_to*`
- I/O helpers: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
- Split/join/trim/map utilities: `ft_split`, `ft_strjoin`, `ft_strtrim`, `ft_strmapi`, `ft_striteri`
- Linked list API: `t_list` plus `ft_lstnew`, `ft_lstadd_front/back`, `ft_lstsize`, `ft_lstlast`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`
