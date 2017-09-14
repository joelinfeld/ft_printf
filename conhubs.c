/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conhubs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 12:18:28 by jinfeld           #+#    #+#             */
/*   Updated: 2017/08/23 17:07:26 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conhub(va_list args, char c, int mod)
{
	if (ft_strchr("Ddi", c))
		return (di(args, c, mod));
	else if (ft_strchr("Oo", c))
		return (o(args, c, mod));
	else if (ft_strchr("Uu", c))
		return (u(args, c, mod));
	else if (c == 'X')
		return (capx(args, mod));
	else if (c == 'x')
		return (x(args, mod));
	else if (c == 's')
		return (s(args, mod));
	else if (c == 'c')
		return (ch(args, mod));
	else if (c == 'p')
		return (p(args, mod));
	else if (c == '%')
		return ("%");
	else
		return (NULL);
}

wchar_t	*wconhub(va_list args, char c, int mod)
{
	if (ft_strchr("Ss", c))
	{
		return (ws(args, c, mod));
	}
	if (ft_strchr("Cc", c))
		return (wc(args, c, mod));
	else
		return (NULL);
}
