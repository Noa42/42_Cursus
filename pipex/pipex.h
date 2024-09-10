/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:58:47 by achacon-          #+#    #+#             */
/*   Updated: 2024/05/05 11:47:23 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include "memory_leaks.h"

typedef struct s_store
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipe[2];
	char	*in_name;
	char	*out_name;
	int		in_fd;
	int		out_fd;
	char	**array_cmd1;
	char	**array_cmd2;
}	t_store;

//LIBFT
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char const c);
char	*ft_strjoin(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);

//UTILS

void	print_array(char **p);
void	free_array(char **array);
void	print_store(t_store store);
void	close_pipes(t_store store);
void	ending(t_store store);

//PROCESS
char	*get_path(char *command, char **env);
void	child(t_store store, char **env);
void	parent(t_store store, char **env);
#endif