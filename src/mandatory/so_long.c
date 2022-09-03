#include "../inc/so_long.h"

void	display_moves(t_game *var)
{
	char	*moves;

	moves = ft_itoa(var->player_move);
	mlx_string_put(var->mlx, var->win, 10, 20, 0xFFFFFF,
		"MOVES: ");
	mlx_string_put(var->mlx, var->win, 65, 20, 0xFFFFFF, moves);
	free(moves);
}

int	animate(t_game *var)
{
	if (var->loop < 40)
	{
		var->loop++;
		if (var->enemy == 2)
			var->enemy = 1;
		var->enemy++;
		if (var->loop < 20)
			var->enemy = 1;
		if (var->loop > 0)
		load_window(var);
		return (0);
	}
	var->loop = 0;
	return (0);
}

void	arg_check(int argc, char **argv)
{
	if (argc != 2)
	{
		error("Must have only 2 number of arguments");
		exit(0);
	}
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
	{
		error("Must be <name>.ber file");
		exit (1);
	}
}

void	game_init(t_game *var)
{
	var->map_row = 0;
	var->map_coll = 0;
	var->x = 0;
	var->y = 0;
	var->pxl = 0;
	var->player = 0;
	var->player_move = 0;
	var->player_dir = "img/catfront1.xpm";
	var->collectibles = 0;
	var->exits = 0;
	var->enemy = 1;
	var->loop = 0;
}

int main(int argc, char **argv)
{
    t_game  var;

    arg_check(argc, argv);
    game_init(&var);
	map_validate(argv, &var);
	print_matrix(&var);
	window_create(&var);
    mlx_hook(var.win, 2, 1L << 0, key_input, &var);
	mlx_hook(var.win, 17, 1L << 5, close_window, &var);
	mlx_loop_hook(var.mlx, animate, &var);
	mlx_loop(var.mlx);
	exit(0);
}