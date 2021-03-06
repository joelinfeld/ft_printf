/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formathandlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:15:50 by jinfeld           #+#    #+#             */
/*   Updated: 2017/09/19 16:23:17 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			leftpad(t_flag flag, int *len)
{
	int	chars;

	chars = 0;
	if (flag.plus && !flag.isneg &&
		(flag.c == 'd' || flag.c == 'D' || flag.c == 'i'))
		*len += 1;
	if (flag.space && *len >= flag.marg && !flag.plus && ft_atoi(flag.str) >= 0
		&& !(flag.c == 'c' && ft_atoi(flag.str) == 0)
			&& !flag.isneg && flag.str[0] != '%')
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

int			rightpad(t_flag flag, int len)
{
	int	chars;

	chars = 0;
	if (flag.minus)
		chars += printminus(flag, len);
	return (chars);
}

static void	handleprecisionhelp2(t_flag *flag, int *len, char *str)
{
	if (flag->precision < *len)
	{
		str = ft_strndup(flag->str, flag->precision);
		flag->str = ft_strdup(str);
		*len = ft_strlen(flag->str);
		flag->edit = 1;
	}
	ddelete(&str);
}

static void	handleprecisionhelp(t_flag *flag, int *len, char *str, char *str2)
{
	int	i;

	i = -1;
	if (flag->precision && flag->c == 's' && flag->str != NULL)
		handleprecisionhelp2(flag, len, str);
	if (flag->precision > *len && flag->c != 's'
		&& flag->c != 'c' && flag->str != NULL)
	{
		i = -1;
		str = ft_strnew(flag->precision - *len);
		while (++i < flag->precision - *len)
			str[i] = '0';
		str2 = ft_strjoin(str, flag->str);
		ddelete(&(flag->str));
		flag->str = ft_strdup(str2);
		*len = ft_strlen(flag->str);
		flag->edit = 1;
	}
	ddelete(&str2);
	ddelete(&str);
}

int			handleprecision(t_flag *flag, int len)
{
	char	*str;
	char	*str2;

	str = NULL;
	str2 = NULL;
	handleprecisionhelp(flag, &len, str, str2);
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
