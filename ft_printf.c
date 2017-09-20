/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 12:20:00 by jinfeld           #+#    #+#             */
/*   Updated: 2017/09/19 16:21:45 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void		typeselecthelp(t_flag *flag)
{
	char *cpy;

	cpy = NULL;
	if (flag->str && flag->str[0] == '-')
	{
		cpy = ft_strdup(&(flag->str[1]));
		ddelete(&(flag->str));
		flag->str = ft_strdup(cpy);
		ddelete(&cpy);
		flag->isneg = 1;
	}
}

static int		typeselect(va_list args, char *str)
{
	t_flag	flag;
	int		chars;

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
		typeselecthelp(&flag);
	chars = demprintz(flag);
	if (flag.str && (flag.c != 's' || flag.edit == 1) && flag.c != '%')
		ddelete(&(flag.str));
	if (flag.c == 'C' || (flag.c == 'c' && flag.mod == 1))
		free(flag.wstr);
	return (chars);
}

static int		findflag(char **str, char *format)
{
	int		i;
	char	*cpy;
	int		find;

	find = 0;
	i = -1;
	while (format[++i])
	{
		if (ft_strchr("SspdiouxXcDOUxC%", format[i]))
		{
			cpy = ft_strdup(format);
			cpy[i + 1] = '\0';
			ddelete(str);
			*str = ft_strdup(cpy);
			ddelete(&cpy);
			find = 1;
			break ;
		}
	}
	if (!find)
		return (0);
	return (i + 1);
}

static void		metavalues(int meta[3], va_list args, char *str)
{
	meta[0] += typeselect(args, str);
	meta[1] = 1;
}

int				ft_printf(const char *format, ...)
{
	va_list	args;
	char	*str;
	int		i;
	int		meta[3];

	va_start(args, format);
	meta[0] = 0;
	meta[2] = 0;
	i = -1;
	str = NULL;
	while (format[++i])
	{
		meta[1] = 0;
		if (format[i] == '%')
		{
			if ((meta[2] = findflag(&str, (char*)&format[i + 1])))
				metavalues(meta, args, str);
			i += meta[2];
		}
		if (format[i] && meta[1] == 0)
			meta[0] += ft_putchar_count(format[i]);
	}
	va_end(args);
	ddelete(&str);
	return (meta[0]);
}
