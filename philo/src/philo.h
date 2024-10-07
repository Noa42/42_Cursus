/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <	achacon-@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 01:35:19 by achacon-          #+#    #+#             */
/*   Updated: 2024/10/02 01:44:13 by achacon-         ###   ########.fr       */
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
	pthread_mutex_t	mut_last_meal;
	long			last_meal;
	pthread_mutex_t	mut_meals_eaten;
	int				meals_eaten;
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_data			*data;
}	t_philo;

typedef struct s_fork
{
	int				index;
	int				is_taken;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_data
{
	long			start_time;
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meals;
	pthread_mutex_t	mut_apocalypse;
	pthread_mutex_t	mut_print;
	t_philo			**array_philos;
	t_fork			*array_forks;
	int				apocalypse;
}	t_data;

//ARGOS
void	*argos(void *arg);
int		check_apocalypse(t_data *data);
int		check_alive(t_data *data);
int		check_full_tummy(t_data *data);
long	store_last_meal(t_philo *philo);

//CLEAN
void	destroy_mutex(t_data *data);
void	free_structures(t_data *data);
void	free_traces(t_data *data);

//FORKS
int		create_forks(t_data *data);
void	take_forks_odd(t_philo *philo);
void	take_forks_even(t_philo *philo);
void	drop_forks(t_philo *philo);

//FT_ATOI
int		ft_atoi(const char *str);

//INIT
int		take_args(t_data *data, int argc, char **argv);
int		create_philosophers(t_data *data);
int		init_data(t_data *data);
t_philo	*a_philo_is_born(t_data *data, int i);
void	join_threads(t_data *data);

//ROUTINE
void	*routine(void *arg);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);

//ONE PHILO
void	one_philo_case(char **argv);

//UTILS
long	present_time(long start_time);
void	safe_print(t_philo *philo, char s);
void	update_last_meal(t_philo *philo);
void	update_meals_eaten(t_philo *philo);

#endif