/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:11:25 by jinfeld           #+#    #+#             */
/*   Updated: 2017/09/12 13:25:52 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int		setmarg(t_flag *flag, char *str, int i, int ast)
{
	int	cur;

	if (ast)
	{
		cur = setflagvalue(&(flag->marg), ast, 1);
		ast = 0;
	}
	else
		cur = setflagvalue(&(flag->marg), ft_atoi(&str[i]), 1);
	return (cur);
}

void	handleast(t_flag *flag, char *str, int *ast, va_list args)
{
	int	i;

	i = -1;
	*ast = va_arg(args, int);
	while (str[++i])
	{
		if (str[i] == '*')
		{
			if (i > 0 && str[i - 1] == '-')
			{
				flag->minus = *ast;
				*ast = 0;
			}
			break ;
		}
	}
}

void	flagparsehelp(t_flag *flag, char *str, va_list args, int ast)
{
	int	i;
	int	cur;

	cur = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '*')
			handleast(flag, str, &ast, args);
		if (((str[i] > '0' && str[i] <= '9') || str[i] == '*') && cur == 0)
			cur = setmarg(flag, str, i, ast);
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

void	flagparse(t_flag *flag, char *str, va_list args)
{
	int ast;

	ast = 0;
	if (str != NULL)
		flagparsehelp(flag, str, args, ast);
}
