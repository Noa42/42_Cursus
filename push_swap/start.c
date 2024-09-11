/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:06:14 by achacon-          #+#    #+#             */
/*   Updated: 2024/03/20 17:23:52 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	start(int argc, char **argv, t_stack **stack_a)
{
	int	flag;

	flag = 1;
	if (argc < 2)
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = array_len(argv);
		flag = 0;
	}
	if (errors(argc, argv) != 0 || argc < 2)
	{
		if (flag == 0)
			erase(argv, argc - 1);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	*stack_a = take_arg(argc, argv, flag);
	if (flag == 0)
		erase(argv, argc - 1);
	set_positions(stack_a);
	return (0);
}

int	two_nodes_case(t_stack **stack_a)
{
	if (is_ordered(*stack_a) == 1)
	{
		clear_stack(stack_a);
		return (0);
	}
	else if (ft_stack_size(*stack_a) < 3)
	{
		swap_a(stack_a);
		clear_stack(stack_a);
		return (0);
	}
	else
		return (1);
}

t_stack	*take_arg(int argc, char **argv, int flag)
{
	int		i;
	t_stack	*head;
	t_stack	*node;

	i = flag;
	head = ft_stack_new(ft_atoi(argv[i]));
	i++;
	while (i < argc)
	{
		node = ft_stack_new(ft_atoi(argv[i]));
		ft_stack_add_back(&head, node);
		i++;
	}
	return (head);
}
