/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonar <mathonar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 19:45:59 by mathonar          #+#    #+#             */
/*   Updated: 2020/09/13 14:46:20 by mathonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_c;
	unsigned char	*src_c;

	src_c = (unsigned char*)src;
	dst_c = (unsigned char*)dst;
	i = 0;
	while (i < n && src_c[i] != (unsigned char)c)
	{
		dst_c[i] = src_c[i];
		i++;
	}
	if (i != n)
	{
		dst_c[i] = src_c[i];
		i++;
		return (&dst_c[i]);
	}
	else
		return (NULL);
}
