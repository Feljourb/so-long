/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:47:47 by feljourb          #+#    #+#             */
/*   Updated: 2024/05/29 02:25:49 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_name(char *av)
{
	int	len;

	len = ft_strlen(av);
	if (len < 4)
		ft_error();
	if (ft_strcmp(&av[len - 4], ".ber") != 0)
		ft_error();
}

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
				ft_error();
			count_line = 0;
		}
		else
			count_line++;
		i++;
	}
	if (first_line != count_line)
		ft_error();
}

void	ckeck_p_e_c(char *str)
{
	int	count_p;
	int	count_e;
	int	count_c;
	int	i;

	count_p = 0;
	count_e = 0;
	count_c = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			count_p++;
		else if (str[i] == 'E')
			count_e++;
		else if (str[i] == 'C')
			count_c++;
		i++;
	}
	if (count_p != 1 || count_e != 1 || count_c < 1)
		ft_error();
}

void	check_caractere(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			ft_error();
		if (str[i] == '1' || str[i] == '0' || str[i] == 'C' || str[i] == 'E'
			|| str[i] == 'P' || str[i] == '\n')
			i++;
		else
			ft_error();
	}
}
