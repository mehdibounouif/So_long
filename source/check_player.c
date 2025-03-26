#include "../includes/so_long.h"

static void	check_symbol(t_map **map, char symbol, int x, int y)
{
	if (symbol == 'E')
	{
		(*map)->exit_x = x + 1;
		(*map)->exit_y = y;
	}
	if (symbol == 'P')
	{
		(*map)->player_x = x + 1;
		(*map)->player_y = y;
	}

}

static void	find_position(t_node **list, t_map **map, int *p, char symbol)
{
	t_node	*tmp_list;
	char	*tmp_line;
	size_t	x;
	int	y;

	tmp_list = *list;
	y = 0;
	while (y++ < (*map)->y)
	{
		tmp_line = tmp_list->content;
		x = 0;
		while (x++ < (*map)->x)
		{
			if (tmp_line[x] == symbol)
			{
				(*p)++;
				check_symbol(map, symbol, x, y);
			}
		}
		tmp_list = tmp_list->next;
	}
}

void	check_player(t_node **list, t_map **map, int fd)
{
	int	p;

	p = 0;
	find_position(list, map, &p, 'P');
	if (p > 1)
		free_and_close(list, map, fd, MULTY_PLAYER_ERROR);
	if (p < 1)
		free_and_close(list, map, fd, NO_PLAYER_ERROR);
}

void	check_exit_door(t_node **list, t_map **map, int fd)
{
	int	e;

	e = 0;
	find_position(list, map, &e, 'E');
	if (e > 1)
		free_and_close(list, map, fd, MULTY_EXIT_ERROR);
	if (e < 1)
		free_and_close(list, map, fd, NO_EXIT_ERROR);
}
