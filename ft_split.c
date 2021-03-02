/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonar <mathonar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 19:46:29 by mathonar          #+#    #+#             */
/*   Updated: 2020/09/20 11:25:11 by mathonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(char const *s, char c)
{
	int count;
	int i;
	int is_a_word;

	i = 0;
	count = 0;
	is_a_word = 0;
	while (s[i])
	{
		if (s[i] == c)
			is_a_word = 0;
		else if (s[i] != c && is_a_word == 0)
		{
			is_a_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

int		ft_word_size(char const *s, char c, int x)
{
	int size;

	size = 0;
	while (s[x])
	{
		if (s[x] != c)
			size++;
		else
			break ;
		x++;
	}
	return (size);
}

char	**ft_free_all(char **strs)
{
	unsigned int	a;

	a = 0;
	while (strs[a])
	{
		free(strs[a]);
		a++;
	}
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		x;
	int		l;

	if (!(s) || !(strs = malloc(sizeof(char*) * (ft_count_words(s, c) + 1))))
		return (NULL);
	i = -1;
	x = 0;
	while (++i < ft_count_words(s, c))
	{
		while (s[x] && s[x] == c)
			x++;
		if (!(strs[i] = malloc(sizeof(char) * (ft_word_size(s, c, x) + 1))))
			return (NULL);
		l = -1;
		while (++l < ft_word_size(s, c, x))
			strs[i][l] = s[x + l];
		strs[i][l] = '\0';
		x += ft_word_size(s, c, x);
	}
	strs[i] = NULL;
	return (strs);
	ft_free_all(strs);
}
