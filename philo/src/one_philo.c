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

void	one_philo_case(char **argv)
{
	long	start_time;
	int		time_to_die;

	time_to_die = ft_atoi(argv[2]);
	start_time = present_time(0);
	printf("At time %ld ms: Philosopher 1 has taken their left fork\n",
		present_time(start_time));
	while (1)
	{
		usleep(1);
		if (present_time(start_time) > time_to_die)
			break ;
	}
	printf("At time %ld ms: Philosopher 1 died\n", present_time(start_time));
}
