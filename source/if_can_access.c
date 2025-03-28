#include "../includes/so_long.h"

void	flood_fill(char **list, t_map *map, size_t x, int y, int *c)
{
	if (list[y][x] == '1' || list[y][x] == 'E'
			|| list[y][x] == 'V')
		return ;
	if (x == 0 || y == 0 || x >= map->x || y >= map->y)
		return ;
	if (*c == 0 && list[y][x] == 'E')
		map->access_exit = 1;
	if (list[y][x] == 'C')
		(*c)--;	
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
	int	i;
	i = 0;

	c = (*map)->collectible;
	printf("collectible before %d\n", c);
	printf("%d\n", (*map)->access_exit);
	lst = map_copy(list, map);
	flood_fill(lst, *map, (*map)->player_x, (*map)->player_y, &c);
	printf("%d\n", (*map)->access_exit);
	if (c == 0 && (*map)->access_exit == 1)
	{
	        printf("\n=+++++++++++++++++++++=\n");
        	while (lst[i])
	        {
        	        printf("%s\n", lst[i++]);
	        }
        	printf("\n=+++++++++++++++++++++=\n");
		printf("You can access all collectibles and exit dor!\n");
	}
	printf("collectible after %d\n", c);
	close(fd);
}
