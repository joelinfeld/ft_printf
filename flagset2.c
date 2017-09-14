/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagset2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:22:59 by jinfeld           #+#    #+#             */
/*   Updated: 2017/09/12 20:02:11 by jinfeld          ###   ########.fr       */
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
