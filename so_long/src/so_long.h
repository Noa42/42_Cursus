/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 01:35:19 by achacon-          #+#    #+#             */
/*   Updated: 2024/08/02 12:12:19 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define IMG 64
# define WIDTH 256
# define HEIGHT 256

typedef struct s_data
{
	char			*map_name;
	char			**map;
	int				check_c;
	int				check_e;
	int				map_width;
	int				map_height;
	int				count_player;
	int				count_exit;
	int				count_collect;
	int				player_x;
	int				player_y;
	int				collected;
	mlx_t			*mlx_ptr;
	mlx_texture_t	*texture;
	mlx_image_t		*i_floor;
	mlx_image_t		*i_player;
	mlx_image_t		*i_collect;
	mlx_image_t		*i_wall;
	mlx_image_t		*i_exit;
	int				move_counter;
}	t_game;

//PARSING_MAP
void	get_map(t_game *game);
void	fill_flood(t_game *game, int p_y, int p_x);
void	check_playable(t_game *game);
void	parsing_map(t_game *game);

//PARSING_UTILS
int		check_ber(char*s);
int		check_rectangle(t_game *game);
int		check_char(char **map);
int		check_walls(char **map);
void	check_elements(t_game *game);

//MAP
void	init_loading(t_game *game);
void	check_files(t_game *game);
void	load_png(t_game *game);
void	paint_map(t_game *game);

//GAMEPLAY
void	update(t_game *game);
void	move(char m, t_game *game);
void	gameplay(mlx_key_data_t key, void *game);

//UTILS
void	memory(t_game *game);
void	my_error(char *s, t_game *game);
void	print_array(char **array);
void	free_array(char **array);

#endif