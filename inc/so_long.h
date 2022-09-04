/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <snair@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:30:08 by snair             #+#    #+#             */
/*   Updated: 2022/09/05 07:20:51 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <mlx_int.h>
# include <stdio.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_row;
	int		map_coll;
	int		map_area;
	int		x;
	int		y;
	int		pxl;
	int		player_x;
	int		player_y;
	int		player_move;
	int		loop;
	char	*player_dir;
	char	*exit;
	char	*floor;
	char	*collect;
	char	*wall;
	char	*file;
	char	*bar;
	char	*enemies;
	int		collectibles;
	int		player;
	int		exits;
	int		enemy;
	int		melon;
}	t_game;

/*map_check*/
void	error(char *message);
void	check_wall_x(t_game *var);
void	check_wall_y(t_game *var);
void	check_map(char *buffer, t_game *var);
void	check_assets(char *buffer, t_game *var);

/*image_load*/
void	load_walls(t_game *var);
void	load_player(t_game *var);
void	load_collectible(t_game *var);
void	load_exit(t_game *var);
void	load_floor(t_game *var);

/*window_load*/
void	load_enemy(t_game *var);
int		close_window(t_game *var);
int		load_window(t_game *var);
void	window_create(t_game *var);
void	win_message(t_game *var);

/*keyhook*/
void	up(t_game *var);
void	down(t_game *var);
void	right(t_game *var);
void	left(t_game *var);
int		key_input(int keyboard, t_game *var);

/*map_load*/
void	check_chars(char *buffer);
void	map_validate(char **argv, t_game *game);
void	print_matrix(t_game *var);

/*so_long*/
void	arg_check(int argc, char **argv);
void	display_moves(t_game *var);
int		animate(t_game *var);
void	game_init(t_game *var);
void	load_bar(t_game *var);

#endif