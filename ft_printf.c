/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 12:20:00 by jinfeld           #+#    #+#             */
/*   Updated: 2017/09/07 12:55:56 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	getformat(char **str, t_flag *flag, va_list args)
{
	int		i;
	char	*flagstr;

	i = -1;
	while (str[0][++i])
	{
		if (str[0][i] == 'l' || str[0][i] == 'h'
			|| str[0][i] == 'j' || str[0][i] == 'z')
			break ;
	}
	flagstr = ft_strdup(*str);
	flagstr[i] = '\0';
	*str += i;
	flagparse(flag, flagstr, args);
}

int		typeselect(va_list args, char *str)
{
	t_flag	flag;

	flagnew(&flag);
	flag.c = str[ft_strlen(str) - 1];
	str[ft_strlen(str) - 1] = '\0';
	getformat(&str, &flag, args);
	getmod(&flag, str);
	if (flag.c == 'S' || flag.c == 'C' || (flag.c == 's' && flag.mod == 1)
		|| (flag.c == 'c' && flag.mod == 1))
	{
		flag.wstr = wconhub(args, flag.c, flag.mod);
		flag.wide = 1;
	}
	else
		flag.str = conhub(args, flag.c, flag.mod);
	if (flag.c == 'd' || flag.c == 'i' || flag.c == 'D' || flag.c == 'I')
	{
		if (flag.str && flag.str[0] == '-')
		{
			++flag.str;
			flag.isneg = 1;
		}
	}
	return (demprintz(flag));
}

int		findflag(char **str, char *format)
{
	int		i;
	char	*cpy;
	int		find;

	find = 0;
	i = 0;
	while (format[++i])
	{
		if (ft_strchr("SspdiouxXcDOUxC%", format[i]))
		{
			cpy = ft_strdup(format);
			cpy[i + 1] = '\0';
			*str = ft_strdup(cpy);
			ft_strdel(&cpy);
			find = 1;
			break ;
		}
	}
	if (!find)
		i = 0;
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	char	*str;
	int		i;
	int		meta[2];

	va_start(args, format);
	meta[0] = 0;
	i = -1;
	while (format[++i])
	{
		meta[1] = 0;
		if (format[i] == '%')
		{
			if (findflag(&str, (char*)&format[i]))
			{
				meta[0] += typeselect(args, str);
				meta[1] = 1;
			}
			i += findflag(&str, (char*)&format[i]);
		}
		if (format[i] && meta[1] == 0)
			meta[0] += ft_putchar_count(format[i]);
	}
	va_end(args);
	return (meta[0]);
}
