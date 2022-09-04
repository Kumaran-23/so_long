/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <snair@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:29:38 by snair             #+#    #+#             */
/*   Updated: 2022/09/04 15:52:54 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_chars(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] != 'E' && buffer[i] != 'P' && buffer[i] != 'C'
			&& buffer[i] != '1' && buffer[i] != '0' && buffer[i] != 'M'
			&& buffer[i] != '\n')
			error("Invalid map characters");
		i++;
	}
}

static void	free_buffer(char *buffer, int bytes)
{
	if ((bytes == 0 && buffer[0] == '\0') || bytes < 0)
	{
		error("Map is empty");
		free(buffer);
		buffer = NULL;
		exit (0);
	}
}

void	map_validate(char **argv, t_game *var)
{
	char	*buffer;
	int		bytes;
	int		fd;
	int		i;

	fd = open(argv[1], O_RDONLY);
	buffer = malloc(sizeof(char) * 600);
	if (fd == -1)
		error("Map could not be found");
	bytes = read(fd, buffer, 600);
	buffer[bytes] = '\0';
	free_buffer(buffer, bytes);
	check_assets(buffer, var);
	check_chars(buffer);
	var->map = ft_split(buffer, '\n');
	i = 0;
	while (var->map[0][i] != '\0')
	{
		var->map_row++;
		i++;
	}
	check_map(buffer, var);
	free(buffer);
	close(fd);
}

void	print_matrix(t_game *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < var->map_coll)
	{
		i = 0;
		while (var->map[j][i] != '\0')
		{
			write(1, &var->map[j][i], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}
