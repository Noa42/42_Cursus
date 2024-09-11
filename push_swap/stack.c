/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:19:06 by achacon-          #+#    #+#             */
/*   Updated: 2024/03/20 13:10:48 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node -> value = value;
	node -> position = 0;
	node -> cost_a = 0;
	node -> cost_b = 0;
	node -> total_cost = 0;
	node -> next = NULL;
	return (node);
}

int	ft_stack_size(t_stack *head)
{
	int		len;
	t_stack	*p;

	if (head == NULL)
		return (0);
	len = 1;
	p = head;
	while (p -> next != NULL)
	{
		p = p -> next;
		len ++;
	}
	return (len);
}

void	ft_stack_add_back(t_stack **head, t_stack *new)
{
	t_stack	*last;

	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		last = ft_stack_last(*head);
		last -> next = new;
	}
}

t_stack	*ft_stack_last(t_stack *head)
{
	t_stack	*ptr;

	ptr = head;
	if (head == NULL)
		return (NULL);
	while (ptr -> next)
	{
		ptr = ptr -> next;
	}
	return (ptr);
}

int	clear_stack(t_stack **stack)
{
	t_stack	*p_clear;
	t_stack	*p;

	p = *stack;
	p_clear = *stack;
	while (p != NULL)
	{
		p = p -> next;
		free(p_clear);
		p_clear = p;
	}
	*stack = NULL;
	return (1);
}
