<h1 align="center">
  <b>libft</b>
</h1>

<p align="center">
	<b><i>Personalized function library based on standard 🇨 library.</i></b><br>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Score-125%2F100-lightgreen?style=for-the-badge" alt="score">
  <img src="https://img.shields.io/github/languages/top/Jarnomer/libft?style=for-the-badge&logo=c&label=%20&labelColor=gray&color=lightblue" alt="GitHub top language">
	<img src="https://img.shields.io/github/languages/code-size/Jarnomer/libft?style=for-the-badge&color=lightyellow" alt="GitHub code size in bytes">
  <img src="https://img.shields.io/github/directory-file-count/Jarnomer/libft/sources?style=for-the-badge&label=sources&color=pink" alt="GitHub repo file or directory count (in path)">
</p>

<p align="center">
    <img src="https://img.shields.io/badge/Type-Solo-violet?style=for-the-badge" alt="type">
  <img src="https://img.shields.io/github/last-commit/Jarnomer/libft/main?style=for-the-badge&color=red" alt="GitHub last commit (branch)">
</p>

<div align="center">

## Table of Contents
[📝 General](#-general)
[🛠️ Build](#️-build)
[⚡ Usage](#-usage)
[🚀 Details](#-details)
[♻️ Resources](#️-resources)

</div>

## 📝 General

Library includes mainly a selection of replicated `Libc` functions.

It is complemented by `additional`, mostly `string` and `print` based functionality.

`Bonus` which is centered around `linked lists` is also integrated into the library.

[ft_printf](https://github.com/Jarnomer/ft_printf) and [gnl](https://github.com/Jarnomer/gnl) are combined to the project as well alongside other `extra` functions.

Project `passes` many of the 42 `testers`, including [franzinette](https://github.com/xicodomingues/francinette) `strict`.

⚠️ `Main` branch is shared between other [42 projects](https://github.com/Jarnomer/Hive42) and it is expanded from original subject. ⚠️

If you want to see the version used for school evaluation, check `eval` branch.

## 🛠️ Build

GNU `make`, `gcc` and `ar` are required to build, compile and archive the project.

```bash
git clone https://github.com/Jarnomer/libft.git libft
```

```bash
cd libft && make all
```

## ⚡ Usage

Build creates binary `libft.a` into `root` directory and it should be `compiled` with your project.

```c
#include "./include/libft.h"

int main(void)
{
  char *str1 = "Hello ";
  char *str2 = "world!";
  char *result;

  result = ft_strjoin(str1, str2);
  ft_printf("Result: %s\n", result);
  ft_free_single(&result);
  return (0);
}
```

```bash
gcc main.c libft.a -o my_program
```

Here is an example how to implement `libft` into your `Makefile`.

```bash
$(NAME): $(OBJECTS)
  $(CC) $(CFLAGS) $^ $(LIBFTDIR)/$(LIBFTBIN) -o $@

$(OBJECTS): $(LIBFTDIR)/$(LIBFTBIN)

libft: $(LIBFTDIR)/$(LIBFTBIN)

$(LIBFTDIR)/$(LIBFTBIN): 
  @make -C $(LIBFTDIR) all
```

## 🚀 Details

Here is the table of all functions.

| **Libc**              | **Additional**        | **Bonus**               | **Extras**            |
|------------------------|-----------------------|--------------------------|------------------------|
| `ft_atoi`             | `ft_itoa`            | `ft_lstadd_back`        | `ft_printf`           |
| `ft_bzero`            | `ft_putchar_fd`      | `ft_lstadd_front`       | `ft_printf_fmt`       |
| `ft_calloc`           | `ft_putendl_fd`      | `ft_lstclear`           | `ft_gnl`              |
| `ft_isalnum`          | `ft_putnbr_fd`       | `ft_lstdelone`          | `ft_gnl_utils`        |
| `ft_isalpha`          | `ft_putstr_fd`       | `ft_lstiter`            | `ft_free_single`      |
| `ft_isascii`          | `ft_split`           | `ft_lstlast`            | `ft_free_double`      |
| `ft_isdigit`          | `ft_strdup`          | `ft_lstmap`             | `ft_strcmp`           |
| `ft_isprint`          | `ft_striteri`        | `ft_lstnew`             | `ft_isspace`          |
| `ft_memchr`           | `ft_strjoin`         | `ft_lstsize`            | `ft_issign`           |
| `ft_memcmp`           | `ft_strmapi`         |                          |                        |
| `ft_memcpy`           | `ft_strtrim`         |                          |                        |
| `ft_memmove`          | `ft_substr`          |                          |                        |
| `ft_memset`           |                       |                          |                        |
| `ft_strchr`           |                       |                          |                        |
| `ft_strlcat`          |                       |                          |                        |
| `ft_strlcpy`          |                       |                          |                        |
| `ft_strlen`           |                       |                          |                        |
| `ft_strncmp`          |                       |                          |                        |
| `ft_strnstr`          |                       |                          |                        |
| `ft_strrchr`          |                       |                          |                        |
| `ft_tolower`          |                       |                          |                        |
| `ft_toupper`          |                       |                          |                        |

Each function is relying on each other when applicable.

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

## ♻️ Resources

[franzinette](https://github.com/xicodomingues/francinette) amazing unit test framework for libft and other 42 projects.

## 4️⃣2️⃣ Footer

For my other 42 project and general information, please refer the [landing page](https://github.com/Jarnomer/Hive42).

I have also created error handling [unit testers](https://github.com/Jarnomer/Hive42) for `pipex`, `so_long` and `cub3d`.

### Cheers and good luck! 🥳