#include "../includes/so_long.h"

char	*my_line;

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_free_str(char **list)
{
	char	*tmp;

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

void	ft_free_list(t_node **list)
{
	t_node	*tmp;
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
	*list = NULL;
        free(*map);
	*map = NULL;
        close(fd);
        write(2, "Error\n", 6);
        write(2, msg, ft_strlen(msg));
        exit(2);
}

void    ft_init(t_map **map)
{
        (*map)->c_line = 0;
        (*map)->len = 0;
        (*map)->collectible = 0;
        (*map)->is_rectang = false;
        (*map)->is_correct = false;
}

void	check_rectangule(int fd, t_map **map, t_node **list)
{
        char    *line;
        size_t	first_line;
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
                        free_and_close(list, map, fd, RECTANGUL_ERROR);
		}
                node = ft_new_node(line);
                if (!node)
                        free_and_close(list, map, fd, NODE_ERROR);
                add_back(list, node);
                (*map)->c_line++;
        }
        (*map)->len = first_line - 1;
}
