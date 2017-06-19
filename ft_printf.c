/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <jinfeld@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:23:29 by jinfeld           #+#    #+#             */
/*   Updated: 2017/06/19 16:48:47 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int		ft_printf(const char *format,...);

/*
int		pstr(char *str)
{
	ft_putstr(str);
	return ((int)ft_strlen(str));
}

int		pint(int num)
{
	char	*str;
	
	str = ft_itoa(num);
	ft_putstr(str);
	return ((int)ft_strlen(str));
}
*/

int		getmod(char *str)
{
	int	mod;

	if (ft_strequ(str, "ll"))
		mod = 2;
	else if (ft_strchr(str, 'l'))
		mod = 1;
	else if (ft_strequ(str, "hh"))
		mod = 4;
	else if (ft_strchr(str, 'h'))
		mod = 3;
	else if (ft_strchr(str, 'j'))
		mod = 5;
	else if (ft_strchr(str, 'z'))
		mod = 6;
	else
		mod = 0;	
	return (mod);
}

void	toprint(char *str)
{
	ft_putstr(str);
}

char	*di(va_list args, char c, int mod)
{
	char	*str;

	if (mod == 0 && c != 'D')
		str = ft_itoa(va_arg(args, int));
	if (mod == 1 || c == 'D')
		str = ft_itoa(va_arg(args, long));
	if (mod == 2)
		str = ft_itoa(va_arg(args, long long));
	if (mod == 3) 
		str = ft_itoa((short)va_arg(args, int));
	if (mod == 4)
		str = ft_itoa((signed char)va_arg(args, int));
	if (mod == 5)
		str = ft_itoa(va_arg(args, intmax_t));
	return (str);
}


char	*o(va_list args, char c, int mod)
{
	char	*str;
	if (mod == 0 && c != 'O')
		str = ft_itoa_base(va_arg(args, unsigned int), 8, 1);
	if (mod == 1 || c == 'O')
		str = ft_itoa_base(va_arg(args, unsigned long), 8, 1);
	if (mod == 2)
		str = ft_itoa_base(va_arg(args, unsigned long long), 8, 1);
	if (mod == 3)
		str = ft_itoa_base((unsigned short)va_arg(args, unsigned int), 8, 1);
	if (mod == 4)
		str = ft_itoa_base((unsigned char)va_arg(args, unsigned int), 8, 1);
	if (mod == 5)
		str = ft_itoa_base(va_arg(args, uintmax_t), 8, 1);
	return (str);
}


//finds the entire conversion/print argument and returns an int to skip over it in the input str "format"
char	*conhub(va_list args, char c, int mod)
{
	if (ft_strchr("Ddi", c))
		return (di(args, c, mod));
	else if (c == 'o')
		return (o(args, c, mod));
//	else if (c == 'u')
//		return (u(args, c, mod));
//	else if (strchr("Xx", c))
//		return (Xx(args, c, mod));
	else
		return (NULL);
}

//sorts through flag and sends it to sub direction functions
int		typeselect(va_list args, char *flag)
{	
	int		len;
	char	c;
	int		mod;
	char	*format;
	char	*str;

	len = ft_strlen(flag);	
	c = flag[len - 1];
	flag[len - 1] = '\0';
	mod = getmod(flag);
	//format = getformat(flag); //doesn't work yet;
	str = conhub(args, c, mod);
	toprint(str);
	return((int)ft_strlen(str));
}

int		flagset(char **flag, char *format)
{
	int		i;
	char	*cpy;

	i = -1;
	while (format[++i])
	{
		if (ft_strchr("spdiouxXcSDOUxC", format[i]))
		{
			cpy = ft_strdup(format);
			cpy[i + 1]= '\0';
			*flag = ft_strdup(cpy);
			break ;
		}
	}
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	char		*flag;
	int			skip;
	int			chars;
	int			i;
	
	va_start(args, format);
	i = -1;
	chars = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			skip = flagset(&flag, (char*)&format[i]);
			chars += typeselect(args, flag);
			i += skip;
			chars++;
		}
		else if (format[i])
			ft_putchar(format[i]);
	}
	va_end(args);
	return (chars);
}

int main(void)
{
	int a = 5000;
//	printf("first test %d", a);
	ft_printf("first test %d\n dingles\n", a);
	ft_printf("secondtest %o\n dingles\n", a);
	return (0);
}
