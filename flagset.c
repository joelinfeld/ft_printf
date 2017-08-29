/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:11:25 by jinfeld           #+#    #+#             */
/*   Updated: 2017/08/29 08:25:22 by jinfeld          ###   ########.fr       */
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
}

int		setflagvalue(int *n, int value, int cur)
{
	*n = value;
	return (cur);
}

int		setflagminus(t_flag *flag, char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '.')
			break ;
		if (str[i] >= '0' && str[i] <= '9')
		{
			flag->minus = ft_atoi(&str[i]);
			break ;
		}
	}
	return (1);
}

void	flagparse(t_flag *flag, char *str, va_list args)
{
	int	i;
	int cur;
	int ast;
	
	ast = 0;
	cur = 0;
	i = -1;
	if (str != NULL)
	{
		while (str[++i])
		{
			if (str[i] == '*')
			{
				ast = va_arg(args, int);
				if (i > 0 && str[i - 1] == '-')
				{
					flag->minus = ast;
					ast = 0;
				}
			}
			if (((str[i] > '0' && str[i] <= '9') || str[i] == '*')  && cur == 0)
			{
				if (ast)
				{
					cur = setflagvalue(&(flag->marg), ast, 1);
					ast = 0;
				}
				else
					cur = setflagvalue(&(flag->marg), ft_atoi(&str[i]), 1);
			}
			if (str[i] == '+')
				flag->plus = 1;
			if (str[i] == '-')
				cur = setflagminus(flag, &str[i]);
			if (str[i] == '#')
				flag->octothorpe = 1;
			if (str[i] == '0' && cur == 0)
				cur = setflagvalue(&(flag->zero), ft_atoi(&str[i + 1]), 1);
			if (str[i] == ' ' && str[i + 1] != ' ')
				flag->space = 1;
			if (str[i] == '.')
				cur = setflagvalue(&(flag->precision), ft_atoi(&str[i + 1]), 1);
		}
	}
}
