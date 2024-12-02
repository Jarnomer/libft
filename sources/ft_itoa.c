/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:22:39 by jmertane          #+#    #+#             */
/*   Updated: 2023/11/26 13:05:46 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	st_fill_buffer(char *str, int n, int len)
{
	if (n < 0)
	{
		*str = '-';
		n = -n;
	}
	while (n != 0)
	{
		--len;
		*(str + len) = n % 10 + '0';
		n /= 10;
	}
}

static int	st_get_buffer_size(int n)
{
	int	buffer_size;

	buffer_size = (n == 0) + (n < 0);
	while (n != 0)
	{
		n /= 10;
		++buffer_size;
	}
	return (buffer_size);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		buffer_size;

	if (n == 0)
		return (ft_strdup("0"));
	else if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	buffer_size = st_get_buffer_size(n);
	str = ft_calloc(buffer_size + 1, sizeof(char));
	if (str)
		st_fill_buffer(str, n, buffer_size);
	return (str);
}
