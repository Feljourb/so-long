/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:45:54 by feljourb          #+#    #+#             */
/*   Updated: 2024/07/12 14:42:05 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_game(t_game *game, t_map *map)
{
	game->map = *map;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, map->cols * 50, map->rows
			* 50, "so_long");
	load_img(game);
	draw_map(game, map);
	mlx_hook(game->win_ptr, 17, 0, close_window, game);
	mlx_key_hook(game->win_ptr, key_hook, game);
	mlx_loop(game->mlx_ptr);
}
