/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 14:00:55 by jinfeld           #+#    #+#             */
/*   Updated: 2017/08/22 15:34:00 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t		*wc(va_list args, char c, int mod)
{
	wchar_t		*str;

	str = (wchar_t *)malloc(sizeof(wchar_t) * 1);
	if ((mod = 1 && c == 'c') || (mod = 0 && c == 'C'))
		*str = va_arg(args, wchar_t);
	return (str);	
}
