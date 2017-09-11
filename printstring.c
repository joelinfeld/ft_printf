/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:41:13 by jinfeld           #+#    #+#             */
/*   Updated: 2017/08/29 08:29:34 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	ft_wputstr(wchar_t *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_wputchar(str[i]);
}

void	ft_wputchar(wchar_t c)
{
	unsigned int	n;

	n = (unsigned int)c;
	if (n < (MB_CUR_MAX == 1 ? 255 : 127))
		ft_putchar(n);
	else if (n <= 2047)
	{
		ft_putchar(192 | (n >> 6 & 63));
		ft_putchar(128 | (n & 63));
	}
	else if (n <= 65535)
	{
		ft_putchar(224 | (n >> 12 & 63));
		ft_putchar(128 | (n >> 6 & 63));
		ft_putchar(128 | (n & 63));
	}
	else
	{
		ft_putchar(240 | (n >> 18 & 63));
		ft_putchar(224 | (n >> 12 & 63));
		ft_putchar(224 | (n >> 6 & 63));
		ft_putchar(128 | (n & 63));
	}
}

int		putflagstr(t_flag flag)
{
	if (flag.wide)
	{
		if (flag.c == 'c' || flag.c == 'C')
			ft_wputchar(*flag.wstr);
		else
			ft_wputstr(flag.wstr);
		return (1);
	}
	else if(flag.str != NULL)
	{
		if (flag.c == 'c')
			ft_putchar(*flag.str);
		else
			ft_putstr(flag.str);
		return (1);
	}
	return (0);
}

int		demprintz(t_flag flag)
{
	int len;
	int chars;

	chars = 0;
	if (flag.wide)
		len = wprintlen(&flag);
	else
		len = printlen(&flag);
	chars += len;
	chars += leftpad(flag, &len);
	if (!putflagstr(flag))
	{
		ft_putstr("(null)");
		chars += 6;
	}
	chars += rightpad(flag, len);
	return (chars);
}
