/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:34:30 by feljourb          #+#    #+#             */
/*   Updated: 2024/06/03 20:06:36 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void dimension(t_map *map_d)
{
	int i = 0;
	i = ft_strlen(map_d->map[0]);
	map_d->cols = i;
	i = 0;
	while(map_d->map[i])
		i++;
	map_d->rows = i;
}

void ft_map(t_map *map_first, char *str)
{
	map_first->map = ft_split(str, '\n');
	map_first->map_e = ft_split(str, '\n');
}

void count_collectible(t_map *coint)
{
	int i;
	int	j;

	i = 0;
	coint->collectible = 0;
	while (i < coint->rows)
	{
		j = 0;
		while(j < coint->cols)
		{
			if (coint->map[i][j] == 'C')
				coint->collectible += 1;
			j++;
		}
		i++;
	}
}

void init_map(t_map *map_init , char *str)
{	
	ft_map(map_init, str);
	map_init->player_x = -1;
	map_init->player_y = -1;
	map_init->exit_x = -1;
	map_init->exit_y = -1;
	int i = 0;
	int j;
	dimension(map_init);
	count_collectible(map_init);
	while(i < map_init->rows)
	{
		j = 0;
		while(j < map_init->cols)
		{
			if (map_init->map[i][j] == 'P')
			{
				map_init->player_x = i;
				map_init->player_y = j;
			}
			else if(map_init->map[i][j] == 'E')
			{
				map_init->exit_x = i;
				map_init->exit_y = j;
			}
			j++;
		}
		i++;
	}
}

void print_map(t_map *map)
{
	int i =0;
	int j;
	while(i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			printf("%c", map->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
