/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:19:06 by achacon-          #+#    #+#             */
/*   Updated: 2024/02/08 12:50:49 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

stack	*ft_lstlast(stack *lst)
{
	stack	*ptr;

	ptr = lst;
	if (lst == NULL)
		return (NULL);
	while (ptr -> next)
	{
		ptr = ptr -> next;
	}
	return (ptr);
}
