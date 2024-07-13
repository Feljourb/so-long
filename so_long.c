/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:18:54 by feljourb          #+#    #+#             */
/*   Updated: 2024/07/13 11:38:55 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	*str;
	char	*line;
	int		fd;
	t_map	map;
	t_game	game;

	if (ac != 2)
		ft_error(NULL, NULL, 0);
	check_name(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error(NULL, NULL, -1);
	str = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		str = f_strjoin(str, line);
		free(line);
	}
	check_all(&map, str);
	init_game(&game, &map);
	close_window(&game);
	return (close(fd), 0);
}
