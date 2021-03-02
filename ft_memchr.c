/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonar <mathonar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 19:46:02 by mathonar          #+#    #+#             */
/*   Updated: 2020/09/17 14:19:31 by mathonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_c;
	unsigned int	i;

	s_c = (unsigned char *)s;
	i = 0;
	while (i < n && s_c[i] != (unsigned char)c)
		i++;
	if (i == n)
		return (NULL);
	return ((void *)&s_c[i]);
}
