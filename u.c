/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:26:02 by jinfeld           #+#    #+#             */
/*   Updated: 2017/09/12 16:16:11 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*u(va_list args, char c, int mod)
{
	char	*str;

	if (mod == 0 && c != 'U')
		str = ft_itoa_base(va_arg(args, unsigned int), 10, 1);
	if (mod == 1 || c == 'U')
		str = ft_itoa_base(va_arg(args, unsigned long int), 10, 1);
	if (mod == 2)
		str = ft_itoa_base(va_arg(args, unsigned long long int), 10, 1);
	if (mod == 3 && str == NULL)
		str = ft_itoa_base((unsigned short)va_arg(args, unsigned int), 10, 1);
	if (mod == 4)
		str = ft_itoa_base((unsigned char)va_arg(args, unsigned int), 10, 1);
	if (mod == 5)
		str = ft_itoa_base(va_arg(args, uintmax_t), 10, 1);
	if (mod == 6)
		str = ft_itoa_base(va_arg(args, size_t), 10, 1);
	return (str);
}
