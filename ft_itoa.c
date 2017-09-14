/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 16:40:37 by jinfeld           #+#    #+#             */
/*   Updated: 2017/09/12 16:40:54 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits(uintmax_t n)
{
	int	dig;

	dig = 1;
	while (n /= 10)
		dig++;
	return (dig);
}

char		*ft_itoa(intmax_t n)
{
	int			dig;
	char		*res;
	uintmax_t	n1;
	int			neg;

	neg = n < 0 ? 1 : 0;
	n1 = n < 0 ? -n : n;
	dig = digits(n1);
	if (!(res = (char *)malloc(sizeof(char) * dig + neg + 1)))
		return (NULL);
	res[dig + neg] = '\0';
	if (neg)
		res[0] = '-';
	while (dig)
	{
		res[dig + neg - 1] = '0' + n1 % 10;
		n1 /= 10;
		dig--;
	}
	return (res);
}
