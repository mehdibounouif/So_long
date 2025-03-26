#include "../includes/so_long.h"

void	check_map(int fd, t_map **map, t_node **list)
{
	if (!(*map = malloc(sizeof(t_map))))
		return ;
	ft_init(map);
	check_rectangule(list, map, fd);
	check_walls(list, map, fd);
	check_player(list, map, fd);
	check_exit_door(list, map, fd);
	free_and_close(list, map, fd, "Salina\n");
	//print_list(*list);
	//free(*map);
	//close(fd);
	//check_rectangule();
	//check_walls();
}
