/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <	achacon-@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:06:14 by achacon-          #+#    #+#             */
/*   Updated: 2024/08/01 03:37:40 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_files(t_game *game)
{
	if (access("./sprites/floor.png", F_OK | R_OK) == -1)
		my_error("Loading error: floor.png not found", game);
	if (access("./sprites/wall.png", F_OK | R_OK) == -1)
		my_error("Loading error: wall.png not found", game);
	if (access("./sprites/player.png", F_OK | R_OK) == -1)
		my_error("Loading error: player.png not found", game);
	if (access("./sprites/collect.png", F_OK | R_OK) == -1)
		my_error("Loading error: collect.png not found", game);
	if (access("./sprites/exit.png", F_OK | R_OK) == -1)
		my_error("Loading error: exit.png not found", game);
}

void	load_png(t_game *game)
{
	game->texture = mlx_load_png("./sprites/floor.png");
	game->i_floor = mlx_texture_to_image(game->mlx_ptr, game->texture);
	mlx_delete_texture(game->texture);
	game->texture = mlx_load_png("./sprites/wall.png");
	game->i_wall = mlx_texture_to_image(game->mlx_ptr, game->texture);
	mlx_delete_texture(game->texture);
	game->texture = mlx_load_png("./sprites/player.png");
	game->i_player = mlx_texture_to_image(game->mlx_ptr, game->texture);
	mlx_delete_texture(game->texture);
	game->texture = mlx_load_png("./sprites/collect.png");
	game->i_collect = mlx_texture_to_image(game->mlx_ptr, game->texture);
	mlx_delete_texture(game->texture);
	game->texture = mlx_load_png("./sprites/exit.png");
	game->i_exit = mlx_texture_to_image(game->mlx_ptr, game->texture);
	mlx_delete_texture(game->texture);
	if (!game->i_floor || !game->i_wall || !game->i_player
		|| !game->i_collect || !game->i_exit)
		my_error("Error loading textures", game);
}

void	init_loading(t_game *game)
{
	game->mlx_ptr = mlx_init(game->map_width * IMG,
			game->map_height * IMG, "so_long", false);
	if (!game->mlx_ptr)
		my_error("Error initializing mlx", game);
	check_files(game);
	load_png(game);
}

void	paint_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			mlx_image_to_window(game->mlx_ptr, game->i_floor, j * IMG, i * IMG);
			if (game->map[i][j] == '1')
				mlx_image_to_window(game->mlx_ptr,
					game->i_wall, j * IMG, i * IMG);
			else if (game->map[i][j] == 'C')
				mlx_image_to_window(game->mlx_ptr,
					game->i_collect, j * IMG, i * IMG);
			else if (game->map[i][j] == 'E')
				mlx_image_to_window(game->mlx_ptr,
					game->i_exit, j * IMG, i * IMG);
			j++;
		}
		i++;
	}
}
