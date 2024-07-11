/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:40:52 by feljourb          #+#    #+#             */
/*   Updated: 2024/07/11 20:41:29 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_img(t_game *game)
{
	int	hauteur;
	int	largeur;

	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr, "Xpm/player.xpm",
			&hauteur, &largeur);
	game->img_coin = mlx_xpm_file_to_image(game->mlx_ptr, "Xpm/coin.xpm",
			&hauteur, &largeur);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, "Xpm/exit.xpm",
			&hauteur, &largeur);
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, "Xpm/wall.xpm",
			&hauteur, &largeur);
	game->img_surface = mlx_xpm_file_to_image(game->mlx_ptr, "Xpm/surface.xpm",
			&hauteur, &largeur);
}
