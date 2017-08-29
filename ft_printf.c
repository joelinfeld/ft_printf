/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 12:20:00 by jinfeld           #+#    #+#             */
/*   Updated: 2017/08/29 07:47:29 by jinfeld          ###   ########.fr       */
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
		if (str[0][i] == 'l' || str[0][i] == 'h' || str[0][i] == 'j' || str[0][i] == 'z')
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
	int		len;

	flagnew(&flag);
	len = ft_strlen(str);
	flag.c = str[len - 1];
	str[len - 1] = '\0';
	getformat(&str, &flag, args);
	getmod(&flag, str);
	if (flag.c == 'S' || flag.c == 'C' || (flag.c == 's' && flag.mod == 1) || (flag.c == 'c' && flag.mod == 1))
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
	return(demprintz(flag));
}

int		findflag(char **str, char *format)
{
	int		i;
	char	*cpy;
	int		find = 0;
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
	int		skip;
	int		chars;
	int		find;

	va_start(args, format);
	chars = 0;
	i = 0;
	find = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			skip = findflag(&str, (char*)&format[i]);
			if (skip)
			{
				chars += typeselect(args, str);
				find = 1;
			}
			i += skip;
		}
		if (format[i] && find == 0)
			chars += ft_putchar_count(format[i]);
		i++;
		find = 0;
	}
	va_end(args);
	return (chars);
}

/*
int		main(void)
{
	ft_printf("%*");
	return (0);
}
*/
