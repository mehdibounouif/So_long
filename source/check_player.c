#include "../includes/so_long.h"

void	player_position(t_node **list, t_map **map, int fd)
{
	size_t	x;
	int	y;
	int	p;
	char	*tmp;

	y = 0;
	p = 0;
	while (y++ < (*map)->y)
	{
		tmp = (*list)->content;
		x = 0;
		while (x < (*map)->x)
		{
			if (tmp[x] == 'P')
			{
				p++;
				(*map)->x = x;
				(*map)->y = y;
			}
			x++;
		}
		*list = (*list)->next;
	}
	if (p > 1)
		free_and_close(list, map, fd, MULTY_PLAYER_ERROR);
	if (p < 1)
		free_and_close(list, map, fd, NO_PLAYER_ERROR);
}
