/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 11:32:26 by snair             #+#    #+#             */
/*   Updated: 2021/07/13 19:09:27 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*n_str;

	if (!str)
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	if (!str || !buff)
		return (NULL);
	n_str = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buff)) + 1));
	if (n_str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (str)
		while (str[++i])
			n_str[i] = str[i];
	while (buff[j])
		n_str[i++] = buff[j++];
	n_str[ft_strlen(str) + ft_strlen(buff)] = '\0';
	free(str);
	return (n_str);

}
