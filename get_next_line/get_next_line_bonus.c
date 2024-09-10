/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:40:34 by achacon-          #+#    #+#             */
/*   Updated: 2023/12/17 11:33:23 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_buffer(char **store, int fd)
{
	char	*buffer;
	int		end;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE +1));
	if (buffer == NULL)
		return (-1);
	while (ft_nl(*store) == -1)
	{
		end = read(fd, buffer, BUFFER_SIZE);
		if (end < 0)
		{
			free (*store);
			*store = NULL;
			free (buffer);
			return (0);
		}
		buffer[end] = '\0';
		if (end == 0)
			break ;
		*store = ft_strjoin(*store, buffer);
	}
	free(buffer);
	return (end);
}

char	*get_next_line(int fd)
{
	static char	*store [1024];
	int			end;
	char		*result;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	end = ft_buffer(&store[fd], fd);
	if (store[fd] == NULL || end == -1)
		return (NULL);
	result = ft_first_line(store[fd]);
	if (result == NULL)
	{
		free(store[fd]);
		store[fd] = NULL;
		return (NULL);
	}
	store[fd] = ft_substr(store[fd], ft_nl(store[fd]) + 1, \
	ft_strlen(store[fd]) - ft_nl(store[fd]));
	if (end == 0)
	{
		free(store[fd]);
		store[fd] = NULL;
	}
	return (result);
}
