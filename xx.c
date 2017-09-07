/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Xx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 17:00:25 by jinfeld           #+#    #+#             */
/*   Updated: 2017/08/23 19:22:01 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*x(va_list args, int mod)
{
	char	*str;

	if (mod == 0)
		str = ft_itoa_base(va_arg(args, unsigned int), 16, 0);
	if (mod == 1)
		str = ft_itoa_base(va_arg(args, unsigned long), 16, 0);
	if (mod == 2)
		str = ft_itoa_base(va_arg(args, unsigned long long), 16, 0);
	if (mod == 3)
		str = ft_itoa_base((unsigned short)va_arg(args, unsigned int), 16, 0);
	if (mod == 4)
		str = ft_itoa_base((unsigned char)va_arg(args, unsigned int), 16, 0);
	if (mod == 5)
		str = ft_itoa_base(va_arg(args, uintmax_t), 16, 0);
	if (mod == 6)
		str = ft_itoa_base(va_arg(args, size_t), 16, 0);
	return (str);
}

char	*capx(va_list args, int mod)
{
	char	*str;

	if (mod == 0)
		str = ft_itoa_base(va_arg(args, unsigned int), 16, 1);
	if (mod == 1)
		str = ft_itoa_base(va_arg(args, unsigned long), 16, 1);
	if (mod == 2)
		str = ft_itoa_base(va_arg(args, unsigned long long), 16, 1);
	if (mod == 3)
		str = ft_itoa_base((unsigned short)va_arg(args, unsigned int), 16, 1);
	if (mod == 4)
		str = ft_itoa_base((unsigned char)va_arg(args, unsigned int), 16, 1);
	if (mod == 5)
		str = ft_itoa_base(va_arg(args, uintmax_t), 16, 1);
	if (mod == 6)
		str = ft_itoa_base(va_arg(args, size_t), 16, 1);
	return (str);
}
