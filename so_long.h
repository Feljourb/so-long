/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:18:52 by feljourb          #+#    #+#             */
/*   Updated: 2024/06/06 15:36:45 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h> 
# include <string.h>
# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"

#define ESC_KEY 65307
#define KEY_W 13 // Touche 'w'
#define KEY_A 0  // Touche 'a'
#define KEY_S 1  // Touche 's'
#define KEY_D 2  // Touche 'd'

typedef struct s_map
{
	char	**map;
	char	**map_e;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		rows; //  lignes
	int		cols; // collones
	int		collectible;
	int		collectible_trouve;
}	t_map;

typedef struct s_game
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_wall;
    void *img_player;
    void *img_coin;
    void *img_exit;
	void *img_surface;
	t_map map;
}	t_game;

//_____________checker_________________

void			ft_error(void);
void			check_name(char *av);
void			check_murs(t_map *map_murs);
void			check_first_last_indice(t_map *map_murs);
void			check_rectangulaire(char *str);
void			ckeck_p_e_c(char *str);
void			check_caractere(char *str);
void			dimension(t_map *map_d);
void			init_map(t_map *map_init, char *str);
void			ft_flood_fill(t_map *map, int x, int y);
void			chemin_valide(t_map *path);
void			print_map(t_map *map);
void			ft_map(t_map *map_first, char *str);
void			count_collectible(t_map *coint);
void			position_player_exit(t_map *map_p_e);
void			check_all(t_map *map, char *str);

//________________utils____________________

unsigned int	ft_strlen(const char *str);
char			*f_strjoin(char *s1, char *s2);
int				ft_strcmp(char *s1, char *s2);

char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			free_map(t_map *map);

#endif