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

long	present_time(long start_time)
{
	struct timeval	time;
	long			temp;

	gettimeofday(&time, NULL);
	temp = (time.tv_sec * 1000 + time.tv_usec / 1000);
	return (temp - start_time);
}

void	safe_print(t_philo *philo, char c)
{
	char	*s;

	if (c == 'd')
		s = "died";
	else if (c == 'e')
		s = "is eating";
	else if (c == 't')
		s = "is thinking";
	else if (c == 's')
		s = "is sleeping";
	else if (c == 'l')
		s = "has taken their left fork";
	else if (c == 'r')
		s = "has taken their right fork";
	if (check_apocalypse(philo->data) == 1)
		return ;
	pthread_mutex_lock(&philo->data->mut_print);
	printf("At time %ld ms: Philo: %i %s\n", \
	present_time(philo->data->start_time), philo->id, s);
	pthread_mutex_unlock(&philo->data->mut_print);
	if (check_apocalypse(philo->data) == 1)
		return ;
}

void	update_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_last_meal);
	philo->last_meal = present_time(philo->data->start_time);
	pthread_mutex_unlock(&philo->mut_last_meal);
}

void	update_meals_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_meals_eaten);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->mut_meals_eaten);
}
