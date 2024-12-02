/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:17:03 by jmertane          #+#    #+#             */
/*   Updated: 2023/11/26 13:10:45 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	**st_free_exit(char **arr, int current)
{
	while (--current >= 0)
		free(arr[current]);
	free(arr);
	return (NULL);
}

static char	**st_fill_array(char **arr, char const *s, char c, int count)
{
	int	start;
	int	end;
	int	current;

	end = 0;
	current = 0;
	while (current < count)
	{
		while (s[end] == c)
			++end;
		start = end;
		while (s[end] && s[end] != c)
			++end;
		arr[current] = ft_substr(s, start, end - start);
		if (!arr[current])
			return (st_free_exit(arr, current));
		++end;
		++current;
	}
	return (arr);
}

static int	st_word_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
			++count;
		while (*s && *s != c)
			++s;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count;

	if (!s)
		return (NULL);
	count = st_word_count(s, c);
	arr = ft_calloc(count + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	return (st_fill_array(arr, s, c, count));
}
