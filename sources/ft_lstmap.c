/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:01:17 by jmertane          #+#    #+#             */
/*   Updated: 2024/02/06 18:16:46 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new;
	void	*result;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		result = f(lst->content);
		new = ft_lstnew(result);
		if (!new)
		{
			del(result);
			ft_lstclear(&head, del);
			return (head);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}
