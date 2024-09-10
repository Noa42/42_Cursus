/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:15:56 by achacon-          #+#    #+#             */
/*   Updated: 2024/05/05 11:35:45 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path_line(char **env)
{
	char	*path_line;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			path_line = env[i];
		i++;
	}
	path_line = path_line + 5;
	return (path_line);
}

char	*get_path(char *command, char **env)
{
	char	*path_line;
	char	**path_array;
	char	*path_final;
	int		i;
	char	*temp;

	i = 0;
	if (command[0] == '/')
		return (command);
	path_line = get_path_line(env);
	path_array = ft_split(path_line, ':');
	while (path_array[i])
	{
		temp = ft_strjoin(path_array[i], "/");
		path_final = ft_strjoin(temp, command);
		free(temp);
		if (access(path_final, F_OK) == 0)
			return (path_final);
		free(path_final);
		i++;
	}
	free_array(path_array);
	return (NULL);
}

void	child(t_store store, char **env)
{
	char	*temp;

	store.in_fd = open(store.in_name, O_RDONLY);
	if (store.in_fd == -1)
	{
		ending(store);
		ft_putstr_fd("Input file error\n", 2);
		exit(1);
	}
	dup2(store.in_fd, STDIN_FILENO);
	dup2(store.pipe[1], STDOUT_FILENO);
	close(store.pipe[0]);
	temp = get_path(store.array_cmd1[0], env);
	if (temp == NULL)
	{
		free(temp);
		ending(store);
		ft_putstr_fd("Command 1 not found\n", 2);
		exit(1);
	}
	execve(temp, store.array_cmd1, env);
}

void	parent(t_store store, char **env)
{
	char	*temp;

	wait(NULL);
	store.out_fd = open(store.out_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (store.out_fd == -1)
	{
		ending(store);
		ft_putstr_fd("Open function error\n", 2);
		exit(1);
	}
	dup2(store.pipe[0], STDIN_FILENO);
	close(store.pipe[1]);
	dup2(store.out_fd, STDOUT_FILENO);
	temp = get_path(store.array_cmd2[0], env);
	if (temp == NULL)
	{
		free(temp);
		ending(store);
		ft_putstr_fd("Command 2 not found\n", 2);
		exit(1);
	}
	execve(temp, store.array_cmd2, env);
}
