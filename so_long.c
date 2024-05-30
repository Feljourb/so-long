/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:18:54 by feljourb          #+#    #+#             */
/*   Updated: 2024/05/29 02:28:41 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char		*str;
	char	 	*line;
	int			fd;

	str = ft_strdup("");
	line = ft_strdup("");
	if (ac != 2)
		ft_error();
	check_name(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		str = f_strjoin(str, line);
	}
	check_caractere(str);
	ckeck_p_e_c(str);
	check_rectangulaire(str);
	check_murs(str);
	printf("Done\n");
	close(fd);
}
