#include "../includes/so_long.h"

void	check_walls(t_node **list, t_map **map, int fd)
{
	char	*tmp;
	int	i;
	size_t	j;
	t_node	*tmp_list;

	i = 0;
	tmp_list = *list;
	while (tmp_list)
	{
		tmp = tmp_list->content;
		j = 0;
		while (j < (*map)->x)
		{
			if (((i == 0 || i == (*map)->y - 1) && tmp[j] != '1')
					|| ((i > 0 && i < (*map)->y - 1) 
					&& (j == 0 || j == (*map)->x - 1) 
					&& tmp[j] != '1'))
			{
				free_and_close(list, map, fd, WALL_ERROR);
			}
			j++;
		}
//		printf("%s\n", tmp);
		i++;
		tmp_list = tmp_list->next;
	}
}
