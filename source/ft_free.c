#include "../includes/so_long.h"

void    ft_free_str(char **list)
{
        char    *tmp;

        if (*list)
        {
                while (*list)
                {
                        tmp = *list;
                        list++;
                        free(tmp);
                }
        }
}

void    ft_free_list(t_node **list)
{
        t_node  *tmp;
        if (*list)
        {
                while (*list)
                {
                        tmp = *list;
                        *list = (*list)->next;
                        free(tmp->content);
                        free(tmp);
                }
        }
}

void    free_and_close(t_node **list, t_map **map, int fd, char *msg)
{
        ft_free_list(list);
        free(*map);
        close(fd);
        write(2, "Error\n", 6);
        write(2, msg, ft_strlen(msg));
        exit(2);
}
