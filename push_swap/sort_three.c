/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:06:14 by achacon-          #+#    #+#             */
/*   Updated: 2024/03/20 15:19:43 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	keep_three_nodes(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*p;

	p = *stack_a;
	i = ft_stack_size(*stack_a) - 3;
	while (i > 0)
	{
		if (p -> value < mean(*stack_a))
		{
			push_b(stack_b, stack_a);
			i--;
		}
		else
		{
			rotate_a(stack_a, 1);
		}
		p = *stack_a;
	}
}

t_stack	*order_a(t_stack *stack_a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = stack_a;
	second = first -> next;
	third = second -> next;
	if (is_ordered(stack_a) == 1)
		return (stack_a);
	if ((first->value > second->value) && (first->value > third->value))
		rotate_a(&stack_a, 1);
	if ((second->value > first->value) && (second->value > third->value))
		rev_rotate_a(&stack_a, 1);
	if (is_ordered(stack_a) == 1)
		return (stack_a);
	first = stack_a;
	second = first -> next;
	third = second -> next;
	if (first->value > second->value)
		swap_a(&stack_a);
	if (is_ordered(stack_a) == 1)
		return (stack_a);
	else
		return (stack_a);
}
