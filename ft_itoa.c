/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 16:40:37 by jinfeld           #+#    #+#             */
/*   Updated: 2017/01/19 15:57:09 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits(long n)
{
	int	dig;

	dig = 0;
	if (n < 0)
	{
		n *= -1;
		dig++;
	}
	while (n >= 10)
	{
		n /= 10;
		dig++;
	}
	if (n < 10)
		dig++;
	return (dig);
}

char		*ft_itoa(int n)
{
	int		dig;
	char	*res;
	long	nb;

	nb = n;
	dig = digits(nb);
	if (!(res = (char *)malloc(sizeof(char) * dig + 1)))
		return (NULL);
	res[dig] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		res[0] = '-';
	}
	while (nb >= 10)
	{
		res[--dig] = nb % 10 + '0';
		nb /= 10;
	}
	res[--dig] = nb + '0';
	return (res);
}
