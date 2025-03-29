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
        
char    **map_copy(t_node **list, t_map **map)
{       
        t_node  *tmp_list;
		char    **lst;
		int     i;
		char	*tmp;

		lst = malloc(sizeof(char *) * ((*map)->y + 1)); 
        i = 0;
        tmp_list = *list;
        while (tmp_list)
        {
				tmp = ft_strdup(tmp_list->content);
                lst[i] = tmp;
                tmp_list = tmp_list->next;
				i++;
        }
		lst[i] = NULL;
        return(lst);
}

void    ft_init(t_map **map)
{
	(*map)->mlx = NULL;
	(*map)->win = NULL;
	(*map)->back_img = NULL;
	(*map)->wall_img = NULL;
	(*map)->exit_img = NULL;
	(*map)->player_img = NULL;
	(*map)->collectible_img = NULL;
	(*map)->player_x = 0;
	(*map)->player_y = 0;
	(*map)->exit_x = 0;
	(*map)->exit_y = 0;
	(*map)->x_pixel = 0;
	(*map)->y_pixel = 0;
	(*map)->y = 0;
	(*map)->x = 0; (*map)->collectible = 0;
    (*map)->access_exit = 0;
}










