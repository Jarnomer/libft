/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:22:14 by jmertane          #+#    #+#             */
/*   Updated: 2024/02/06 18:31:27 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*build_new_line(t_gnl *lst)
{
	char	*line;
	int		total_len;
	int		i;

	total_len = get_line_len(lst);
	line = malloc(sizeof(char) * (total_len + 1));
	if (!line || !lst)
		return (free(line), NULL);
	while (lst)
	{
		i = -1;
		while (lst->content[++i] && lst->content[i] != '\n')
			line[i] = lst->content[i];
		if (lst->content[i] == '\n')
			line[i++] = '\n';
		line[i] = '\0';
		if (!lst->next)
			prep_next_iter(lst->content);
		lst = lst->next;
		line += i;
	}
	return (line - total_len);
}

static bool	parse_new_line(t_gnl **lst, int fd)
{
	t_gnl	*new;
	char	*buffer;
	int		bytes_read;

	new = *lst;
	while (!found_new_line(new))
	{
		new = malloc(sizeof(t_gnl));
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!buffer || !new || bytes_read < 0)
			return (free(buffer), free(new), false);
		else if (!bytes_read)
			return (free(buffer), free(new), true);
		buffer[bytes_read] = '\0';
		append_list(lst, new, buffer);
	}
	return (true);
}

char	*get_next_line(int fd)
{
	static t_gnl	*lst = NULL;
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0
		|| !parse_new_line(&lst, fd))
		return (clean_list(&lst, NULL));
	line = build_new_line(lst);
	return (clean_list(&lst, line));
}
