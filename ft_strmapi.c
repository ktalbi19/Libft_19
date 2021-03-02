/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonar <mathonar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 19:46:48 by mathonar          #+#    #+#             */
/*   Updated: 2020/09/06 19:46:48 by mathonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*out_str;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (!(out_str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		out_str[i] = f(i, s[i]);
		i++;
	}
	out_str[i] = '\0';
	return (out_str);
}
