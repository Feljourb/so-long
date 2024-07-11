/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_murs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 01:49:42 by feljourb          #+#    #+#             */
/*   Updated: 2024/07/11 10:00:46 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_rectangulaire(char *str)
{
	int	i;
	int	first_line;
	int	count_line;

	i = 0;
	first_line = 0;
	count_line = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (first_line == 0)
				first_line = count_line;
			else if (first_line != count_line)
				ft_error(NULL, str, 4);
			count_line = 0;
		}
		else
			count_line++;
		i++;
	}
	if (first_line != count_line)
		ft_error(NULL, str, 4);
}

void	check_first_last_indice(t_map *map_murs)
{
	int	i;
	int	len;

	i = 0;
	while (map_murs->map[i] != NULL)
	{
		len = ft_strlen(map_murs->map[i]);
		if (map_murs->map[i][0] != '1' || map_murs->map[i][len - 1] != '1')
			ft_error(map_murs, NULL, 5);
		i++;
	}
}

void	check_murs(t_map *map_murs)
{
	int	i;
	int	last_index;

	last_index = 0;
	while (map_murs->map[last_index] != NULL)
		last_index++;
	last_index--;
	i = 0;
	while (map_murs->map[0][i] != '\0')
	{
		if (map_murs->map[0][i] != '1')
			ft_error(map_murs, NULL, 5);
		i++;
	}
	i = 0;
	while (map_murs->map[last_index][i] != '\0')
	{
		if (map_murs->map[last_index][i] != '1')
			ft_error(map_murs, NULL, 5);
		i++;
	}
	check_first_last_indice(map_murs);
}
