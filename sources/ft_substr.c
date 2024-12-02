/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:52:59 by jmertane          #+#    #+#             */
/*   Updated: 2024/02/08 15:43:17 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (!*s || start >= s_len)
		return ((ft_strdup("")));
	if (len > s_len - start)
		len = s_len - start;
	str = ft_calloc(len + 1, sizeof(char));
	if (str)
		ft_strlcpy(str, s + start, len + 1);
	return (str);
}
