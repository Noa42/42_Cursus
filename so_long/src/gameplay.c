/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:06:14 by achacon-          #+#    #+#             */
/*   Updated: 2024/08/02 12:24:06 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update(t_game *game)
{
	game->move_counter ++;
	ft_printf("Kirby's moves: %i\n", game->move_counter);
	if (game->map[game->player_y][game->player_x] == 'C')
	{
		game->collected ++;
		ft_printf("Kirby ate %i oniguiri\n", game->collected);
		game->map[game->player_y][game->player_x] = '0';
		mlx_image_to_window(game->mlx_ptr, game->i_floor,
			game->player_x * IMG, game->player_y * IMG);
		mlx_delete_image(game->mlx_ptr, game->i_player);
		game->texture = mlx_load_png("./sprites/player.png");
		game->i_player = mlx_texture_to_image(game->mlx_ptr, game->texture);
		mlx_delete_texture(game->texture);
		mlx_image_to_window(game->mlx_ptr, game->i_player,
			game->player_x * IMG, game->player_y * IMG);
		if (game->collected == game->count_collect)
			ft_printf("Kirby ate all the oniguiri! Return to Dreamland :D\n");
	}
	if (game->map[game->player_y][game->player_x] == 'E'
		&& game->collected == game->count_collect)
	{
		ft_printf("Congratulations!!! You did really well sweetheart <3\n");
		memory(game);
		exit(0);
	}
}

void	move(char m, t_game *game)
{
	if (m == 'U' && game->map[game->player_y - 1][game->player_x] != '1')
	{
		(game->i_player)->instances[0].y -= IMG;
		game->player_y --;
		update(game);
	}
	if (m == 'D' && game->map[game->player_y + 1][game->player_x] != '1')
	{
		(game->i_player)->instances[0].y += IMG;
		game->player_y ++;
		update(game);
	}
	if (m == 'L' && game->map[game->player_y][game->player_x - 1] != '1')
	{
		(game->i_player)->instances[0].x -= IMG;
		game->player_x --;
		update(game);
	}
	if (m == 'R' && game->map[game->player_y][game->player_x + 1] != '1')
	{
		(game->i_player)->instances[0].x += IMG;
		game->player_x ++;
		update(game);
	}
}

void	gameplay(mlx_key_data_t key, void *game)
{
	t_game	*p_game;

	p_game = game;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_RELEASE)
	{
		memory(p_game);
		exit(0);
	}
	if ((key.key == MLX_KEY_W && key.action == MLX_RELEASE)
		|| (key.key == MLX_KEY_UP && key.action == MLX_RELEASE))
		move('U', p_game);
	if ((key.key == MLX_KEY_S && key.action == MLX_RELEASE)
		|| (key.key == MLX_KEY_DOWN && key.action == MLX_RELEASE))
		move('D', p_game);
	if ((key.key == MLX_KEY_A && key.action == MLX_RELEASE)
		|| (key.key == MLX_KEY_LEFT && key.action == MLX_RELEASE))
		move('L', p_game);
	if ((key.key == MLX_KEY_D && key.action == MLX_RELEASE)
		|| (key.key == MLX_KEY_RIGHT && key.action == MLX_RELEASE))
		move('R', p_game);
}
