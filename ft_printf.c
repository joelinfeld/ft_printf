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
int		getmod(char *str)
{
	int	mod;

	if (strmatch(str, "ll"))
		mod = 2;
	else if (strchr(str, 'l'))
		mod = 1;
	else if (strmatch(str, "hh"))
		mod = 4;
	else if (strchr(str, 'h'))
		mod = 3;
	else if (strchr(str, 'j'))
		mod = 5;
	else if (strchr(str, 'z'))
		mod = 6;
	else
		mod = 0;	
	return (mod);
}
//sorts through flag and sends it to sub direction functions
int		typeselect(va_list args, char *flag)
{	
	int		len;
	char	c;
	int		mod;

	len = ft_strlen(flag);	
	c = flag[len - 1];
	flag[len - 1] = '\0';
	mod = getmod(flag);
}

char	*di(va_list args, char c, int mod)
{
	char	*str;

	if (mod = 0 && c != 'D')
		str = ft_itoa(va_args(args, int));
	if (mod = 1 || c == 'D')
		str = ft_itoa(va_arg(args, long));
	if (mod = 2)
		str = ft_itoa(va_args(args, long long));
	if (mod = 3) 
		str = ft_itoa(va_args(args, short));
	if (mod = 4)
		str = ft_itoa(va_args(args, signed char));
	if (mod = 5)
		str = ft_itoa(va_args(args, intmax_t));
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
