/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:01:23 by feljourb          #+#    #+#             */
/*   Updated: 2024/06/04 09:56:18 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *save)
{
	int	i;

	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *buff, char *save)
{
	char	*all;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!buff)
		return (NULL);
	all = malloc(sizeof(char) * (ft_strlen1(buff) + ft_strlen1(save) + 1));
	if (!all)
		return (NULL);
	while (save[i])
	{
		all[i] = save[i];
		i++;
	}
	while (buff[y])
	{
		all[i++] = buff[y++];
	}
	all[i] = '\0';
	free(save);
	return (all);
}

char	*ft_strdup(char *str)
{
	char	*sstr;
	int		i;

	i = 0;
	sstr = malloc(sizeof(char) * (ft_strlen1(str) + 1));
	if (!sstr)
		return (NULL);
	while (str[i])
	{
		sstr[i] = str[i];
		i++;
	}
	sstr[i] = '\0';
	return (sstr);
}
