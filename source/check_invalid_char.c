#include "../includes/so_long.h"

void	check_invalid_char(t_node **list, t_map **map, int fd)
{
	size_t	x;
	int	y;
	char	*tmp;
	t_node	*tmp_list;

	y = 0;
	tmp_list = *list;
	while (tmp_list && y < (*map)->y)
	{
		x = 0;
		tmp = tmp_list->content;
		while (x < (*map)->x)
		{
			if (tmp[x] != '1' && tmp[x] != '0' && tmp[x] != 'E'
					&& tmp[x] != 'C' && tmp[x] != 'P')
				free_and_close(list, map, fd, INVALID_CHAR_ERROR);
			x++;
		}
		tmp_list = tmp_list->next;
		y++;
	}
}
