/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fille.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 20:05:11 by feljourb          #+#    #+#             */
/*   Updated: 2024/06/03 20:07:11 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood_file(t_map *map, int x, int y)
{
	if(x < 0  || x >= map->rows || y < 0 || y >= map->cols)
		return ;

	if (map->map_e[x][y] != 'P' && map->map_e[x][y] != 'C' && map->map_e[x][y] != 'E' && map->map_e[x][y] != '0')
		return ;
	if (map->map_e[x][y] == 'C')
		map->collectible_trouvé += 1;
	map->map_e[x][y] = 'V';
	flood_file(map, x + 1, y);
	flood_file(map, x - 1, y);
	flood_file(map, x , y + 1);
	flood_file(map, x , y - 1);
}

void chemin_valide(t_map *chemin)
{
	chemin->collectible_trouvé = 0;
	flood_file(chemin, chemin->player_x, chemin->player_y);
	if (chemin->map_e[chemin->exit_x][chemin->exit_y] != 'V' || chemin->collectible != chemin->collectible_trouvé)
		ft_error();
}