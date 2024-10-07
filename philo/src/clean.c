/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <	achacon-@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:06:14 by achacon-          #+#    #+#             */
/*   Updated: 2024/08/13 02:29:18 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	if (data)
	{
		pthread_mutex_destroy(&data->mut_apocalypse);
		pthread_mutex_destroy(&data->mut_print);
	}
	if (data->array_forks != NULL)
	{
		while (i < data->number_of_philos)
		{
			pthread_mutex_destroy(&data->array_forks[i].mutex);
			i++;
		}
	}
	if (data->array_philos != NULL)
	{
		while (i < data->number_of_philos)
		{
			pthread_mutex_destroy(&data->array_philos[i]->mut_meals_eaten);
			pthread_mutex_destroy(&data->array_philos[i]->mut_last_meal);
			i++;
		}
	}
}

void	free_structures(t_data *data)
{
	int	i;

	i = 0;
	if (data->array_philos != NULL)
	{
		while (i < data->number_of_philos)
		{
			free(data->array_philos[i]);
			i++;
		}
		free(data->array_philos);
	}
	if (data->array_forks != NULL)
		free(data->array_forks);
}

void	free_traces(t_data *data)
{
	destroy_mutex(data);
	free_structures(data);
}
