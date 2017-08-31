/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 16:40:37 by jinfeld           #+#    #+#             */
/*   Updated: 2017/06/20 15:01:03 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	digits(intmax_t n)
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
	while (n1 >= 10)
	{
		res[--dig + neg] = n1 % 10 + '0';
		n1 /= 10;
	}
	res[--dig + neg] = n1 + '0';
	return (res);
}

int		main(void)
{
	long long int a = -9223372036854775808;
	char		*s = ft_itoa(a);
	printf("%lld\n", a);
	printf("%s\n", s);
	return (0);
}
