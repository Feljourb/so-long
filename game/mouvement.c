/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:00:00 by 9 by feljou       #+#    #+#             */
/*   Updated: 2024/07/11 21:08:47 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	win(t_game *game, char pos)
{
	if (pos == 'E' && game->map.collectible == 0)
	{
		write(1, "you win!\n", 9);
		close_window(game);
	}
}

void	mouv_up(t_game *game)
{
	int		new_x;
	int		new_y;
	char	pos;

	new_x = game->map.player_x - 1;
	new_y = game->map.player_y;
	if (new_x < 0)
		return ;
	pos = game->map.map[new_x][new_y];
	if (pos != '1' && pos != 'E')
	{
		game->map.mouv_count++;
		if (pos == 'C')
		{
			game->map.collectible--;
			game->map.map[new_x][new_y] = '0';
		}
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_surface,
			game->map.player_y * 50, game->map.player_x * 50);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_player,
			new_y * 50, new_x * 50);
		game->map.player_x = new_x;
		print_mouv(game);
	}
	win(game, pos);
}

void	mouv_down(t_game *game)
{
	int		new_x;
	int		new_y;
	char	pos;

	new_x = game->map.player_x + 1;
	new_y = game->map.player_y;
	if (new_x < 0)
		return ;
	pos = game->map.map[new_x][new_y];
	if (pos != '1' && pos != 'E')
	{
		game->map.mouv_count++;
		if (pos == 'C')
		{
			game->map.collectible--;
			game->map.map[new_x][new_y] = '0';
		}
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_surface,
			game->map.player_y * 50, game->map.player_x * 50);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_player,
			new_y * 50, new_x * 50);
		game->map.player_x = new_x;
		print_mouv(game);
	}
	win(game, pos);
}

void	mouv_right(t_game *game)
{
	int		new_x;
	int		new_y;
	char	pos;

	new_x = game->map.player_x;
	new_y = game->map.player_y + 1;
	if (new_x < 0)
		return ;
	pos = game->map.map[new_x][new_y];
	if (pos != '1' && pos != 'E')
	{
		game->map.mouv_count++;
		if (pos == 'C')
		{
			game->map.collectible--;
			game->map.map[new_x][new_y] = '0';
		}
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_surface,
			game->map.player_y * 50, game->map.player_x * 50);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_player,
			new_y * 50, new_x * 50);
		game->map.player_y = new_y;
		print_mouv(game);
	}
	win(game, pos);
}

void	mouv_left(t_game *game)
{
	int		new_x;
	int		new_y;
	char	pos;

	new_x = game->map.player_x;
	new_y = game->map.player_y - 1;
	if (new_x < 0)
		return ;
	pos = game->map.map[new_x][new_y];
	if (pos != '1' && pos != 'E')
	{
		game->map.mouv_count++;
		if (pos == 'C')
		{
			game->map.collectible--;
			game->map.map[new_x][new_y] = '0';
		}
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_surface,
			game->map.player_y * 50, game->map.player_x * 50);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_player,
			new_y * 50, new_x * 50);
		game->map.player_y = new_y;
		print_mouv(game);
	}
	win(game, pos);
}
