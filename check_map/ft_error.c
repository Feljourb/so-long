/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:07:16 by feljourb          #+#    #+#             */
/*   Updated: 2024/07/11 18:29:10 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(t_map *map, char *str, int errno)
{
	(void)str;
	if (errno == 0)
		write(1, "Required two arguments \n", 24);
	else if (errno == -1)
		write(1, "Error in opening file \n", 23);
	else if (errno == 1)
		write(1, "Error: unrequired charactere \n", 30);
	else if (errno == 2)
		write(1, "Error: invalid compenant \n", 26);
	else if (errno == 3)
		write(1, "Error: invalid name \n", 21);
	else if (errno == 4)
		write(1, "Error: invalid forme \n", 22);
	else if (errno == 5)
		write(1, "Error: inclose wall \n", 21);
	else if (errno == 6)
		write(1, "Error: chemin pas valide \n", 26);
	if (str)
		free(str);
	if (map)
		cleaning_map(map);
	exit(1);
}
