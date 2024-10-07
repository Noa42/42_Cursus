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

int	take_args(t_data *data, int argc, char **argv)
{
	data->number_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->array_forks = NULL;
	data->array_philos = NULL;
	data -> apocalypse = 0;
	data->start_time = 0;
	if (argc == 6)
	{
		data->number_of_meals = ft_atoi(argv[5]);
		if (data->number_of_meals < 1)
			return (1);
	}
	else
		data->number_of_meals = -1;
	if (data->number_of_philos <= 1 || data->number_of_philos > 200
		|| data->time_to_die < 60 || data->time_to_eat < 60
		|| data->time_to_sleep < 60)
		return (1);
	return (0);
}

int	init_data(t_data *data)
{
	if (pthread_mutex_init(&data->mut_apocalypse, NULL) != 0
		|| pthread_mutex_init(&data->mut_print, NULL) != 0)
	{
		printf("Error: Can't init data mutexes\n");
		return (1);
	}
	data->start_time = present_time(data->start_time);
	if (create_forks(data) != 0)
	{
		printf("Error: Can't create forks\n");
		return (1);
	}
	if (create_philosophers(data) != 0)
	{
		printf("Error: Can't create philosophers\n");
		return (1);
	}
	return (0);
}

int	create_philosophers(t_data *data)
{
	int			i;
	pthread_t	argos_thread;

	data->array_philos = malloc(sizeof(t_philo) * data->number_of_philos);
	i = 0;
	while (i < data->number_of_philos)
	{
		data->array_philos[i] = a_philo_is_born(data, i);
		i++;
	}
	pthread_create(&argos_thread, NULL, &argos, (void *)data);
	pthread_join(argos_thread, NULL);
	return (0);
}

t_philo	*a_philo_is_born(t_data *data, int i)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	philo->index = i;
	philo->id = i + 1;
	philo->data = data;
	philo->meals_eaten = 0;
	pthread_mutex_init(&philo->mut_last_meal, NULL);
	pthread_mutex_init(&philo->mut_meals_eaten, NULL);
	update_last_meal(philo);
	philo->left_fork = &data->array_forks[i];
	if (i + 1 == data->number_of_philos)
		philo->right_fork = &data->array_forks[0];
	else
		philo->right_fork = &data->array_forks[i + 1];
	pthread_create(&philo->thread, NULL, &routine, (void *)philo);
	return (philo);
}

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		if (pthread_join(data->array_philos[i]->thread, NULL) != 0)
		{
			printf("Error: Can't join philosopher number %i\n",
				data->array_philos[i]->id);
			return ;
		}
		i++;
	}
}
