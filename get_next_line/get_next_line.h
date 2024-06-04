/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 06:32:36 by feljourb          #+#    #+#             */
/*   Updated: 2024/06/04 09:55:52 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
int		ft_strlen1(char *str);
int		ft_strchr(char *save);
char	*ft_strjoin(char *buff, char *save);
char	*ft_save(char *save, char *line);
char	*ft_get_line(char *save);
char	*read_file(int fd, char *save);
char	*ft_strdup(char *str);

#endif