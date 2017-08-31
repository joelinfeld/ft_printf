/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formathandlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:15:50 by jinfeld           #+#    #+#             */
/*   Updated: 2017/08/29 08:31:51 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		leftpad(t_flag flag, int *len)
{
	int	chars;

	chars = 0;
	if (flag.plus && !flag.isneg &&
		(flag.c == 'd' || flag.c == 'D' || flag.c == 'i'))
		*len += 1;
	if (flag.space && *len >= flag.marg && !flag.plus && ft_atoi(flag.str) >= 0
		&& !(flag.c == 'c' && ft_atoi(flag.str) == 0) && !flag.isneg && flag.str[0] != '%')
		chars += ft_putchar_count(' ');
	if (flag.marg)
		chars += printmarg(flag, *len);
	if (flag.octothorpe == 1)
		printocto(flag);
	if (flag.c == 'p')
		printocto(flag);
	if (flag.plus && !flag.isneg &&
		(flag.c == 'd' || flag.c == 'D' || flag.c == 'i'))
		chars += ft_putchar_count('+');
	if (flag.isneg)
		ft_putchar('-');
	if (flag.zero && !flag.minus)
		chars += printzero(flag, *len);
	return (chars);
}

int		rightpad(t_flag flag, int len)
{
	int	chars;

	chars = 0;
	if (flag.minus)
		chars += printminus(flag, len);
	return (chars);
}

int		handleprecision(t_flag *flag, int len)
{
	int		i;
	char	*str;
	char	*str2;

	i = 0;
	if (flag->precision && flag->c == 's' && flag->str != NULL)
	{
		if (flag->precision < len)
		{
			str = ft_strnew(flag->precision);
			str = ft_strncpy(str, flag->str, flag->precision);
			flag->str = str;
			flag->str[flag->precision] = '\0';
			len = ft_strlen(flag->str);
		}
	}
	if (flag->precision > len && flag->c != 's'
		&& flag->c != 'c' && flag->str != NULL)
	{
		i = -1;
		str = ft_strnew(flag->precision - len);
		while (++i < flag->precision - len)
			str[i] = '0';
		str2 = ft_strjoin(str, flag->str);
		flag->str = str2;
		len = ft_strlen(flag->str);
	}
	if (flag->precision < len && flag->c != 's'
		&& flag->c != 'c' && flag->str != NULL)
	{
		if (flag->str[0] == '0')
		{
			flag->str[0] = '\0';
			len = 0;
		}
	}
	return (len);
}
