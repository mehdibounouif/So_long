#include "../includes/so_long.h"
/*
void	print_list(t_node *list)
{
	while (list)
	{
		printf("%s\n", list->content);
		list = list->next;
	}
}
*/

int	main(int c, char **v)
{
	t_node	*list;
	t_map	*map;
	int	fd;

	list = NULL;
	if (c != 2)
	{
		write(2, "Error\ninvalid argument!\n", 24);
		return (1);
	}
		
	check_name(v[1]);
	if ((fd = open(v[1], O_RDONLY)) < 0)
	{
		write(2, "Error\nOpen file failed!\n", 24);
              	return (1);
	}
	//ft_init(&map);
	check_map(fd, &map, &list);
	return (0);
}
