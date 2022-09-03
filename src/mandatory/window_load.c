#include "../inc/so_long.h"

void    load_enemy(t_game *var)
{
    if (var->enemy == 1)
    {
        var->enemies = mlx_xpm_file_to_image(var->mlx,
			"img/enemy1.xpm", &var->pxl, &var->pxl);
            mlx_put_image_to_window (var->mlx, var->win,
            var->enemies, var->pxl * var->x, var->pxl * var->y);
        mlx_destroy_image(var->mlx, var->enemies);
    }
    else if (var->enemy == 2)
    {
         var->enemies = mlx_xpm_file_to_image(var->mlx,
			"img/enemy2.xpm", &var->pxl, &var->pxl);
            mlx_put_image_to_window (var->mlx, var->win,
            var->enemies, var->pxl * var->x, var->pxl * var->y);
        mlx_destroy_image(var->mlx, var->enemies);
    }
}

void	win_message(t_game *var)
{
	ft_printf("You collected all the melons! You win!!\n");
	close_window(var);
}

int	close_window(t_game *var)
{
    mlx_destroy_window(var->mlx, var->win);
	exit (0);
	return (1);
}

int    load_window(t_game *var)
{
    var->y = 0;
    while (var->y < var->map_coll)
    {
        var->x = 0;
        while (var->x < var->map_row)
        {
            display_moves(var);
            if (var->map[var->y][var->x] == 'P')
                load_player(var);
            else if (var->map[var->y][var->x] == 'E')
                load_exit(var);
            else if (var->map[var->y][var->x] == 'C')
                load_collectible(var);
            else if (var->map[var->y][var->x] == '1')
                load_walls(var);
            else if (var->map[var->y][var->x] == '0')
                load_floor(var);
            else if (var->map[var->y][var->x] == 'M')
                load_enemy(var);
            var->x++;
        }
         var->y++;
    }
    //ft_printf("%d\n", var->loop);
    return (0);
}

void	window_create(t_game *var)
{
    int	win_w;
	int	win_h;

	var->pxl = 50;
    win_h = var->map_coll;
	win_w = var->map_row;
    if (win_w > 31 || win_h > 16)
            error("The map is too big.");
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx,
			var->pxl * var->map_row,
			var->pxl * var->map_coll, "SO_LONG");
    load_window(var);
}