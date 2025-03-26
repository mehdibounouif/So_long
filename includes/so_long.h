#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libft/libft.h"

# define RECTANGUL_ERROR "Map is not rectanguler!\n"
# define NODE_ERROR "Node is creation failed!\n"
# define WALL_ERROR "The wall has a hole!\n"
# define MULTY_PLAYER_ERROR "There's many player\n"
# define NO_PLAYER_ERROR "There's no player!\n"
# define MULTY_EXIT_ERROR "There's multy exit doors\n"
# define NO_EXIT_ERROR "There's no exit door!\n"


typedef struct s_node
{
        char    *content;
        struct s_node   *next;
}       t_node;

typedef struct s_map
{
        int     y;
        size_t  x;
	int	player_x;
	int	player_y;
	int	exit_x;
	int	exit_y;
        int     collectible;
        bool    is_rectang;
        bool    is_correct;
}	t_map;

t_node  *ft_new_node(char *content);
void    add_back(t_node **list, t_node *new);
void    ft_free_list(t_node **list);
void    free_and_close(t_node **list, t_map **map, int fd, char *msg);
void	check_rectangule(t_node **list, t_map **map, int fd);
void    ft_init(t_map **map);
int     ft_strcmp(char *s1, char *s2);
void	check_name(char *name);
void    ft_free_str(char **list);
void    print_list(t_node *list);
void    check_map(int fd, t_map **map, t_node **list);
void	check_walls(t_node **list, t_map **map, int fd);
void    check_player(t_node **list, t_map **map, int fd);
void    check_exit_door(t_node **list, t_map **map, int fd);

#endif
