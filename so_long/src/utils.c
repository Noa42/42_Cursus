/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 01:35:35 by achacon-          #+#    #+#             */
/*   Updated: 2024/08/02 12:26:17 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	memory(t_game *game)
{
	if (game->map)
		free_array(game->map);
	if (game->i_floor)
		mlx_delete_image(game->mlx_ptr, game->i_floor);
	if (game->i_player)
		mlx_delete_image(game->mlx_ptr, game->i_player);
	if (game->i_collect)
		mlx_delete_image(game->mlx_ptr, game->i_collect);
	if (game->i_wall)
		mlx_delete_image(game->mlx_ptr, game->i_wall);
	if (game->i_exit)
		mlx_delete_image(game->mlx_ptr, game->i_exit);
	if (game->mlx_ptr)
		mlx_terminate(game->mlx_ptr);
	if (game)
		free(game);
}

void	my_error(char *s, t_game *game)
{
	ft_printf("%s\n", s);
	memory(game);
	exit(1);
}

void	print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_printf("%s --%i\n", array[i], i);
		i++;
	}
}

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
