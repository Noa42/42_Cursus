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

void	*argos(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (check_alive(data) == 1)
		{
			pthread_mutex_lock(&data->mut_apocalypse);
			data->apocalypse = 1;
			pthread_mutex_unlock(&data->mut_apocalypse);
			break ;
		}
		if (check_full_tummy(data) == 1)
		{
			pthread_mutex_lock(&data->mut_apocalypse);
			data->apocalypse = 1;
			pthread_mutex_unlock(&data->mut_apocalypse);
			break ;
		}
	}
	return (NULL);
}

int	check_apocalypse(t_data *data)
{
	pthread_mutex_lock(&data->mut_apocalypse);
	if (data->apocalypse != 0)
	{
		pthread_mutex_unlock(&data->mut_apocalypse);
		return (1);
	}
	pthread_mutex_unlock(&data->mut_apocalypse);
	return (0);
}

int	check_alive(t_data *data)
{
	int		i;
	long	last_meal;

	i = 0;
	last_meal = 0;
	while (i < data->number_of_philos)
	{
		last_meal = store_last_meal(data->array_philos[i]);
		if (present_time(data->start_time) - last_meal > data->time_to_die)
		{
			safe_print(data->array_philos[i], 'd');
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_full_tummy(t_data *data)
{
	int	i;
	int	meals_eaten;
	int	full_philos;

	i = 0;
	meals_eaten = 0;
	full_philos = 0;
	while (i < data->number_of_philos)
	{
		pthread_mutex_lock(&data->array_philos[i]->mut_meals_eaten);
		meals_eaten = data->array_philos[i]->meals_eaten;
		pthread_mutex_unlock(&data->array_philos[i]->mut_meals_eaten);
		if (meals_eaten == data->number_of_meals)
			full_philos++;
		i++;
	}
	if (full_philos == data->number_of_philos)
		return (1);
	return (0);
}

long	store_last_meal(t_philo *philo)
{
	long	value;

	pthread_mutex_lock(&philo->mut_last_meal);
	value = philo->last_meal;
	pthread_mutex_unlock(&philo->mut_last_meal);
	return (value);
}
