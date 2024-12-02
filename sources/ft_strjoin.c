/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:04:54 by jmertane          #+#    #+#             */
/*   Updated: 2024/02/08 15:40:36 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		buffer_size;

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
