/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <jinfeld@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:23:29 by jinfeld           #+#    #+#             */
/*   Updated: 2017/06/21 18:51:05 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	getformat(char **str)
{
	char	*ret;
	int		i;

	ret = ft_strdup(*str);
	i = -1;
	if (*str == '+' || *str == '-' || *str == '#' || *str == '0' || *str == ' ')
	{
		while (*str[++i])
		{
			if (*str[i] == 'l' || *str[i] == 'h' || *str[i] == 'j' || *str[i] == 'z')
			{
				*str += i;
				break ;
			}
		}
	}
	ret[i] = '\0'; 
	return (ret);
}

void	toprint(char *str, char c, int mod, char *format)
{
	int i;
	if (flag.space && !flag.plus)
		ft_putchar(' ');
	if (flag.plus && str[0] != '-')
		ft_putchar('+');
	if (flag.octothorpe = 1)
	{
		if (flag.c == 'x')
			ft_putstr("0x");
		if (flag.c == 'X')
			ft_putstr("0X");
	}
	if (flag.zero && !flag.minus)
	{
		i = -1;
		while(++i < flag.zero)
			ft_putchar('0');
	}
	ft_putstr(str);
	if (flag.minus)
	{
		i = -1;
		while(++i < flag.minus)
			ft_putchar(' ');
	}
}

//finds the entire conversion/print argument and returns an int to skip over it in the input str "format"
char	*conhub(va_list args, char c, int mod)
{
	if (ft_strchr("Ddi", c))
		return (di(args, c, mod));
	else if (ft_strchr("Oo", c))
		return (o(args, c, mod));
	else if (ft_strchr("Uu", c))
		return (u(args, c, mod));
	else if (c == 'X')
		return (X(args, mod));
	else if (c == 'x')
		return (x(args, mod));
	else if (ft_strchr("Ss", c))
		return(s(args, c, mod));
	else if (ft_strchr("Cc", c))
		return(ch(args, c, mod));
	else if(c == 'p')
		return(p(args, mod));
	else
		return (NULL);
}

//sorts through flag and sends it to sub direction functions
int		typeselect(va_list args, char *str)
{	
	int		len;
	char	c;
	int		mod;
	char	*cp;
	t_flag	flag;

	cp = ft_strdup(str)
	len = ft_strlen(str);	
	flag.c = str[len - 1];
	str[len - 1] = '\0';
	ft_strdel(&flag.str);
	cp = ft_strdup(str);
	ft_strdel(&str);
	getformat(cp, flag); //doesn't work yet;
	flag.mod = getmod(flag.str);
	ft_strdel(flag.str);
	flag.str = conhub(args, flag);
	toprint(flag);
	return((int)ft_strlen(str));
}

int		flagset(char *str, char *format)
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
			*str = ft_strdup(cpy);
			break ;
		}
	}
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	char		*str;
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
			skip = flagset(&str, (char*)&format[++i]);
			chars += typeselect(args, str);
			i += skip;
			chars++;
		}
		else if (format[i])
			ft_putchar(format[i]);
	}
	va_end(args);
	return (chars);
}

/*
int main(void)
{
	int a = 5000;
	char *str = "holyballs";
	char c = 'z';
//	printf("first test %d", a);
	ft_printf("first test %lld\n dingles\n", a);
	ft_printf("secondtest %llo\n dingles\n", a);
	ft_printf("%s\n", str);
	ft_printf("chartime: %c\n", c);
	return (0);
}
*/

