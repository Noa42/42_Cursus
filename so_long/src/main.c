/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 01:33:23 by achacon-          #+#    #+#             */
/*   Updated: 2024/08/02 12:27:57 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initial_values(t_game *game)
{
	game->map_name = NULL;
	game->map = NULL;
	game->check_c = 0;
	game->check_e = 0;
	game->map_width = 0;
	game->map_height = 0;
	game->count_player = 0;
	game->count_exit = 0;
	game->count_collect = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->collected = 0;
	game->mlx_ptr = NULL;
	game->texture = NULL;
	game->i_floor = NULL;
	game->i_player = NULL;
	game->i_collect = NULL;
	game->i_wall = NULL;
	game->i_exit = NULL;
	game->move_counter = 0;
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		my_error("Malloc error", game);
	initial_values(game);
	if (argc != 2)
		my_error("Wrong argument number", game);
	game->map_name = argv[1];
	if (access(game->map_name, F_OK | R_OK) == -1)
		my_error("Wrong map filename ", game);
	if (check_ber(argv[1]) != 0)
		my_error("This map is no .ber", game);
	get_map(game);
	parsing_map(game);
	init_loading(game);
	paint_map(game);
	mlx_image_to_window(game->mlx_ptr, game->i_player,
		game->player_x * IMG, game->player_y * IMG);
	ft_printf("Kirby is hungry. Help Kirby to eat all the oniguiri ");
	ft_printf("and then come back to Dreamland through th mirror\n");
	mlx_key_hook(game->mlx_ptr, gameplay, game);
	mlx_loop(game->mlx_ptr);
	memory(game);
	exit(0);
}
