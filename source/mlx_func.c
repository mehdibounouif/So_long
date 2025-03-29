#include "../includes/so_long.h"
#include <stdio.h>

void	place_images(t_map **map)
{
	(*map)->player_img = mlx_xpm_file_to_image((*map)->mlx,
			"./textures/player.xpm",
			&(*map)->img_width, &(*map)->img_height);
	(*map)->exit_img = mlx_xpm_file_to_image((*map)->mlx,
			"./textures/exit.xpm",
			&(*map)->img_width, &(*map)->img_height);
	(*map)->collectible_img = mlx_xpm_file_to_image((*map)->mlx,
			"./textures/collectible.xpm",
			&(*map)->img_width, &(*map)->img_height);
	(*map)->wall_img = mlx_xpm_file_to_image((*map)->mlx,
			"./textures/wall.xpm",
			&(*map)->img_width, &(*map)->img_height);
	(*map)->back_img = mlx_xpm_file_to_image((*map)->mlx,
			"./textures/black.xpm",
			&(*map)->img_width, &(*map)->img_height);
	if (!(*map)->player_img || !(*map)->exit_img || !(*map)->collectible_img || !(*map)->wall_img || !(*map)->back_img)
		printf("image not found!\n");
}

void	put_and_load_map(char **lst, t_map **map)
{

	int	(x), (y);
	place_images(map);
	y = 0;
	while (lst[y])
	{
		x = 0;
		while (lst[y][x])
		{
			if (lst[y][x] == '0')
			{
				write(2,"ERROR", 5);
				mlx_put_image_to_window((*map)->mlx, (*map)->win,
					       	(*map)->wall_img, x * 32, y * 32);
			}
		    else if (lst[y][x] == '1')
				mlx_put_image_to_window((*map)->mlx, (*map)->win,
						(*map)->wall_img, x * 32, y * 32);
			else if (lst[y][x] == 'E')
			{
				printf("and dkhalt\n");
				mlx_put_image_to_window((*map)->mlx, (*map)->win,
						(*map)->exit_img, x * 32, y * 32);
			}
			else if (lst[y][x] == 'C')
				mlx_put_image_to_window((*map)->mlx, (*map)->win,
						(*map)->collectible_img, x * 32, y * 32);
			else if (lst[y][x] == 'P')
				mlx_put_image_to_window((*map)->mlx, (*map)->win,
						(*map)->player_img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	 minilibx(t_node **list, t_map **map, int fd)
{
	char	**lst;

	lst = map_copy(list, map);
	(*map)->mlx = mlx_init();
	if (!(*map)->mlx)
		printf("mlx failed\n");
	(*map)->win = mlx_new_window((*map)->mlx, (*map)->x * 32, (*map)->y * 32, "SO_LONG");
	if (!(*map)->win)
		printf("mlx window failed\n");
	put_and_load_map(lst, map);
	//printf("%s\n", (*list)->content);
	close(fd);
//	mlx_loop((*map)->mlx);
}
