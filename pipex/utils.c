/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:14:24 by achacon-          #+#    #+#             */
/*   Updated: 2024/05/02 18:58:09 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (s[i] != 0)
	{
		write(fd, &s[i], sizeof(s[i]));
		i++;
	}
}

void	close_pipes(t_store store)
{
	close(store.pipe[0]);
	close(store.pipe[1]);
}

void	ending(t_store store)
{
	free_array(store.array_cmd1);
	free_array(store.array_cmd2);
	close_pipes(store);
}
