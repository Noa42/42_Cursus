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

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (check_apocalypse(philo->data) == 0)
	{
		eating(philo);
		if (check_apocalypse(philo->data) == 1)
			break ;
		if (philo->meals_eaten == philo->data->number_of_meals)
			break ;
		sleeping(philo);
		if (check_apocalypse(philo->data) == 1)
			break ;
		thinking(philo);
		if (check_apocalypse(philo->data) == 1)
			break ;
	}
	return (NULL);
}

void	eating(t_philo *philo)
{
	long	end_eating_time;

	if (check_apocalypse(philo->data) == 1)
		return ;
	if (philo->id % 2 == 0)
		take_forks_even(philo);
	else
		take_forks_odd(philo);
	if (check_apocalypse(philo->data) == 1)
		return ;
	safe_print(philo, 'e');
	update_last_meal(philo);
	update_meals_eaten(philo);
	end_eating_time = present_time \
	(philo->data->start_time) + philo->data->time_to_eat;
	while (present_time(philo->data->start_time) < end_eating_time)
	{
		if (check_apocalypse(philo->data) == 1)
			break ;
		usleep(1);
	}
	drop_forks(philo);
}

void	sleeping(t_philo *philo)
{
	long	end_sleeping_time;

	if (check_apocalypse(philo->data) == 1)
		return ;
	safe_print(philo, 's');
	end_sleeping_time = present_time(philo->data->start_time) + \
	philo->data->time_to_sleep;
	while (present_time(philo->data->start_time) < end_sleeping_time)
	{
		if (check_apocalypse(philo->data) == 1)
			break ;
		usleep(1);
	}
}

void	thinking(t_philo *philo)
{
	if (check_apocalypse(philo->data) == 1)
		return ;
	safe_print(philo, 't');
}
