/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:06:14 by achacon-          #+#    #+#             */
/*   Updated: 2024/03/20 15:13:39 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	integers(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '-')
			return (1);
		j++;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	max_and_min(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	duplicates(int argc, char **argv, int i_argv, int i_array)
{
	int	j;
	int	*array;

	j = 0;
	array = malloc(sizeof(int) * (argc - 1));
	while (i_argv < argc)
	{
		array[i_array] = ft_atoi(argv[i_argv]);
		while (j < i_array)
		{
			if (array[j] == array[i_array])
			{
				free (array);
				return (1);
			}
			j++;
		}
		i_argv++;
		i_array++;
		j = 0;
	}
	free (array);
	return (0);
}

int	errors(int argc, char **argv)
{
	if (integers(argc, argv) != 0)
		return (1);
	if (max_and_min(argc, argv) != 0)
		return (2);
	if (duplicates(argc, argv, 1, 0) != 0)
		return (3);
	return (0);
}
