#include "../includes/so_long.h"

void	check_collectible(t_node **list, t_map  **map, int fd)
{
	size_t	x;
	int	y;
	char	*tmp;
	t_node	*tmp_list;

	y = 0;
	tmp_list = *list;
	while (y < (*map)->y)
	{
		x = 0;
		tmp = tmp_list->content;
		while (x < (*map)->x)
		{
			if (tmp[x] == 'C')
				(*map)->collectible++;	
			x++;
		}
		tmp_list = tmp_list->next;
		y++;
	}
	if ((*map)->collectible == 0)
		free_and_close(list, map, fd, NO_COLLECTIBLE_ERROR);
}
