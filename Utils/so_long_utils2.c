/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:57:38 by feljourb          #+#    #+#             */
/*   Updated: 2024/06/04 11:55:46 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static int	word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

char	*free_splite(char **s, int i)
{
	while (i <= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
	return (NULL);
}

char	*f_strdup(char *s1)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s1);
	ptr = (char *)malloc((len + 1));
	if (!ptr)
		return (NULL);
	ft_memcpy (ptr, s1, len);
	ptr[len] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		word;
	int		len_word;
	int		i;

	if (!s)
		return (NULL);
	word = count_words(s, c);
	str = (char **)malloc((word + 1) * sizeof(char *));
	if (!str)
		return (0);
	i = -1;
	while (++i < word)
	{
		while (*s == c)
			s++;
		len_word = word_len(s, c);
		str[i] = ft_substr(s, 0, len_word);
		if (!str[i])
			free_splite(str, i);
		s = s + len_word;
	}
	str[i] = NULL;
	return (str);
}
