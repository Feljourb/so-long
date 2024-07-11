/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:42:32 by feljourb          #+#    #+#             */
/*   Updated: 2024/07/11 20:59:53 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_surface_coin(t_game *game, t_map *map, int i, int j)
{
	if (map->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_coin, j
			* 50, i * 50);
	else if (map->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_surface,
			j * 50, i * 50);
}

void	draw_map(t_game *game, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img_player, j * 50, i * 50);
			else if (map->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img_exit, j * 50, i * 50);
			else if (map->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img_wall, j * 50, i * 50);
			draw_surface_coin(game, map, i, j);
			j++;
		}
		i++;
	}
}
