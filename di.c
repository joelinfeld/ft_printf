/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 17:06:10 by jinfeld           #+#    #+#             */
/*   Updated: 2017/09/12 16:19:08 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*di(va_list args, char c, int mod)
{
	char	*str;
	intmax_t n;
	
	n = va_arg(args, intmax_t);	
	if (mod == 0 && c != 'D')
		str = ft_itoa((int)n);
	if (mod == 1 || c == 'D')
		str = ft_itoa((long int)n);
	if (mod == 2)
		str = ft_itoa((long long int)n);
	if (mod == 3)
		str = ft_itoa((short int)n);
	if (mod == 4)
		str = ft_itoa((signed char)n);
	if (mod == 5)
		str = ft_itoa(n);
	if (mod == 6)
		str = ft_itoa((ssize_t)n);
	return (str);
}
