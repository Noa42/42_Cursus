/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:19:06 by achacon-          #+#    #+#             */
/*   Updated: 2024/05/02 18:57:23 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_store	store;
	pid_t	pid;

	if (argc != 5)
	{
		ft_putstr_fd("Wrong argument number\n", 2);
		ft_putstr_fd("Usage: infile cmd1 cmd1 outfile\n", 2);
		return (1);
	}
	if (pipe(store.pipe) == -1)
	{
		ft_putstr_fd("Pipe function error\n", 2);
		return (1);
	}
	store.in_name = argv[1];
	store.out_name = argv[4];
	store.array_cmd1 = ft_split(argv[2], ' ');
	store.array_cmd2 = ft_split(argv[3], ' ');
	pid = fork();
	if (pid == 0)
		child(store, env);
	else
		parent(store, env);
	return (0);
}
