/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 17:08:47 by jinfeld           #+#    #+#             */
/*   Updated: 2017/08/23 17:08:50 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*p(va_list args, int mod)
{
	char	*str;

	if (mod == 0)
		str = ft_itoa_base((uintmax_t)va_arg(args, void*), 16, 0);
	else
		str = NULL;
	return (str);
}
