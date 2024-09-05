/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:18:52 by feljourb          #+#    #+#             */
/*   Updated: 2024/09/05 14:07:30 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "m_minilbx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

# define ESC_KEY 65307
# define KEY_W 119       // Touche 'w'
# define KEY_A 97        // Touche 'a'
# define KEY_S 115       // Touche 's'
# define KEY_D 100       // Touche 'd'
# define KEY_UP 65362    // Flèche haut
# define KEY_DOWN 65364  // Flèche bas
# define KEY_LEFT 65361  // Flèche gauche
# define KEY_RIGHT 65363 // Flèche droite

typedef struct s_map
{
	char		**map;
	char		**map_e;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
	int			rows;
	int			cols;
	int			collectible;
	int			collectible_trouve;
	int			mouv_count;
}				t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_wall;
	void		*img_player;
	void		*img_coin;
	void		*img_exit;
	void		*img_surface;
	t_map		map;
}				t_game;

//_____________checker_________________

void			ft_error(t_map *map_murs, char *str, int nb);
void			check_name(char *av);
void			check_murs(t_map *map_murs);
void			check_first_last_indice(t_map *map_murs);
void			check_rectangulaire(char *str);
void			ckeck_p_e_c(char *str);
void			check_caractere(char *str);
void			check_all(t_map *map, char *str);

//________________map___________________

void			ft_map(t_map *map_first, char *str);
void			init_map(t_map *map_init, char *str);
void			dimension(t_map *map_d);
void			ft_flood_fill(t_map *map, int x, int y);
void			chemin_valide(t_map *path);
void			count_collectible(t_map *coint);
void			position_player_exit(t_map *map_p_e);

//________________utils____________________

unsigned int	ft_strlen(const char *str);
char			*f_strjoin(char *s1, char *s2);
int				ft_strcmp(char *s1, char *s2);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t n);

//_________________game_________________________

void			init_game(t_game *game, t_map *map);
void			load_img(t_game *game);
void			draw_surface_coin(t_game *game, t_map *map, int i, int j);
void			draw_map(t_game *game, t_map *map);
int				key_hook(int keycode, t_game *game);
void			win(t_game *game, char pos);
void			mouv_up(t_game *game);
void			mouv_down(t_game *game);
void			mouv_right(t_game *game);
void			mouv_left(t_game *game);
void			print_mouv(t_game *game);
int				close_window(t_game *game);

//___________________free_________________________

void			free_map(char **map);
void			cleaning_map(t_map *map);

#endif