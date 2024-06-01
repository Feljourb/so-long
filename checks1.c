/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 01:49:42 by feljourb          #+#    #+#             */
/*   Updated: 2024/06/01 18:19:54 by feljourb         ###   ########.fr       */
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

void	check_f_l_indice_murs(char **spl)
{
	int	i;
	int	len;

	i = 0;
	while (spl[i] != NULL)
	{
		len = ft_strlen(spl[i]);
		if (spl[i][0] != '1' && spl[i][len - 1] != '1')
			ft_error();
		i++;
	}
}

void	check_murs(char *str)
{
	char	**spl;
	int		i;
	int		last_index;

	spl = ft_split(str, '\n');
	last_index = 0;
	while (spl[last_index] != NULL)
		last_index++;
	last_index--;
	i = 0;
	while (spl[0][i] != '\0') //first line
	{
		if (spl[0][i] != '1')
			ft_error();
		i++;
	}
	i = 0;
	while (spl[last_index][i] != '\0') //last line
	{
		if (spl[last_index][i] != '1')
			ft_error();
		i++;
	}
	check_f_l_indice_murs(spl); //first && last indice
	//free_spl(spl);
}
