#include "../includes/so_long.h"

void	free_images(t_map **map)
{
	if ((*map)->back_img)
		mlx_destroy_image((*map)->mlx, (*map)->back_img);
	if ((*map)->collectible_img)
		mlx_destroy_image((*map)->mlx, (*map)->collectible_img);
	if ((*map)->player_img)
		mlx_destroy_image((*map)->mlx, (*map)->player_img);
	if ((*map)->wall_img)
		mlx_destroy_image((*map)->mlx, (*map)->wall_img);
	if ((*map)->exit_img)
		mlx_destroy_image((*map)->mlx, (*map)->exit_img);
}

int	clean_exit(t_map **map, char **lst, int fd)
{
	ft_free_str(lst);
	ft_free_str((*map)->map);
	close(fd);
	free_images(map);
	mlx_destroy_window((*map)->mlx, (*map)->win);
	mlx_destroy_display((*map)->mlx);
	free((*map)->mlx);
	exit(0);
}

void	place_images(t_map **map, char **lst, int fd)
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
	{
		clean_exit(map, lst, fd);
		//free_and_close(list, map, fd, IMAGE_ERROR);
	}
}
/*
void	print(char **c)
{
	int	i = 0;
	while (c[i])
	{
		printf("%s\n", c[i]);
		i++;0
	}
	printf("\n");
}
*/

void	put_and_load_map(char **lst, t_map **map, int fd)
{

	int	(x), (y);
	place_images(map, lst, fd);
	y = 0;
	while (lst[y])
	{
		
		x = 0;
		while (lst[y][x])
		{
			if (lst[y][x] == '0')
				mlx_put_image_to_window((*map)->mlx, (*map)->win,
					       	(*map)->back_img, x * 32, y * 32);
		    else if (lst[y][x] == '1')
				mlx_put_image_to_window((*map)->mlx, (*map)->win,
						(*map)->wall_img, x * 32, y * 32);
			else if (lst[y][x] == 'E')
				mlx_put_image_to_window((*map)->mlx, (*map)->win,
						(*map)->exit_img, x * 32, y * 32);
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
	put_and_load_map(lst, map, fd);
	(*map)->map = lst;
//	mlx_hook((*map)->mlx, 2, 1L << 0, clean_exit, map);
	mlx_loop((*map)->mlx);
}
