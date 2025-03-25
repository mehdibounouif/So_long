#include "../includes/so_long.h"

void	check_map(int fd, t_map **map, t_node **list)
{
	if (!(*map = malloc(sizeof(t_map))))
		return ;
	ft_init(map);
	check_rectangule(fd, map, list);
	check_walls(map, list, fd);
	player_position(list, map, fd);
	free_and_close(list, map, fd, "Salina");
	//print_list(*list);
	//free(*map);
	//close(fd);
	//check_rectangule();
	//check_walls();
}
