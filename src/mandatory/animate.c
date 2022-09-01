#include "../inc/so_long.h"

void	destroy_img(t_game *var)
{
	mlx_destroy_image(var->mlx, var->file);
	mlx_destroy_image(var->mlx, var->collect);
	mlx_destroy_image(var->mlx, var->floor);
	mlx_destroy_image(var->mlx, var->exit);
	mlx_destroy_image(var->mlx, var->wall);
}

void	win_message(t_game *var)
{
	ft_printf("You collected all the melons! You win!!\n");
	close_window(var);
}