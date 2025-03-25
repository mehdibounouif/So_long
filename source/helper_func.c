#include "../includes/so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void    ft_init(t_map **map)
{
        (*map)->y = 0;
        (*map)->x = 0;
        (*map)->collectible = 0;
        (*map)->is_rectang = false;
        (*map)->is_correct = false;
}
