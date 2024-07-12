/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:34:30 by feljourb          #+#    #+#             */
/*   Updated: 2024/07/12 11:47:20 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	dimension(t_map *map_d)
{
	int	i;

	i = ft_strlen(map_d->map[0]);
	map_d->cols = i;
	i = 0;
	while (map_d->map[i])
		i++;
	map_d->rows = i;
}

void	ft_map(t_map *map_first, char *str)
{
	map_first->map = ft_split(str, '\n');
	map_first->map_e = ft_split(str, '\n');
}

void	count_collectible(t_map *coint)
{
	int	i;
	int	j;

	i = 0;
	coint->collectible = 0;
	while (i < coint->rows)
	{
		j = 0;
		while (j < coint->cols)
		{
			if (coint->map[i][j] == 'C')
				coint->collectible += 1;
			j++;
		}
		i++;
	}
}

void	position_player_exit(t_map *map_p_e)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_p_e->rows)
	{
		j = 0;
		while (j < map_p_e->cols)
		{
			if (map_p_e->map[i][j] == 'P')
			{
				map_p_e->player_x = i;
				map_p_e->player_y = j;
			}
			else if (map_p_e->map[i][j] == 'E')
			{
				map_p_e->exit_x = i;
				map_p_e->exit_y = j;
			}
			j++;
		}
		i++;
	}
}

void	init_map(t_map *map_init, char *str)
{
	map_init->player_x = -1;
	map_init->player_y = -1;
	map_init->exit_x = -1;
	map_init->exit_y = -1;
	map_init->mouv_count = 0;
	ft_map(map_init, str);
	dimension(map_init);
	count_collectible(map_init);
	position_player_exit(map_init);
}
