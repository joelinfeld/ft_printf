/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 17:07:55 by jinfeld           #+#    #+#             */
/*   Updated: 2017/08/23 17:08:30 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar_count(char c)
{
	write(1, &c, 1);
	return (1);
}

void	printocto(t_flag flag)
{
	if ((flag.c == 'x' && ft_atoi(flag.str) != 0) || flag.c == 'p')
		ft_putstr("0x");
	if (flag.c == 'X' && ft_atoi(flag.str) != 0)
		ft_putstr("0X");
	if (flag.c == 'o' && (ft_atoi(flag.str) != 0 || flag.precision == 0))
		ft_putchar('0');
}

int		printzero(t_flag flag, int len)
{
	int i;
	int chars;

	i = 0;
	chars = 0;
	if (flag.precision != -10000)
	{
		while (++i <= flag.zero - len)
			chars += ft_putchar_count(' ');
	}
	else
	{
		while (++i <= flag.zero - len)
			chars += ft_putchar_count('0');
	}
	return (chars);
}

int		printmarg(t_flag flag, int len)
{
	int i;
	int chars;

	i = 0;
	chars = 0;
	while (++i <= flag.marg - len)
		chars += ft_putchar_count(' ');
	return (chars);
}

int		printminus(t_flag flag, int len)
{
	int	i;
	int	chars;

	i = 0;
	chars = 0;
	while (++i <= flag.minus - len)
		chars += ft_putchar_count(' ');
	return (chars);
}
