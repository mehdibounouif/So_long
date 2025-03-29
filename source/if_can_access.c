#include "../includes/so_long.h"

void	flood_fill(char **list, t_map *map, size_t x, int y, int *c)
{
	if (list[y][x] == '1' || list[y][x] == 'V')
		return ;
	if (x == 0 || y == 0 || x >= map->x || y >= map->y)
		return ;
	if (list[y][x] == 'C')
		(*c)--;	
	if (list[y][x] == 'E')
		map->access_exit = 1;
	list[y][x] = 'V';
	flood_fill(list, map, x - 1, y, c);
	flood_fill(list, map, x + 1, y, c);
	flood_fill(list, map, x, y - 1, c);
	flood_fill(list, map, x, y + 1, c);
}

void	if_can_access(t_node **list, t_map **map, int fd)
{
	char	**lst;	
	int	c;
	
	lst = map_copy(list, map);
	c = (*map)->collectible;
	flood_fill(lst, *map, (*map)->player_x-1, (*map)->player_y-1, &c);
	if (c == 0 && (*map)->access_exit == 1)
	{
		ft_free_str(lst);
	}
	else
	{
		ft_free_str(lst);
		free_and_close(list, map, fd, INVALID_MAP_ERROR);
	}
}
