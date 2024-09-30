/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <	achacon-@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 01:35:19 by achacon-          #+#    #+#             */
/*   Updated: 2024/09/30 03:26:26 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_fork	t_fork;
typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

typedef struct s_philo
{
	int				index;//índice en el array, empieza en cero
	int				id; //id del filósofo a la hora de imprimir, empieza en 1.
	pthread_t		thread;
	pthread_mutex_t mut_last_meal;
	long	last_meal;
	pthread_mutex_t mut_meals_eaten;
	int				meals_eaten;
	t_fork	*left_fork;
	t_fork	*right_fork;
	t_data			*data;
}	t_philo;

typedef struct s_fork
{
	int	index;
	int is_taken;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_data
{
	int	number_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_meals;
	pthread_mutex_t	mut_apocalypse;
	t_philo	*array_philos;
	t_fork	*array_forks;
	int	apocalypse;
}	t_data;


//UTILS
int	ft_atoi(const char *str);
void free_array (void *array, int size);

#endif