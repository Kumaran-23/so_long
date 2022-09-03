#include "../inc/so_long.h"

void	right(t_game *var)
{
	if (var->map[var->player_y][var->player_x + 1] == '1')
		return ;
	else if (var->map[var->player_y][var->player_x + 1] == 'M')
	{
		ft_printf("You have been killed! You lose!\n");
		close_window(var);
	}
	else if (var->map[var->player_y][var->player_x + 1] == 'C')
	{
		var->map[var->player_y][var->player_x] = '0';
		var->map[var->player_y][var->player_x + 1] = 'P';
		var->collectibles--;
	}
	else if (var->map[var->player_y][var->player_x + 1] == 'E' && var->collectibles == 0)
        win_message(var);
	else if (var->map[var->player_y][var->player_x + 1] == 'E')
		return ;
	else
	{
		var->map[var->player_y][var->player_x] = '0';
		var->map[var->player_y][var->player_x + 1] = 'P';
	}
	var->player_move++;
	var->player_dir = "img/catright1.xpm";
}

void	left(t_game *var)
{
	if (var->map[var->player_y][var->player_x - 1] == '1')
		return ;
	else if (var->map[var->player_y][var->player_x - 1] == 'M')
	{
		ft_printf("You have been killed! You lose!\n");
		close_window(var);
	}
	else if (var->map[var->player_y][var->player_x - 1] == 'C')
	{
		var->map[var->player_y][var->player_x] = '0';
		var->map[var->player_y][var->player_x - 1] = 'P';
		var->collectibles--;
	}
	else if (var->map[var->player_y][var->player_x - 1] == 'E' && var->collectibles == 0)
        win_message(var);
	else if (var->map[var->player_y][var->player_x - 1] == 'E')
		return ;
	else
	{
		var->map[var->player_y][var->player_x] = '0';
		var->map[var->player_y][var->player_x - 1] = 'P';
	}
	var->player_move++;
	var->player_dir = "img/catleft1.xpm";
}

void	up(t_game *var)
{
	if (var->map[var->player_y - 1][var->player_x] == '1')
		return ;
	else if (var->map[var->player_y - 1][var->player_x] == 'M')
	{
		ft_printf("You have been killed! You lose!\n");
		close_window(var);
	}
	else if (var->map[var->player_y - 1][var->player_x] == 'C')
	{
		var->map[var->player_y][var->player_x] = '0';
		var->map[var->player_y - 1][var->player_x] = 'P';
		var->collectibles--;
	}
	else if (var->map[var->player_y - 1][var->player_x] == 'E' && var->collectibles == 0)
        win_message(var);
	else if (var->map[var->player_y - 1][var->player_x] == 'E')
		return ;
	else
	{
		var->map[var->player_y][var->player_x] = '0';
		var->map[var->player_y - 1][var->player_x] = 'P';
	}
	var->player_move++;
	var->player_dir = "img/catback2.xpm";
}

void	down(t_game *var)
{
    if (var->map[var->player_y + 1][var->player_x] == '1')
		return ;
	else if (var->map[var->player_y + 1][var->player_x] == 'M')
	{
		ft_printf("You have been killed! You lose!\n");
		close_window(var);
	}
	else if (var->map[var->player_y + 1][var->player_x] == 'C')
	{
		var->map[var->player_y][var->player_x] = '0';
		var->map[var->player_y + 1][var->player_x] = 'P';
		var->collectibles--;
	}
	else if (var->map[var->player_y + 1][var->player_x] == 'E' && var->collectibles == 0)
        win_message(var);
	else if (var->map[var->player_y + 1][var->player_x] == 'E')
		return ;
	else
	{
		var->map[var->player_y][var->player_x] = '0'; 
		var->map[var->player_y + 1][var->player_x] = 'P';
	}
	var->player_move++;
	var->player_dir = "img/catfront1.xpm";
}

int	key_input(int keyboard, t_game *var)
{
	if (keyboard == 65307)
		close_window(var);
	if (keyboard == 115)
		down(var);
	if (keyboard == 119)
		up(var);
	if (keyboard == 100)
		right(var);
	if (keyboard == 97)
		left(var);
	load_window(var);
    ft_printf("%d\n", var->player_move);
    return (0);
}