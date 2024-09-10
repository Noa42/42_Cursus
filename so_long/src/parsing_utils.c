/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <	achacon-@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 01:35:07 by achacon-          #+#    #+#             */
/*   Updated: 2024/08/01 03:31:13 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char*s)
{
	int		i;
	char	*ext;

	ext = ".ber";
	i = 0;
	while (s[i] != '\0' && s[i] != '.')
		i++;
	if (ft_strlen(&s[i]) != ft_strlen(ext))
		return (1);
	return (ft_strncmp(ext, &s[i], ft_strlen(ext)));
}

int	check_rectangle(t_game *game)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(game->map[0]);
	game->map_width = len;
	if (len < 2)
		return (1);
	while (game->map[i] != NULL)
	{
		if (ft_strlen(game->map[i]) != len)
			return (1);
		i++;
	}
	game->map_height = i;
	if (i < 2)
		return (1);
	return (0);
}

int	check_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][++j] != '\0')
	{
		if (map[i][j] != '1')
			return (1);
	}
	i++;
	while (map[++i] != NULL)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (1);
	}
	j = 0;
	i--;
	while (map[i][++j] != '\0')
	{
		if (map[i][j] != '1')
			return (1);
	}
	return (0);
}

void	check_elements(t_game *game)
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
			if (game->map[i][j] == 'P')
			{
				game->count_player++;
				game->player_x = j;
				game->player_y = i;
			}
			if (game->map[i][j] == 'C')
				game->count_collect++;
			if (game->map[i][j] == 'E')
				game->count_exit++;
			j++;
		}
		i++;
	}
}
