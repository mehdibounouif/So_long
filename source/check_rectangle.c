#include "../includes/so_long.h"

void    check_rectangule(t_node **list, t_map **map, int fd)
{
        char    *line;
        size_t  first_line;
        size_t  len;
        t_node  *node;

        first_line = 0;
        len = 0;
        while ((line = get_next_line(fd)) != NULL)
        {
                len = ft_strlen(line);
                if (first_line == 0)
                        first_line = len;
                if (len != first_line)
                {
                        free(line);
                        line = NULL;
                        free_and_close(list, map, fd, RECTANGUL_ERROR);
                }
                node = ft_new_node(line);
                if (!node)
                        free_and_close(list, map, fd, NODE_ERROR);
                add_back(list, node);
                (*map)->y++;
        }
        (*map)->x = first_line - 1;
		(*map)->list = *list;
}

