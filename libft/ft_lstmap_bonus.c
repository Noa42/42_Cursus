/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:06:14 by achacon-          #+#    #+#             */
/*   Updated: 2024/02/08 12:50:49 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

stack	*ft_lstmap(stack *lst, void *(*f)(void *), void (*del)(void *))
{
	stack	*newhead;
	stack	*node;

	newhead = NULL;
	node = NULL;
	if (lst == NULL || f == NULL || del == NULL || lst -> content == NULL)
		return (NULL);
	while (lst != NULL)
	{
		node = ft_lstnew(NULL);
		if (node == NULL)
		{
			ft_lstclear(&newhead, del);
			return (NULL);
		}
		node -> content = f(lst -> content);
		ft_lstadd_back(&newhead, node);
		lst = lst -> next;
	}
	return (newhead);
}
