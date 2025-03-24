#include "../includes/so_long.h"

void	check_map(int fd, t_map **map, t_node **list)
{
	if (!(*map = malloc(sizeof(t_map))))
		return ;
	check_rectangule(fd, map, list);
	//print_list(*list);
	ft_free_list(list);
	free(*map);
	close(fd);
	//check_name(v);
	//check_rectangule();
	//check_walls();
}
