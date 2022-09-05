/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <snair@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:29:58 by snair             #+#    #+#             */
/*   Updated: 2022/09/05 09:01:50 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error(char *message)
{
	ft_printf("Error\n%s\n", message);
	exit(1);
}

void	check_wall_x(t_game *var)
{
	while ((var->x) < (var->map_row))
	{
		if (var->map[0][var->x] != '1')
			error("Top row is not closed!.");
		var->x++;
	}
	var->y = var->map_coll - 1;
	var->x = 0;
	while ((var->x) < (var->map_row))
	{
		if (var->map[var->y][var->x] != '1')
			error("Bottom row is not closed!.");
		var->x++;
	}
}

void	check_wall_y(t_game *var)
{
	var->x = 0;
	var->y = 0;
	while ((var->y) < (var->map_coll))
	{
		if (var->map[var->y][0] != '1')
			error("First vertical wall not closed!.");
		var->y++;
	}
	var->y = 0;
	var->x = var->map_row - 1;
	while ((var->y) < (var->map_coll))
	{
		if (var->map[var->y][var->x] != '1')
			error("Last vertical wall not closed!.");
		var->y++;
	}
}

void	check_map(char *buffer, t_game *var)
{
	var->map_area = ft_strlen(buffer) - var->map_coll;
	if (var->map_area != var->map_row * var->map_coll)
		error("Map has wrong shape!.");
	check_wall_x(var);
	check_wall_y(var);
}

void	check_assets(char *buffer, t_game *var)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'P')
			var->player++;
		if (buffer[i] == 'C')
			var->collectibles++;
		if (buffer[i] == 'E')
			var->exits++;
		if (buffer[i] == '\n')
			var->map_coll++;
		i++;
	}
	ft_printf("%d player\n", var-> player);
	ft_printf("%d collect\n", var-> collectibles);
	ft_printf("%d exit\n", var-> exits);
	if (var->player != 1 || var->collectibles < 1 || var->exits != 1)
		error("Incorrect number of Players, Collectibles or Exits or Enemys.");
}
