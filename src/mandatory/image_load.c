#include "../inc/so_long.h"

void    load_walls(t_game *var)
{
	var->file = mlx_xpm_file_to_image(var->mlx,
			"./img/wall.xpm", &var->pxl, &var->pxl);
	mlx_put_image_to_window (var->mlx, var->win,
		var->file, var->pxl * var->x,
		var->pxl * var->y);
	mlx_destroy_image(var->mlx, var->file);
}

void	load_player(t_game *var)
{
	var->file = mlx_xpm_file_to_image(var->mlx,
			var->player_dir, &var->pxl, &var->pxl);
	var->player_x = var->x;
	var->player_y = var->y;
	mlx_put_image_to_window (var->mlx, var->win,
		var->file, var->pxl * var->x,
		var->pxl * var->y);
	mlx_destroy_image(var->mlx, var->file);
}

void	load_collectible(t_game *var)
{
	var->file = mlx_xpm_file_to_image(var->mlx,
			"./img/melon.xpm", &var->pxl, &var->pxl);
	mlx_put_image_to_window (var->mlx, var->win,
		var->file, var->pxl * var->x,
		var->pxl * var->y);
	mlx_destroy_image(var->mlx, var->file);
}

void	load_exit(t_game *var)
{
	if (var->collectibles == 0)
	{	
		var->file = mlx_xpm_file_to_image(var->mlx,
				"./img/opening.xpm", &var->pxl, &var->pxl);
		mlx_put_image_to_window (var->mlx, var->win,
		var->file, var->pxl * var->x,
		var->pxl * var->y);
		mlx_destroy_image(var->mlx, var->file);
	}
	else
	{
		var->file = mlx_xpm_file_to_image(var->mlx,
			"./img/door.xpm", &var->pxl, &var->pxl);
		mlx_put_image_to_window (var->mlx, var->win,
		var->file, var->pxl * var->x,
		var->pxl * var->y);
		mlx_destroy_image(var->mlx, var->file);
	}
}

void	load_floor(t_game *var)
{
	var->y = 0;
	while ((var->y) < (var->map_coll))
	{
		var->x = 0;
		while ((var->x) < (var->map_row))
		{
			var->file = mlx_xpm_file_to_image(var->mlx,
					"./img/floor.xpm", &var->pxl, &var->pxl);
			mlx_put_image_to_window (var->mlx, var->win,
				var->file, var->pxl * var->x,
				var->pxl * var->y);
			mlx_destroy_image(var->mlx, var->file);
			var->x++;
		}
		var->y++;
	}
}