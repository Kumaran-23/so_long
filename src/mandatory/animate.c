#include "../inc/so_long.h"

char	*get_front(void)
{
	char		*pic;
	int			i;
	char		*img[3];

	i = 0;
	img[0] = "./img/catfront1.xpm";
	img[1] = "./img/catfront2.xpm";
	img[2] = "./img/catfront3.xpm";
	pic = img[i++];
	if (i == 2)
		i = 0;
	return (pic);
}

char	*get_back(void)
{
	char		*pic;
	int			i;
	char		*img[3];

	i = 0;
	img[0] = "./img/catback1.xpm";
	img[1] = "./img/catback2.xpm";
	img[2] = "./img/catback3.xpm";
	pic = img[i++];
	if (i == 2)
		i = 0;
	return (pic);
}

char	*get_right(void)
{
	char		*pic;
	int			i;
	char		*img[3];

	i = 0;
	img[0] = "./img/catright1.xpm";
	img[1] = "./img/catright2.xpm";
	img[2] = "./img/catright3.xpm";
	pic = img[i++];
	if (i == 2)
		i = 0;
	return (pic);
}

char	*get_left(void)
{
	char		*pic;
	int			i;
	char		*img[3];

	i = 0;
	img[0] = "./img/catleft1.xpm";
	img[1] = "./img/catleft2.xpm";
	img[2] = "./img/catleft3.xpm";
	pic = img[i++];
	if (i == 2)
		i = 0;
	return (pic);
}

void	win_message(t_game *var)
{
	ft_printf("You collected all the melons! You win!!\n");
	close_window(var);
}