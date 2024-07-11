/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:46:45 by feljourb          #+#    #+#             */
/*   Updated: 2024/07/11 20:48:17 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_game *game)
{
	if (game->img_coin)
		mlx_destroy_image(game->mlx_ptr, game->img_coin);
	if (game->img_player)
		mlx_destroy_image(game->mlx_ptr, game->img_player);
	if (game->img_exit)
		mlx_destroy_image(game->mlx_ptr, game->img_exit);
	if (game->img_wall)
		mlx_destroy_image(game->mlx_ptr, game->img_wall);
	if (game->img_surface)
		mlx_destroy_image(game->mlx_ptr, game->img_surface);
	if (game->map.map)
		cleaning_map(&game->map);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		close_window(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		mouv_up(game);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		mouv_down(game);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		mouv_right(game);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		mouv_left(game);
	return (0);
}
