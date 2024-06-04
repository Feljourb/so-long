/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 20:05:11 by feljourb          #+#    #+#             */
/*   Updated: 2024/06/04 11:47:53 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->rows || y < 0 || y >= map->cols)
		return ;
	if (map->map_e[x][y] != 'P' && map->map_e[x][y] != 'C' && map->map_e[x][y]
		!= 'E' && map->map_e[x][y] != '0')
		return ;
	if (map->map_e[x][y] == 'C')
		map->collectible_trouve += 1;
	map->map_e[x][y] = 'V';
	ft_flood_fill(map, x + 1, y);
	ft_flood_fill(map, x - 1, y);
	ft_flood_fill(map, x, y + 1);
	ft_flood_fill(map, x, y - 1);
}

void	chemin_valide(t_map *chemin)
{
	chemin->collectible_trouve = 0;
	ft_flood_fill(chemin, chemin->player_x, chemin->player_y);
	if (chemin->map_e[chemin->exit_x][chemin->exit_y] != 'V'
		|| chemin->collectible != chemin->collectible_trouve)
		ft_error();
}
