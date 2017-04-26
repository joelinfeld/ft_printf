/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <jinfeld@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:23:29 by jinfeld           #+#    #+#             */
/*   Updated: 2017/04/25 18:39:21 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int		typeselect(va_list args, char *flag)
{	
	int		len;
	
	len = ft_strlen(flag);
	if (len == 1)
	{
		if (ft_strchr("spdiouxXc", *flag))			
			return (spdiouxXc(args, *flag));	
		else if (ft_strchr("SDOUC", *flag))			
			return (lmod(args, *flag));
	}
	if (len == 2 && *flag++ = 'l')
	{
		if (ft_strchr("sdouXxc", *flag))
			return (lmod(args, *flag));
	}
}

int		spdiouxXc(va_list args, char flag)
{
	if (flag == 's')
		ft_putstr(va_arg(args, char *));
	else if (flag == 'p')
		pvhex(args); 
	else if (flag == 'd' || flag == 'i')
		pint(args);
	else if (flag == 'o')
		poct(args);
	else if (flag == 'u')
		punint(args);
	else if (flag == 'x')
		phexlow(args);
	else if (flag == 'X')
		phexup(args);
	else if (flag == 'c')
		punchr(args);
}

int		lmod(va_list args, char flag)
{
	if (flag == 'S' || 's')
		ft_putstr(va_arg(args, char *));
	if (flag == 'D' || 'd')
		pint(args);
	if (flag == 'O' || 'o')
		poct(args);
	if (flag == 'U' || 'o')
		punint(args);
	if (flag == 'X')
	if (flag == 'x')
	if (flag == 'C' || 'c')
		punchr(args);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	char		*flag;
	int			skip;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			skip = flagset(&flag, format[i]);
			typeselect(args, flag);
			i += skip;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(args, format);
}

void	pstr(va_list args)
{
	ft_putstr(va_arg(args, char*));
}
