/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:18:54 by feljourb          #+#    #+#             */
/*   Updated: 2024/06/05 15:56:47 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_img(t_game *game)
{
	int hauteur;
	int largeur;
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr, "Xpm/player.xpm", &hauteur, &largeur);
	game->img_coin = mlx_xpm_file_to_image(game->mlx_ptr, "Xpm/coin.xpm", &hauteur, &largeur);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, "Xpm/exit.xpm", &hauteur, &largeur);
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, "Xpm/wall.xpm", &hauteur, &largeur);
	game->img_surface = mlx_xpm_file_to_image(game->mlx_ptr, "Xpm/surface.xpm", &hauteur, &largeur);
}
void draw_map(t_game *game, t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j  < map->cols)
		{
			if (map->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_player, j * 50, i * 50);
			else if (map->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_exit, j * 50, i * 50);
			else if (map->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_wall, j * 50, i * 50);
			else if (map->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_coin, j * 50, i * 50);
			else if (map->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_surface, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void init_game(t_game *game, t_map *map)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		perror("Error");
	game->win_ptr = mlx_new_window(game->mlx_ptr, 700, 300, "so_long");
	if (!game->win_ptr)
		perror("Error");
	load_img(game);
	draw_map(game, map);
	mlx_loop(game->mlx_ptr);
}

int main(int ac, char **av)
{
	char *str;
	char *line;
	int fd;
	t_map map;
	t_game game;

	str = ft_strdup("");
	line = ft_strdup("");
	if (ac != 2)
		ft_error();
	check_name(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		str = f_strjoin(str, line);
		free(line);
	}
	check_all(&map, str);
	init_game(&game, &map);
}
