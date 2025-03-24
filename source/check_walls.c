#include "../includes/so_long.h"

void	check_walls(t_map **map, t_node **list, int fd)
{
	char	*tmp;
	int	i;
	size_t	j;

	i = 0;
	while (*list)
	{
		tmp = (*list)->content;
		while (i < (*map)->c_line)
		{
			j = 0;
			while (j < (*map)->len)
			{
				if (((i == 0 || i == (*map)->c_line - 1) && tmp[j] != '1')
						|| (i > 0 && i < (*map)->c_line)
						&& (j == 0 || j == (*map)->c_line))
					free_and_close(list, map, fd, WALL_ERROR);
				j++;	
			}
			i++;
		}
		*list = (*list)->next;
	}
}
