/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonar <mathonar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 19:45:53 by mathonar          #+#    #+#             */
/*   Updated: 2020/09/19 23:29:38 by mathonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_len(long long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_opp(int i, long long n, char *str)
{
	i = i - 1;
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int nb)
{
	char		*str;
	long long	n;
	int			i;

	n = nb;
	i = ft_len(n);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (n == 0)
		str[0] = 48;
	else if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	str = ft_opp(i, n, str);
	str[i] = '\0';
	return (str);
}
