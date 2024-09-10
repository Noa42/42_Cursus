/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 01:34:40 by achacon-          #+#    #+#             */
/*   Updated: 2024/08/02 11:55:24 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map(t_game *game)
{
	int		fd;
	int		len;
	char	*buffer;
	int		buffer_size;

	buffer_size = INT_MAX;
	buffer = (char *)malloc(sizeof(char) * (buffer_size));
	fd = open(game->map_name, O_RDONLY);
	len = read(fd, buffer, buffer_size);
	close(fd);
	free(buffer);
	if (len == 0)
		my_error("Empty map", game);
	fd = open(game->map_name, O_RDONLY);
	buffer = (char *)malloc(sizeof(char) * (len + 1));
	buffer[len] = '\0';
	read(fd, buffer, len);
	close(fd);
	game->map = ft_split(buffer, '\n');
	free(buffer);
}

void	fill_flood(t_game *game, int p_y, int p_x)
{
	if (game->map[p_y][p_x] != '1' && game->map[p_y][p_x] != 'R')
	{
		if (game->map[p_y][p_x] == 'E')
			game->check_e++;
		if (game->map[p_y][p_x] == 'C')
			game->check_c++;
		game->map[p_y][p_x] = 'R';
		if (p_x + 1 < game -> map_height)
			fill_flood(game, p_y + 1, p_x);
		if (p_x - 1 >= 0)
			fill_flood(game, p_y - 1, p_x);
		if (p_y + 1 < game -> map_width)
			fill_flood(game, p_y, p_x + 1);
		if (p_y - 1 >= 0)
			fill_flood(game, p_y, p_x - 1);
	}
}

void	check_playable(t_game *game)
{
	int		p_x;
	int		p_y;

	game->check_c = 0;
	game->check_e = 0;
	p_x = game->player_x;
	p_y = game->player_y;
	fill_flood(game, p_y, p_x);
	free_array(game->map);
	get_map(game);
	if (game->check_c != game->count_collect)
		my_error("Map not playable. Player can't reach all collectables", game);
	if (game->check_e != 1)
		my_error("Map not playable. Player can't reach the exit", game);
}

void	parsing_map(t_game *game)
{
	if (check_rectangle(game) != 0)
		my_error("The map is not a valid rectangle", game);
	if (check_char(game->map) != 0)
		my_error("The map has invalid characters", game);
	if (check_walls(game->map) != 0)
		my_error("The map is not surrounded by walls", game);
	check_elements(game);
	if (game->count_player != 1)
		my_error("The number of players in the map is not correct", game);
	if (game->count_collect < 1)
		my_error("The map has not enough collectables", game);
	if (game->count_exit != 1)
		my_error("The number of exits in the map is not correct", game);
	check_playable(game);
}
