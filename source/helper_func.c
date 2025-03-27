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
        int     j;
	char 	*tmp;

	lst = (char *)malloc(sizeof(char *) * ((*map)->y + 1));
        
        i = 0;
        tmp_list = *list;
        while (i < (*map)->y)
        {
                tmp = tmp_list->content;
                j = 0;
                while (j < (*map)->y)
                {
                        lst[i][j] = tmp[j];
                        j++;
                }
                tmp_list = tmp_list->next;
                i++;
        }
        return(lst);
}

void    ft_init(t_map **map)
{
	(*map)->player_x = 0;
	(*map)->player_y = 0;
	(*map)->exit_x = 0;
	(*map)->exit_y = 0;
        (*map)->y = 0;
        (*map)->x = 0;
        (*map)->collectible = 0;
        (*map)->is_rectang = false;
        (*map)->is_correct = false;
}
