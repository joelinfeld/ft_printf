/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <jinfeld@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:23:29 by jinfeld           #+#    #+#             */
/*   Updated: 2017/05/16 22:44:44 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pstr(char *str)
{
	ft_putstr(str);
	return ((int)ft_strlen(str));
}

int		pint(int num)
{
	char	*str;
	
	str = ft_itoa(num);
	ft_putstr(str);
	return ((int)ft_strlen(str));
}
//sorts through flag and sends it to sub direction functions
int		typeselect(va_list args, char *flag)
{	
	int		len;
	char	c;
	len = ft_strlen(flag);
	
	c = flag[len - 1];
	flag[len - 1] = '\0';
}
//handles all standard conversions
int		spdiouxXc(va_list args, char flag)
{
	if (flag == 's')
		return(pstr(va_arg(args, char *)));
	else if (flag == 'p')
		return(pvhex(args)); 
	else if (flag == 'd' || flag == 'i')
		return(pint(va_arg(args, int)));
	else if (flag == 'o')
		return(poct(args));
	else if (flag == 'u')
		return(punint(args));
	else if (flag == 'x')
		return(phexlow(args));
	else if (flag == 'X')
		return(phexup(args));
	else if (flag == 'c')
		return(punchr(args));
}

//handles all lmod type commands
int		lmod(va_list args, char flag)
{
	if (flag == 'D' || flag == 'd' || flag == 'i')
		return(pint(args));
	if (flag == 'O' || 'o')
		return(poct(args));
	if (flag == 'U' || 'u')
		return(punint(args));
	if (flag == 'X')
	if (flag == 'x')	
	if (flag == 'S' || 's')
		return(ft_putstr(va_arg(args, char *)));
	if (flag == 'C' || 'c')
		return(punchr(args));
}

int		di(va_list args)
{
	if (d || i)
		pint(va_args(args, int), d);
	if (l)
		pint(va_arg(args, long), l);
	if (ll)
		pint(va_args(args, long long), ll);
	if (h) 
		pint(va_args(args, short), h);
	if (hh)
		pint(va_args(args, signed char), hh);
	if (j)
		pint(va_args(args, intmax_t), j);
}

//finds the entire conversion/print argument and returns an int to skip over it in the input str "format"
int		flagset(char **flag, char *format)
{
	int		i;

	i = -1;
	while (format[++i])
	{
		if (strchr(format[i], "spdiouxXcSDOUxC"))
		{
			format[i + 1]= '\0';
			*flag = ft_strdup(format);
			break ;
		}
	}
	return (i + 1);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	char		*flag;
	int			skip;
	int			chars;
	int			i;
	
	va_start(args, format);
	i = -1;
	chars = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			skip = flagset(&flag, format[i]);
			chars += typeselect(args, flag);
			i += skip;
			chars++;
		}
		else
			ft_putchar(format[i]);
	}
	va_end(args, format);
	return (chars);
}
