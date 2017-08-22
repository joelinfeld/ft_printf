/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 14:57:06 by jinfeld           #+#    #+#             */
/*   Updated: 2017/08/22 15:13:15 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ch(va_list args, int mod)

{
	char	*str;
	
	str = ft_strnew(1);
	if (mod == 0)
		*str = (char)va_arg(args, unsigned int);
	return (str);
}
