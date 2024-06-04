/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 06:31:41 by feljourb          #+#    #+#             */
/*   Updated: 2024/06/04 09:56:34 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *save)
{
	char	*buff;
	int		rread;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!save)
		save = ft_strdup("");
	rread = 1;
	while (!ft_strchr(save) && rread != 0)
	{
		rread = read(fd, buff, BUFFER_SIZE);
		if (rread == -1)
		{
			free(buff);
			free(save);
			return (NULL);
		}
		buff[rread] = '\0';
		save = ft_strjoin(buff, save);
	}
	free(buff);
	return (save);
}

char	*ft_get_line(char *save)
{
	char	*str;
	int		i;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	str = malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_save(char *save, char *line)
{
	char	*rest;
	int		i;
	int		j;

	i = ft_strlen1(line);
	j = 0;
	if (line[0] == '\0')
	{
		free(save);
		return (NULL);
	}
	while (save[i++])
		j++;
	rest = malloc(j + 1);
	if (!rest)
		return (NULL);
	i = ft_strlen1(line);
	j = 0;
	while (save[i])
		rest[j++] = save[i++];
	rest[j] = '\0';
	free(save);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_file(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save(save, line);
	if (!save)
		return (free(line), NULL);
	return (line);
}
