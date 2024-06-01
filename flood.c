/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:34:30 by feljourb          #+#    #+#             */
/*   Updated: 2024/06/01 19:08:12 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *map, char **spl)
{
	int i;
	int j;
	
	map->map = spl;
	map->exit_x = -1;
	map->exit_y = -1;
	map->player_x = -1;
	map->player_y = -1;
	i = 0;
	while(spl[i] < map->lignes)
	{
		j = 0;
		while(spl[j] < map->collones)
		{
			if(spl[i][j] == 'P')
			{
				map->player_x = i;
				map->player_y = j;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while(spl[i] < map->lignes)
	{
		j = 0;
		while(spl[j] < map->collones)
		{
			if(spl[i][j] == 'E')
			{
				map->exit_x = i;
				map->exit_y = j;
			}
			j++;
		}
		i++;
	}
}
