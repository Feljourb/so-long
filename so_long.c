/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:18:54 by feljourb          #+#    #+#             */
/*   Updated: 2024/06/03 21:58:30 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char		*str;
	char	 	*line;
	int			fd;
	t_map map;
	
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
	close(fd);
	init_map(&map, str);
	check_caractere(str);
	chemin_valide(&map);
	print_map(&map);
	ckeck_p_e_c(str);
	check_rectangulaire(str);
	check_murs(&map);
	printf("Done\n");
	void *mlx_ptr = mlx_init();
	if(!mlx_ptr)
		perror("error");
	void *win_ptr = mlx_new_window(mlx_ptr, 500,500, "so_long");
	if(!win_ptr)
		perror("error");
	mlx_loop(mlx_ptr);
}
