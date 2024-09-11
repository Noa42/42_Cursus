/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_fields.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:06:14 by achacon-          #+#    #+#             */
/*   Updated: 2024/03/20 15:15:24 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_positions(t_stack **head)
{
	t_stack	*p;
	int		i;

	i = 0;
	p = *head;
	while (p != NULL)
	{
		p -> position = i;
		i++;
		p = p -> next;
	}
}

void	set_targets(t_stack **stack_a, t_stack **stack_b, int max)
{
	t_stack	*pa;
	t_stack	*pb;

	pa = *stack_a;
	pb = *stack_b;
	while (pb != NULL)
	{
		if (is_highest(pb -> value, stack_a) == 1)
			pb -> target = lowest_node(*stack_a);
		else
		{
			while (pa != NULL && pb != NULL)
			{
				if (pa -> value > pb -> value && pa -> value < max)
				{
					max = pa -> value;
					pb -> target = pa -> position;
				}
				pa = pa -> next;
			}
		}
		pb = pb -> next;
		pa = (*stack_a);
		max = INT_MAX;
	}
}

int	absolute(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	set_costs(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*p;

	p = *stack_b;
	while (p != NULL)
	{
		if (p -> target > ft_stack_size(*stack_a) / 2)
			p -> cost_a = (ft_stack_size(*stack_a) - (p -> target)) * (-1);
		else
			p -> cost_a = p -> target;
		if (p -> position > ft_stack_size(*stack_b) / 2)
			p -> cost_b = (ft_stack_size(*stack_b) - (p -> position)) * (-1);
		else
			p -> cost_b = p -> position;
		p -> total_cost = absolute(p -> cost_a) + absolute(p -> cost_b);
		p = p -> next;
	}
}
