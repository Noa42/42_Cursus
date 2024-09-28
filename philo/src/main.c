/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <	achacon-@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:06:14 by achacon-          #+#    #+#             */
/*   Updated: 2024/09/28 02:42:31 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	time_lapse(struct timeval start, struct timeval end)
{
	long	time;

	time = (end.tv_sec - start.tv_sec) * 1000;
	time = time + (end.tv_usec - start.tv_usec) / 1000;
	return (time);
}
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
	data->dead_flag = 0;
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
	pthread_mutex_init(&data->dead_mutex, NULL);
	return (0);
}

int check_apocalypse(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead_mutex);
	if (philo->data->dead_flag != 0)
	{
		//printf("philo id %i sabe que hay apocalipsis\n", philo->id);
		pthread_mutex_unlock(&philo->data->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->dead_mutex);
	return (0);
}

int eating (t_philo *philo)
{
	int i = 0;
	if (check_apocalypse(philo) == 1)
	{
		printf("philo id %i apocalipsis en eating 1\n", philo->id);
		return (0);
	}
	pthread_mutex_lock(&philo->left_fork->mutex);
	philo->left_fork->is_taken = 1;
	//printf("Before left fork philo id %i apocalypse %i\n", philo->id, check_apocalypse(philo));
	if (check_apocalypse(philo) == 1)
	{
		printf("philo id %i apocalipsis en eating 2\n", philo->id);
		return (0);
	}
	printf("At time %ld ms: Philosopher %i has taken their left fork\n",present_time(), philo->id);
	pthread_mutex_lock(&philo->right_fork->mutex);
	philo->right_fork->is_taken = 1;
	if (check_apocalypse(philo) == 1)
	{
		printf("philo id %i apocalipsis en eating 3\n", philo->id);
		return (0);
	}
	printf("At time %ld ms: Philosopher %i has taken their right fork\n",present_time(), philo->id);
	if (check_apocalypse(philo) == 1)
	{
		printf("philo id %i apocalipsis en eating 4\n", philo->id);
		return (0);
	}
	// Hacer la comprobacion de muerte aqui me da un problema
	//Si cuando el philo 3 va a comer y resulta que se muere los otros filosofos han estado haciendo cosas hasta el momento de la muerte
	gettimeofday(&philo->end, NULL);
	if (time_lapse(philo->start, philo->end) > philo->data->time_to_die)
	{
		printf("At time %ld ms: Philosopher %i died\n",present_time(), philo -> id);
		pthread_mutex_lock(&philo->data->dead_mutex);
		philo->data->dead_flag = philo->id;
		pthread_mutex_unlock(&philo->data->dead_mutex);

	}
	if (check_apocalypse(philo) == 1)
	{
		printf("philo id %i apocalipsis en eating 5\n", philo->id);
		return (0);
	}
	printf("At time %ld ms: Philosopher %i is eating\n",present_time(), philo->id);
	gettimeofday(&philo->start, NULL);
	while(i < philo->data->time_to_eat)
	{
		usleep(1);
		if (check_apocalypse(philo) == 1)
		{
			printf("philo id %i apocalipsis en eating 6\n", philo->id);
			return (0);
		}
		i++;
	}
	//usleep(philo->data->time_to_eat * 1000);// aqui
	pthread_mutex_unlock(&philo->left_fork->mutex);
	philo->left_fork->is_taken = 0;
	pthread_mutex_unlock(&philo->right_fork->mutex);
	philo->right_fork->is_taken = 0;
	philo->meals_eaten++;
	if (philo->meals_eaten == philo->data->number_of_meals)
	{
		philo->is_full = 1;
	}
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int i;

	philo = (t_philo *)arg;
	printf("At time %ld ms: Hello from philosopher number %i\n",present_time(), philo->id);
	gettimeofday(&philo->start, NULL);
	while (philo-> is_full == 0)
	{
		i = 0;
		if (philo->left_fork->is_taken == 0 && philo->right_fork->is_taken == 0)
		{
			if (check_apocalypse(philo) == 1)
			{
				printf("philo id %i apocalipsis en routine 1\n", philo->id);
				break;
			}
			if(eating(philo) == 0)
				break;
			if (check_apocalypse(philo) == 1)
			{
				printf("philo id %i apocalipsis en routine 2\n", philo->id);
				break;
			}
			printf("At time %ld ms: Philosopher %i is sleeping\n",present_time(), philo->id);
			while(i < philo->data->time_to_sleep)
			{
				usleep(1);
				if (check_apocalypse(philo) == 1)
				{
					printf("philo id %i apocalipsis en routine 3\n", philo->id);
					break;
				}
				i++;
			}
			//usleep(philo->data->time_to_sleep * 1000);
			philo->is_thinking = 0;
		}
		else if (philo->is_thinking == 0)
		{
			if (check_apocalypse(philo) == 1)
			{
				printf("philo id %i apocalipsis en routine 4\n", philo->id);
				break;
			}
			printf("At time %ld ms: Philosopher %i is thinking\n",present_time(), philo->id);
			philo->is_thinking = 1;
		}
			if (check_apocalypse(philo) == 1)
			{
				printf("philo id %i apocalipsis en routine 5\n", philo->id);
				break;
			}
	}
	return (NULL);
}


void	print_data(t_data *data)
{
	printf("number_of_philos: %d\n", data->number_of_philos);
	printf("time_to_die: %d\n", data->time_to_die);
	printf("time_to_eat: %d\n", data->time_to_eat);
	printf("time_to_sleep: %d\n", data->time_to_sleep);
	printf("number_of_meals: %d\n", data->number_of_meals);
}
t_philo *a_philo_is_born(t_data*data, int i)
{
	t_philo *philo;

	philo = malloc(sizeof(t_philo));
	philo->index = i;
	philo->id = i + 1;
	philo->data = data;
	philo->meals_eaten = 0;
	philo->is_full = 0;
	philo->is_thinking = 0;
	philo->apocalypse = 0;
	philo->left_fork = &data->array_forks[i];
	if (i + 1 == data->number_of_philos)
		philo->right_fork = &data->array_forks[0];
	else
		philo->right_fork = &data->array_forks[i + 1];//esto es para que el último filósofo coja el primer tenedor
	pthread_create(&philo->thread, NULL, &routine, (void*)philo);
	return (philo);

}

void apocalypse(t_data *data)
{
	int i = 0;

	while (i < data->number_of_philos)
	{
		data->array_philos[i].apocalypse = 1;
		i++;
	}
}
void printpocalypse(t_data *data)
{
int i = 0;

	while (i < data->number_of_philos)
	{
		printf("Philosopher %i is apocalypse: %i\n", data->array_philos[i].id, data->array_philos[i].apocalypse);
		i++;
	}
}

void *argos(void *arg)
{
	t_data	*data;
	int i = 0;

	data = (t_data *)arg;
	while (1)
	{
		pthread_mutex_lock(&data->dead_mutex);
		if (data->dead_flag != 0)
		{
			//printf("At time %ld ms: Philosopher %i died\n",present_time(), data->dead_flag);
			pthread_mutex_unlock(&data->dead_mutex);
			//apocalypse(data);
			//printpocalypse(data);
			//poner función que libere memoria (igual abajo cuando están todos llenos)
			return (NULL);
		}
		pthread_mutex_unlock(&data->dead_mutex);
		if (data->number_of_meals != -1)
		{
			i = 0;
			while (i < data->number_of_philos)
			{
				if (data->array_philos[i].is_full == 0)
					break;
				i++;
			}
			if (i == data->number_of_philos)
			{
				printf("All philosophers have eaten %i times\n", data->number_of_meals);
				return (NULL);
			}
		}
	}
}

int	create_philosophers(t_data *data)
{
	int i;
	pthread_t argos_thread;
	pthread_create(&argos_thread, NULL, &argos, (void*)data);
	data->array_philos = malloc(sizeof(t_philo) * data->number_of_philos);//creo que esto debería ser sizeof(t_philo) * data->number_of_philos pero si lo pongo asi no me funciona
	i = 0;
	while (i < data->number_of_philos)
	{
		data->array_philos[i] = *a_philo_is_born(data, i);
		usleep(10);//Esto es para que no se me creen dos hilos con el mismo id
		i++;
	}
	return (0);
}

void print_forks(t_data *data)
{
	int i;

	i = 0;
	while (i < data->number_of_philos)
	{
		printf("Fork %i is taken: %i\n", data->array_forks[i].index, data->array_forks[i].is_taken);
		i++;
	}
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
	print_data(&data);
	if (create_forks(&data) != 0)
	{
		printf("Error: Can't create forks\n");
		return (1);
	}
	//print_forks(&data);
	if (create_philosophers(&data) != 0)
	{
		printf("Error: Can't create philosophers\n");
		return (1);
	}

	//Esto lo he quitado porque en principio con detach no hace falta hacer join
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
