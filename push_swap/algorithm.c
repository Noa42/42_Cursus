/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:06:14 by achacon-          #+#    #+#             */
/*   Updated: 2024/03/20 13:17:57 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lowest_node(t_stack *stack_a)
{
	t_stack	*p;
	t_stack	*lowest;

	p = stack_a;
	lowest = stack_a;
	while (p != NULL)
	{
		if (p -> value < lowest -> value)
		{
			lowest = p;
		}
		p = p -> next;
	}
	return (lowest -> position);
}

t_stack	*lowest_cost(t_stack *head)
{
	t_stack	*p;
	t_stack	*p_lowest;

	p = head -> next;
	p_lowest = head;
	while (p != NULL)
	{
		if (p -> total_cost < p_lowest -> total_cost)
		{
			p_lowest = p;
		}
		p = p -> next;
	}
	return (p_lowest);
}

void	movement(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*p;

	p = lowest_cost(*stack_b);
	if (p -> cost_a == 0 && p -> cost_b == 0)
		push_a(stack_a, stack_b);
	else if (p -> cost_a < 0 && p -> cost_b < 0)
	{
		rev_rotate_a(stack_a, 0);
		rev_rotate_b(stack_b, 0);
		ft_putstr_fd("rrr\n", 1);
	}
	else if (p -> cost_a > 0 && p -> cost_b > 0)
	{
		rotate_a(stack_a, 0);
		rotate_b(stack_b, 0);
		ft_putstr_fd("rr\n", 1);
	}
	if (p -> cost_a < 0)
		rev_rotate_a(stack_a, 1);
	else if (p -> cost_a > 0)
		rotate_a(stack_a, 1);
	else if (p -> cost_b < 0)
		rev_rotate_b(stack_b, 1);
	else if (p -> cost_b > 0)
		rotate_b(stack_b, 1);
}

void	sort_and_push(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b != NULL)
	{
		set_positions(stack_b);
		set_positions(stack_a);
		set_targets(stack_a, stack_b, INT_MAX);
		set_costs(stack_a, stack_b);
		movement(stack_a, stack_b);
	}
}

void	rotate_till_sorted(t_stack **stack_a)
{
	int	flag;

	if (lowest_node(*stack_a) <= ft_stack_size(*stack_a) / 2)
		flag = 0;
	else
		flag = 1;
	while (is_ordered(*stack_a) != 1)
	{
		if (flag == 0)
			rotate_a(stack_a, 1);
		else
			rev_rotate_a(stack_a, 1);
	}
}
