/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:18:52 by feljourb          #+#    #+#             */
/*   Updated: 2024/06/03 21:43:38 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h> 
# include <string.h>
# include "minilibx_linux/mlx.h"
# include "Gnl/get_next_line.h"

typedef struct s_map
{
    char **map;
    char **map_e;
    int player_x;
    int player_y;
    int exit_x;
    int exit_y;
    int rows; //  lignes
    int cols; // collones
    int collectible;
	int collectible_trouvé;
} t_map;



//_____________checker_________________

void	ft_error(void);
void	check_name(char *av);
void	check_murs(t_map *map_murs);
void	check_f_l_indice_murs(t_map *map_murs);
void	check_rectangulaire(char *str);
void	ckeck_p_e_c(char *str);
void	check_caractere(char *str);
void	dimension(t_map *map_d);
void	init_map(t_map *map_init , char *str);
void	flood_file(t_map *map, int x, int y);
void	chemin_valide(t_map *path);
void	print_map(t_map *map);
void	ft_map(t_map *map_first, char *str);
void	count_collectible(t_map *coint);

//________________utils____________________

unsigned int	ft_strlen(const char *str);
char	*f_strjoin(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif