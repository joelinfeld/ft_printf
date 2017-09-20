/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagset2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:22:59 by jinfeld           #+#    #+#             */
/*   Updated: 2017/09/19 16:22:23 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flagnew(t_flag *flag)
{
	flag->str = NULL;
	flag->wstr = NULL;
	flag->mod = 0;
	flag->octothorpe = 0;
	flag->zero = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->marg = 0;
	flag->precision = -10000;
	flag->isneg = 0;
	flag->wide = 0;
	flag->len = 0;
	flag->str = NULL;
	flag->wstr = NULL;
	flag->edit = 0;
}

int		setflagvalue(int *n, int value, int cur)
{
	*n = value;
	return (cur);
}

void	ddelete(char **str)
{
	if (*str != NULL)
	{
		ft_strclr(*str);
		ft_strdel(str);
	}
}

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
	ddelete(&flagstr);
}
