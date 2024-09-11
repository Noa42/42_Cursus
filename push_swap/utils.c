/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:06:14 by achacon-          #+#    #+#             */
/*   Updated: 2024/03/20 12:45:34 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered(t_stack *head)
{
	int		result;
	t_stack	*p_i;
	t_stack	*p_j;

	result = 1;
	p_i = head;
	while (p_i != NULL)
	{
		p_j = p_i -> next;
		while (p_j != NULL)
		{
			if ((p_i -> value) > (p_j -> value))
				return (0);
			p_j = p_j -> next;
		}
		p_i = p_i -> next;
	}
	return (result);
}

int	mean(t_stack *head)
{
	t_stack	*p;
	int		total;

	total = 0;
	p = head;
	while (p != NULL)
	{
		total = total + p -> value;
		p = p -> next;
	}
	return (total / ft_stack_size(head));
}

int	is_highest(int n, t_stack **head)
{
	t_stack	*p;
	int		max;

	p = *head;
	max = 0;
	while (p != NULL)
	{
		if (p -> value > max)
			max = p -> value;
		p = p -> next;
	}
	if (max > n)
		return (0);
	else
		return (1);
}

int	array_len(char **s)
{
	int		i;

	i = 0;
	while (s[i] != NULL)
	{
		i++;
	}
	return (i);
}

char	**erase(char **array, int i)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
	return (NULL);
}
