/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonar <mathonar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 19:46:40 by mathonar          #+#    #+#             */
/*   Updated: 2020/09/17 23:20:26 by mathonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	tot_len;

	i = 0;
	j = 0;
	tot_len = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	while (src[j])
		j++;
	tot_len = i + j;
	if (i == dstsize)
		return (tot_len);
	j = 0;
	while (src[j] && i + j < dstsize - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (tot_len);
}
