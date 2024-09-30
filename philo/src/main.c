/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <	achacon-@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:06:14 by achacon-          #+#    #+#             */
/*   Updated: 2024/09/30 04:23:48 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long present_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int create_forks(t_data *data)
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

int	initial_data(t_data *data, int argc, char **argv)
{
	data->number_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data -> apocalypse = 0;
	if (argc == 6)
	{
		data->number_of_meals = ft_atoi(argv[5]);
	}
	else
		data->number_of_meals = -1;//como flag de que no hay veces para comer? si no borrarlo
	if (data->number_of_philos <= 1 || data->number_of_philos > 200
		|| data->time_to_die < 60 || data->time_to_eat < 60
		|| data->time_to_sleep < 60)
		return (1);
	pthread_mutex_init(&data->mut_apocalypse, NULL);
	return (0);
}

int check_apocalypse(t_data *data)
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

void	take_forks(t_philo *philo)
{
	if(check_apocalypse(philo->data) == 1)
		return;
	pthread_mutex_lock(&philo->left_fork->mutex);
	philo->left_fork->is_taken = 1;
	printf("At time %ld ms: Philosopher %i has taken their left fork\n",present_time(), philo->id);
	pthread_mutex_lock(&philo->right_fork->mutex);
	if(check_apocalypse(philo->data) == 1)
		return;
	philo->right_fork->is_taken = 1;
	printf("At time %ld ms: Philosopher %i has taken their right fork\n",present_time(), philo->id);
}
void drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->left_fork->mutex);
	philo->left_fork->is_taken = 0;
	pthread_mutex_unlock(&philo->right_fork->mutex);
	philo->right_fork->is_taken = 0;
}

void update_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_last_meal);
	philo->last_meal = present_time();
	printf("Philo %i, Update Last meal is %ld\n", philo->id, philo->last_meal);
	pthread_mutex_unlock(&philo->mut_last_meal);
}

void update_meals_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_meals_eaten);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->mut_meals_eaten);
}
void eating(t_philo *philo)
{
	int i;
	i = 0;
	if (check_apocalypse(philo->data) == 1)
		return;
	if(philo->id % 2 == 0)
		usleep(10);
	take_forks(philo);
	if (check_apocalypse(philo->data) == 1)
		return;
	printf("At time %ld ms: Philosopher %i is eating\n",present_time(), philo->id);
	update_last_meal(philo);
	update_meals_eaten(philo);
	//printf("Philo %i, Update Last meal is %ld\n", philo->id, philo->last_meal);
	//usleep(philo->data->time_to_eat * 1000);
	while(i < philo->data->time_to_eat)
	{
		usleep(100);
		if (check_apocalypse(philo->data) == 1)
			break;
		i = i + 100;
	}
	drop_forks(philo);
}
void sleeping(t_philo *philo)
{
	int i;

	i = 0;
	if (check_apocalypse(philo->data) == 1)
		return;
	printf("At time %ld ms: Philosopher %i is sleeping\n",present_time(), philo->id);
	//usleep(philo->data->time_to_sleep * 1000);
	while(i < philo->data->time_to_sleep)
	{
		usleep(100);
		if (check_apocalypse(philo->data) == 1)
			break;
		i = i + 100;
	}
}
void thinking(t_philo *philo)
{
	if (check_apocalypse(philo->data) == 1)
		return;
	printf("At time %ld ms: Philosopher %i is thinking\n",present_time(), philo->id);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	philo = (t_philo *)arg;
	printf("At time %ld ms: Hello from philosopher number %i\n",present_time(), philo->id);
	//update_last_meal(philo);
	while (check_apocalypse(philo->data) == 0)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

t_philo *a_philo_is_born(t_data*data, int i)
{
	t_philo *philo;

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
		philo->right_fork = &data->array_forks[i + 1];//esto es para que el último filósofo coja el primer tenedor
	pthread_create(&philo->thread, NULL, &routine, (void*)philo);
	return (philo);

}
long store_last_meal(t_philo philo)
{
	long value;
	pthread_mutex_lock(&philo.mut_last_meal);
	value = philo.last_meal;
	pthread_mutex_unlock(&philo.mut_last_meal);
	return (value);
}
void print_philo(t_philo philo)
{
	pthread_mutex_lock(&philo.mut_meals_eaten);
	pthread_mutex_lock(&philo.mut_last_meal);
	printf("Philo %i, Last meal is %ld\n", philo.id, philo.last_meal);
	printf("Philo %i, Meals eaten is %i\n", philo.id, philo.meals_eaten);
	pthread_mutex_unlock(&philo.mut_last_meal);
	pthread_mutex_unlock(&philo.mut_meals_eaten);
}
void print_philos(t_data *data)
{
	printf("Printing philos\n");
	int i = 0;
	while (i < data->number_of_philos)
	{
		print_philo(data->array_philos[i]);
		printf("\n");
		i++;
	}
}

int check_alive(t_data *data)
{
	int i = 0;

	long last_meal = 0;
	while (i < data->number_of_philos)
	{
		last_meal = store_last_meal(data->array_philos[i]);
		if(present_time() - last_meal > data->time_to_die)
		{
			printf("Last meal es %ld\n", last_meal);
			printf("Muerte: Philo: %i -- El lapso es %ld\n", data->array_philos[i].id, present_time() - last_meal);
			print_philos(data);
			pthread_mutex_lock(&data->array_philos[i].mut_meals_eaten);
			printf("Meals eaten: %i\n", data->array_philos[i].meals_eaten);
			pthread_mutex_unlock(&data->array_philos[i].mut_meals_eaten);
			return (1);
		}
		pthread_mutex_unlock(&data->array_philos[i].mut_last_meal);
		i++;
	}
	return (0);
}

void *argos(void *arg)
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
			//gestionar memoria
			break;
		}
 		//aqui poner checker de si han comido todo lo que debían. No entiendo si es el numero de comidas totales o por filosofo
	}
	return (NULL);
}

int	create_philosophers(t_data *data)
{
	int i;
	pthread_t argos_thread;

	data->array_philos = malloc(sizeof(t_philo) * data->number_of_philos);//creo que esto debería ser sizeof(t_philo) * data->number_of_philos pero si lo pongo asi no me funciona
	i = 0;
	while (i < data->number_of_philos)
	{
		data->array_philos[i] = *a_philo_is_born(data, i);
		usleep(10);//Esto es para que no se me creen dos hilos con el mismo id
		i++;
	}
	pthread_create(&argos_thread, NULL, &argos, (void*)data);
	return (0);
}


int	main (int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	if (initial_data(&data, argc, argv) != 0)
	{
		printf("Error: Invalid arguments\n");
		return (1);
	}
	if (create_forks(&data) != 0)
	{
		printf("Error: Can't create forks\n");
		return (1);
	}
	if (create_philosophers(&data) != 0)
	{
		printf("Error: Can't create philosophers\n");
		return (1);
	}

	//El join se puede hacer en la misma función create philosophers
	int i = 0;
	while (i < data.number_of_philos)
	{
		if (pthread_join(data.array_philos[i].thread, NULL) != 0)
		{
			printf("Error: Can't join philosopher number %i\n", data.array_philos[i].id);
			//free_array((void*)&philos, data->number_of_philosophers);
			return (1);
		}
		i++;
	}
 }
