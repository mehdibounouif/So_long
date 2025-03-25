#include "../includes/so_long.h"

void	check_walls(t_map **map, t_node **list, int fd)
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
		while (j < (*map)->len)
		{
			if (((i == 0 || i == (*map)->c_line - 1) && tmp[j] != '1')
					|| ((i > 0 && i < (*map)->c_line - 1) 
					&& (j == 0 || j == (*map)->len - 1) 
					&& tmp[j] != '1'))
			{
				free_and_close(list, map, fd, WALL_ERROR);
			}
			j++;
		}
		printf("%s\n", tmp);
		i++;
		tmp_list = tmp_list->next;
	}
}
