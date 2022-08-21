/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:41:50 by snair             #+#    #+#             */
/*   Updated: 2022/02/16 15:52:59 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_findline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i += 1;
			break ;
		}
		i++;
	}
	return (i);
}

char	*ft_getline(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = ft_findline(str);
	j = 0;
	line = 0;
	if (!str)
		return (NULL);
	if (i > 0)
	{
		line = (char *)malloc(sizeof(char) * (i + 1));
		while (j < i)
		{
			line[j] = str[j];
			j++;
		}
		line[j] = '\0';
	}
	return (line);
}
