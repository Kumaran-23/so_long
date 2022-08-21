#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	char	*file;
	int		map_row;
	int		map_coll;
	int		map_area;
	int		x;
	int		y;
	int		pxl;
	int		player_x;
	int		player_y;
	int		player_move;
	int		play_pos;
	int		loop;
	char	*pl_dir;
	int		collectibles;
	int		player;
	int		exits;
	int		enemy;
	int		enemy_x;
	int		enemy_y;
}	t_game;

/*map_check*/
void    error(char *message);
void	check_wall_x(t_game *var);
void	check_wall_y(t_game *var);
void	check_map(char *buffer, t_game *var);
void	check_assets(char *buffer, t_game *var);

/*image_load*/
void    load_walls(t_game *var);
void	load_player(t_game *var);
void	load_collectible(t_game *var);
void	load_exit(t_game *var);
void	load_floor(t_game *var);
void    load_enemy(t_game *var);

/*window_load*/
void	check_chars(char *buffer);
int		close_window(t_game *var);
int		c_collected(t_game *var);
void    load_window(t_game *var);
void	window_create(t_game *var);

/*keyhook*/
void    up(t_game *var);
void    down(t_game *var);
void    right(t_game *var);
void    left(t_game *var);
int		key_input(int keyboard, t_game *var);

/*map_load*/
char	*join_line(char *line, char c);
int		check_line(char *line);
char	*get_map(int fd);
void	map_validate(char **argv, t_game *game);
void	print_matrix(t_game *v);

/*animate*/
char	*get_back(void);
char	*get_front(void);
char	*get_right(void);
char	*get_left(void);

/*so_long*/
void	arg_check(int argc, char **argv);
void	game_init(t_game *var);

#endif