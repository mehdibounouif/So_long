#include "../includes/so_long.h"

void	print(char **p)
{
	int	i = 0;
	int	j;
	while (p[i])
	{
		j = 0;
		while (p[i][j])
		{
			printf("%c", p[i][j]);
			j++;
		}
		i++;
	}
	printf("\n");
}

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
	printf("%d\n", (*map)->access_exit);
	flood_fill(lst, *map, (*map)->player_x-1, (*map)->player_y-1, &c);
	print(lst);
	printf("%d\n", (*map)->access_exit);
	if (c == 0 && (*map)->access_exit == 1)
	{
		print(lst);
		printf("You can access all collectibles and exit dor!\n");
	}
	close(fd);
}
