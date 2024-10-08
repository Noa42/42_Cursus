/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <	achacon-@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:06:14 by achacon-          #+#    #+#             */
/*   Updated: 2024/10/02 02:40:18 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	if (ft_atoi(argv[1]) == 1)
	{
		one_philo_case(argv);
		return (0);
	}
	if (take_args(&data, argc, argv) != 0)
	{
		printf("Error: Invalid arguments\n");
		return (1);
	}
	if (init_data(&data) != 0)
	{
		free_traces(&data);
		return (1);
	}
	join_threads(&data);
	free_traces(&data);
	return (0);
}
