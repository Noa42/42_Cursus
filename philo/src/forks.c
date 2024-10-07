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

int	create_forks(t_data *data)
{
	int	i;

	i = 0;
	data->array_forks = malloc(sizeof(t_fork) * data->number_of_philos);
	while (i < data->number_of_philos)
	{
		data->array_forks[i].index = i;
		data->array_forks[i].is_taken = 0;
		if (pthread_mutex_init(&data->array_forks[i].mutex, NULL) != 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	take_forks_odd(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->mutex);
	philo->left_fork->is_taken = 1;
	if (check_apocalypse(philo->data) == 1)
	{
		pthread_mutex_unlock(&philo->left_fork->mutex);
		return ;
	}
	safe_print(philo, 'l');
	pthread_mutex_lock(&philo->right_fork->mutex);
	philo->right_fork->is_taken = 1;
	if (check_apocalypse(philo->data) == 1)
	{
		pthread_mutex_unlock(&philo->left_fork->mutex);
		pthread_mutex_unlock(&philo->right_fork->mutex);
		return ;
	}
	safe_print(philo, 'r');
}

void	take_forks_even(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork->mutex);
	philo->right_fork->is_taken = 1;
	if (check_apocalypse(philo->data) == 1)
	{
		pthread_mutex_unlock(&philo->right_fork->mutex);
		return ;
	}
	safe_print(philo, 'r');
	pthread_mutex_lock(&philo->left_fork->mutex);
	philo->left_fork->is_taken = 1;
	if (check_apocalypse(philo->data) == 1)
	{
		pthread_mutex_unlock(&philo->left_fork->mutex);
		pthread_mutex_unlock(&philo->right_fork->mutex);
		return ;
	}
	safe_print(philo, 'l');
}

void	drop_forks(t_philo *philo)
{
	philo->left_fork->is_taken = 0;
	pthread_mutex_unlock(&philo->left_fork->mutex);
	philo->right_fork->is_taken = 0;
	pthread_mutex_unlock(&philo->right_fork->mutex);
}
