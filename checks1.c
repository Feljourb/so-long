/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 01:49:42 by feljourb          #+#    #+#             */
/*   Updated: 2024/06/03 18:45:56 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_spl(char **spl)
{
	int	i;

	i = 0;
	while (spl[i])
	{
		free(spl[i]);
		i++;
	}
	free(spl);
}

void	check_f_l_indice_murs(t_map *map_murs)
{
	int	i;
	int	len;

	i = 0;
	while (map_murs->map[i] != NULL)
	{
		len = ft_strlen(map_murs->map[i]);
		if (map_murs->map[i][0] != '1' && map_murs->map[i][len - 1] != '1')
			ft_error();
		i++;
	}
}

void	check_murs(t_map *map_murs)
{
	int		i;
	int		last_index;
	last_index = 0;
	while (map_murs->map[last_index] != NULL)
		last_index++;
	last_index--;
	i = 0;
	while (map_murs->map[0][i] != '\0') //first line
	{
		if (map_murs->map[0][i] != '1')
			ft_error();
		i++;
	}
	i = 0;
	while (map_murs->map[last_index][i] != '\0') //last line
	{
		if (map_murs->map[last_index][i] != '1')
			ft_error();
		i++;
	}
	check_f_l_indice_murs(map_murs); //first && last indice
	//free_spl(spl);
}
