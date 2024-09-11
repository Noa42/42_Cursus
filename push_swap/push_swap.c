/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:06:14 by achacon-          #+#    #+#             */
/*   Updated: 2024/03/20 13:15:21 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (start(argc, argv, &stack_a) == 1)
		return (1);
	else
	{
		if (two_nodes_case(&stack_a) == 0)
			return (0);
		keep_three_nodes(&stack_a, &stack_b);
		stack_a = order_a(stack_a);
		if (stack_b == NULL)
		{
			clear_stack(&stack_a);
			return (0);
		}
		sort_and_push(&stack_a, &stack_b);
		rotate_till_sorted(&stack_a);
	}
	clear_stack(&stack_a);
}
