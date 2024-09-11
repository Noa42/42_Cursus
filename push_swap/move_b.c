/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:06:14 by achacon-          #+#    #+#             */
/*   Updated: 2024/03/20 12:42:50 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stack **head)
{
	t_stack	*prim;
	t_stack	*seg;
	t_stack	*tail;

	prim = *head;
	seg = prim -> next;
	tail = seg -> next;
	*head = seg;
	prim -> next = tail;
	seg -> next = prim;
	ft_putstr_fd("sb\n", 1);
}

void	push_b(t_stack **dest, t_stack **ori)
{
	t_stack	*p;

	if (*ori && ft_stack_size(*ori) > 0)
	{
		p = (*ori)->next;
		(*ori)->next = *dest;
		*dest = *ori;
		*ori = p;
	}
	ft_putstr_fd("pb\n", 1);
}

void	rotate_b(t_stack **head, int flag)
{
	t_stack	*p_ini;
	t_stack	*p_fin;

	p_ini = *head;
	p_fin = ft_stack_last(*head);
	p_fin -> next = *head;
	*head = (*head)->next;
	p_ini -> next = NULL;
	if (flag == 1)
		ft_putstr_fd("rb\n", 1);
}

void	rev_rotate_b(t_stack **head, int flag)
{
	t_stack	*p_fin;
	t_stack	*p_fin_prev;
	int		i;

	i = 0;
	p_fin_prev = *head;
	while (i < ft_stack_size(*head) - 2)
	{
		p_fin_prev = p_fin_prev -> next;
		i++;
	}
	p_fin = ft_stack_last(*head);
	p_fin -> next = *head;
	*head = p_fin;
	p_fin_prev -> next = NULL;
	if (flag == 1)
		ft_putstr_fd("rrb\n", 1);
}
