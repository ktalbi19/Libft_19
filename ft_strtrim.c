/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonar <mathonar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 23:02:33 by mathonar          #+#    #+#             */
/*   Updated: 2020/09/16 18:12:47 by mathonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char					*ft_strtrim(char const *s1, char const *set)
{
	int				i;
	int				start;
	int				end;
	unsigned int	size;
	char			*rstr;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && is_in_set(s1[i], set))
		i++;
	start = i;
	if ((i = ft_strlen(s1) - 1) != -1)
		while (i >= 0 && is_in_set(s1[i], set))
			i--;
	end = i;
	size = end - start + 2;
	if (!(rstr = malloc(sizeof(char) * size)))
		return (NULL);
	i = start - 1;
	while (++i <= end)
		rstr[i - start] = s1[i];
	rstr[i - start] = '\0';
	return (rstr);
}
