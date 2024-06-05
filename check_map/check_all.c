/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:05:53 by feljourb          #+#    #+#             */
/*   Updated: 2024/06/05 11:29:29 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_all(t_map *map, char *str)
{
	init_map(map, str);
	check_caractere(str);
	ckeck_p_e_c(str);
	check_rectangulaire(str);
	check_murs(map);
	chemin_valide(map);
	
}
