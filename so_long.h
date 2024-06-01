/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:18:52 by feljourb          #+#    #+#             */
/*   Updated: 2024/06/01 18:44:35 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h> 
# include <string.h>
# include "Gnl/get_next_line.h"

typedef struct s_map
{
    char **map;
    int player_x;
    int player_y;
    int exit_x;
    int exit_y;
    int collones;
    int lignes;
} t_map;

void	ft_error(void);
char	*f_strjoin(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);

void	check_name(char *av);
void	check_murs(char *str);
void	check_f_l_indice_murs(char **spl);
void	check_rectangulaire(char *str);
void	ckeck_p_e_c(char *str);
void	check_caractere(char *str);

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif