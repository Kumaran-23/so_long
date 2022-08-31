#include "../inc/so_long.h"

char	*get_front(void)
{
	char	*img;

	img = "./img/catfront1.xpm";
	return (img);
}

char	*get_back(void)
{
	char	*img;

	img = "./img/catback2.xpm";
	return (img);
}

char	*get_right(void)
{
	char	*img;

	img = "./img/catright1.xpm";
	return (img);
}

char	*get_left(void)
{
	char	*img;

	img = "./img/catleft1.xpm";
	return (img);
}

void	win_message(t_game *var)
{
	ft_printf("You collected all the melons! You win!!\n");
	close_window(var);
}