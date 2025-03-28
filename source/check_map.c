#include "../includes/so_long.h"

void	check_map(int fd, t_map **map, t_node **list)
{
	//char	**tmp;
	//int	i;
	//i = 0;
	if (!(*map = malloc(sizeof(t_map))))
		return ;
	ft_init(map);
	check_rectangule(list, map, fd);
	/*
	tmp = map_copy(list, map);	
	printf("\n=+++++++++++++++++++++=\n");
	while (tmp[i])
	{
		printf("%s\n", tmp[i++]);
	}
	printf("\n=+++++++++++++++++++++=\n");
	*/
	check_invalid_char(list, map, fd);
	check_walls(list, map, fd);
	check_player(list, map, fd);
	check_exit_door(list, map, fd);
	check_collectible(list, map, fd);
	if_can_access(list, map, fd);
//	clean_exiting(list, map, fd);
}
