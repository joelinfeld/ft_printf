/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:43:38 by jinfeld           #+#    #+#             */
/*   Updated: 2017/09/12 13:31:02 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printlen(t_flag *flag)
{
	int	len;

	if (flag->str != NULL)
		len = ft_strlen(flag->str);
	else
		len = 0;
	if (flag->str != NULL)
	{
		if ((flag->str[0] < 32 || flag->str[0] == 127) && flag->c == 'c')
			len = 1;
		if (flag->precision != -10000)
			len = handleprecision(flag, len);
	}
	if (flag->str != NULL && flag->octothorpe)
	{
		if ((flag->c == 'x' || flag->c == 'X') && ft_atoi(flag->str) != 0)
			len += 2;
		if (flag->c == 'o')
			len += 1;
	}
	if (flag->c == 'p')
		len += 2;
	if (flag->isneg)
		len++;
	return (len);
}

int		wprintlen(t_flag *flag)
{
	int	len;
	int	i;

	i = -1;
	len = 0;
	if (flag->wstr != NULL)
		while (flag->wstr[++i])
		{
		}
	len = i;
	return (len);
}
