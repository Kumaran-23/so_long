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

char	*join_line(char *line, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i])
		i++;
	str = malloc(i + 2);
	i = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(line);
	return (str);
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*get_map(int fd)
{
	char	buffer;
	char	*line;
	int		rd_bytes;

	rd_bytes = 1;
	if (fd < 0)
		line = NULL;
	line = malloc(1);
	line[0] = '\0';
	while (!check_line(line) && rd_bytes > 0)
	{
		rd_bytes = read(fd, &buffer, 1);
		if ((rd_bytes == 0 && line[0] == '\0') || rd_bytes < 0)
		{
			free(line);
			return (NULL);
		}
		if (rd_bytes == 0 && line[0] != '\0')
			return (line);
		line = join_line(line, buffer);
	}
	return (line);
}


void	map_validate(char **argv, t_game *var)
{
	int		i;
	int		fd;
	char	*buffer;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("Map could not be opened");
	buffer = get_map(fd);
	check_assets(buffer, var);
	check_chars(buffer);
	var->map = ft_split(buffer, '\n');
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
