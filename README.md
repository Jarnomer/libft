# libft

Standard 🇨 Library functions with added spicing 🌶️.

## General

`Libft` is focused on creating personal function library in C.

The library inludes a selection of replicated `Libc` functions aimed to be used in upcoming 42 projects.

It is completed with `additional`, mainly string focused functions. `Bonus` is centered around `linked list`.

Project `passes` many of the 42 `testers`, including Franzinette `strict`.

Build as a library and thus each function is relying on each other when applicable.

For other information, please refer the main page.

```c
char *ft_strjoin(char const *s1, char const *s2)
{
  char  *str;
  int    buffer_size;

  if (!s1 || !s2)
    return (NULL);
  buffer_size = ft_strlen(s1) + ft_strlen(s2) + 1;
  str = ft_calloc(buffer_size, sizeof(char));
  if (!str)
    return (NULL);
  ft_strlcat(str, s1, buffer_size);
  ft_strlcat(str, s2, buffer_size);
  return (str);
}
```

## Functions

Here is the table of all functions, including bonus.

| **Libc**              | **Additional**        | **Bonus**               |
|------------------------|-----------------------|--------------------------|
| `ft_atoi`           | `ft_itoa`          | `ft_lstadd_back`|
| `ft_bzero`          | `ft_putchar_fd`    | `ft_lstadd_front`|
| `ft_calloc`         | `ft_putendl_fd`    | `ft_lstclear`   |
| `ft_isalnum`        | `ft_putnbr_fd`     | `ft_lstdelone`  |
| `ft_isalpha`        | `ft_putstr_fd`     | `ft_lstiter`    |
| `ft_isascii`        | `ft_split`         | `ft_lstlast`    |
| `ft_isdigit`        | `ft_strdup`        | `ft_lstmap`     |
| `ft_isprint`        | `ft_striteri`      | `ft_lstnew`     |
| `ft_memchr`         | `ft_strjoin`       | `ft_lstsize`    |
| `ft_memcmp`         | `ft_strmapi`       |                          |
| `ft_memcpy`         | `ft_strtrim`       |                          |
| `ft_memmove`        | `ft_substr`        |                          |
| `ft_memset`         |                       |                          |
| `ft_strchr`         |                       |                          |
| `ft_strlcat`        |                       |                          |
| `ft_strlcpy`        |                       |                          |
| `ft_strlen`         |                       |                          |
| `ft_strncmp`        |                       |                          |
| `ft_strnstr`        |                       |                          |
| `ft_strrchr`        |                       |                          |
| `ft_tolower`        |                       |                          |
| `ft_toupper`        |                       |                          |

Mandatory part combines Libc and additional functions, these are located in `sources` folder.

Header is in includes, `-I` is used in `Makefile` to allow include `<libft.h>` instead of `"libft.h"`.

Bonuses are located in their own `bonus` directory under `sources` and they use `shared` header file.

### Cheers and good luck! 🥳