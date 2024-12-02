<h1 align="center">
  <b>libft</b>
</h1>

<p align="center">
	<b><i>Personalized function library based on standard 🇨 library.</i></b><br>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Solo-violet?style=for-the-badge" alt="solo">
  <img src="https://img.shields.io/badge/Score-125%2F100-lightgreen?style=for-the-badge" alt="score">
	<img src="https://img.shields.io/github/languages/code-size/Jarnomer/libft?style=for-the-badge&color=lightyellow" alt="GitHub code size in bytes">
  <img src="https://img.shields.io/github/languages/top/Jarnomer/libft?style=for-the-badge&logo=c&label=%20&labelColor=gray&color=lightblue" alt="GitHub top language">
</p>

## ⚠️ Important

`main` branch is shared between other [42 projects](https://github.com/Jarnomer/Hive42) and it is expanded from original subject.

If you want to see the version used of evaluation, check `eval` branch.

## 📝 General

Library includes a selection of replicated `Libc` functions aimed to be used in upcoming [42 projects](https://github.com/Jarnomer/Hive42).

It is complemented by `additional`, mainly `string` focused functions.

`Bonus` is centered around `linked list`.

As `extra` functions

## 🛠️ Build

GNU `make` and `gcc` are required to build and compile the project.

```bash
git clone https://github.com/Jarnomer/libft.git libft
```

## 🚀 Functions

Here is the table of all functions.

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

Project `passes` many of the 42 `testers`, including Franzinette `strict`.

## 4️⃣2️⃣ Footer

For my other 42 project and general information, please refer the [landing page](https://github.com/Jarnomer/Hive42).

I have also created error handling [unit testers](https://github.com/Jarnomer/Hive42) for `pipex`, `so_long` and `cub3d`.

### Cheers and good luck! 🥳