#include "ft_printf.h"
#include <stdio.h>

char				*ft_itoa_base(uintmax_t n, int base, int caseflag);
void	numbers(t_flag flag)
{
	printf("marg: %d\nmod: %d\nocto: %d\nzero: %d\nminus: %d\nplus: %d\nspace: %d\n",
	flag.marg, flag.mod, flag.octothorpe, flag.zero, flag.minus, flag.plus, flag.space);
}
int		toprint(t_flag flag)
{
	int i;
	int chars;
	int	len;

	len = ft_strlen(flag.str);
	chars = len;
	if (flag.octothorpe == 1 && flag.str[0] != '0')
		len += 2;
	//test funcs
	//numbers(flag);
	//printf("len: %d\n", len);
	if (flag.c == '%')
	{
		ft_putchar('%');
		return (chars);
	}
	if (flag.space && !flag.plus)
	{
		ft_putchar(' ');
		chars += 1;
	}
	if (flag.plus && flag.str[0] != '-')
	{
		ft_putchar('+');
		chars += 1;
	}
	if (flag.marg)
	{
		i = 0;
		while(++i <= flag.marg - len)
		{
			ft_putchar(' ');
			chars += 1;
		}
	}
	if (flag.octothorpe == 1 && flag.str[0] != '0')
	{
		if (flag.c == 'x')
			ft_putstr("0x");
		if (flag.c == 'X')
			ft_putstr("0X");
		chars += 2;
	}
	if (flag.zero && !flag.minus)
	{
		i = 0;
		while(++i <= flag.zero - len)
		{
			ft_putchar('0');
			chars += 1;
		}
	}
	ft_putstr(flag.str);
	if (flag.minus)
	{
		i = 0;
		while(++i <= flag.minus - len)
		{
			ft_putchar(' ');
			chars += 1;
		}

	}
	return (chars);
}

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
	{
		return (x(args, mod));
	}
	else if (ft_strchr("Ss", c))
		return(s(args, c, mod));
	else if (ft_strchr("Cc", c))
		return (ch(args, c, mod));
	else if (c == 'p')
		return (p(args, mod));
	else if (c == '%')
		return ("%");
	else
		return (NULL);
}

void	getmod(t_flag *flag, char *str)
{
	if (!ft_strlen(str))
		flag->mod = 0;
	if	(ft_strequ(str, "l"))
		flag->mod = 1;
	if	(ft_strequ(str, "ll"))
		flag->mod = 2;
	if	(ft_strequ(str, "h"))
		flag->mod = 3;
	if	(ft_strequ(str, "hh"))
		flag->mod = 4;
	if	(ft_strequ(str, "j"))
		flag->mod = 5;	
	if	(ft_strequ(str, "z"))
		flag->mod = 6;
}

void	flagparse(t_flag *flag, char *str)
{
	int	i;
	int cur;
	
	cur = 0;
	i = -1;
	//test str
	//printf("string: %s\n", str);
	while (str[++i])
	{
		if (str[i] > '0' && str[i] <= '9' && cur == 0)
		{
			flag->marg = ft_atoi(&str[i]);
			cur = 1;
		}
		if (str[i] == '+')
		{
			flag->plus = 1;
			cur = 1;
		}
		if (str[i] == '-')
		{
			flag->minus = ft_atoi(&str[i + 1]);
			cur = 1;
		}
		if (str[i] == '#')
		{
			flag->octothorpe = 1;
		}
		if (str[i] == '0' && cur == 0)
		{
			flag->zero = ft_atoi(&str[i + 1]);
			cur = 1;
		}
		if (str[i] == ' ' && str[i + 1] != ' ')
		{
			flag->space = 1;
			cur = 1;
		}
	}
}

void	getformat(char **str, t_flag *flag)
{
	int		i;
	char	*flagstr;

	i = -1;
	while (str[0][++i])
	{
		if (str[0][i] == 'l' || str[0][i] == 'h' || str[0][i] == 'j' || str[0][i] == 'z')
			break ;
	}
	flagstr = ft_strdup(*str);
	flagstr[i] = '\0';
	*str += i;
	flagparse(flag, flagstr);
}

int		typeselect(va_list args, char *str)
{
	t_flag	flag;
	int		len;	
	
	flag.mod = 0;
	flag.octothorpe = 0;
	flag.zero = 0;
	flag.minus = 0;
	flag.plus = 0;
	flag.space = 0;
	flag.marg = 0;
	len = ft_strlen(str);
	flag.c = str[len - 1];
	str[len - 1] = '\0';
	getformat(&str, &flag);
	getmod(&flag, str);
	flag.str = conhub(args, flag.c, flag.mod);
	return(toprint(flag));
}
int		findflag(char **str, char *format)
{
	int		i;
	char	*cpy;

	i = -1;
	while (format[++i])
	{
		if (ft_strchr("spdiouxXcSDOUxC%", format[i]))
		{
			cpy = ft_strdup(format);
			cpy[i + 1] = '\0';
			*str = ft_strdup(cpy);
			ft_strdel(&cpy);
			break ;
		}
	}
	return (i);
}
int		ft_printf(const char *format, ...)
{
	va_list	args;
	char	*str;
	int		i;
	int		skip;
	int		chars;
	
	va_start(args, format);
	chars = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			skip = findflag(&str, (char*)&format[++i]);
			chars += typeselect(args, str);
			i += skip;
		}
		else if (format[i])
		{
			ft_putchar(format[i]);
			chars += 1;
		}
	}
	va_end(args);
	return (chars);
}

/*
int		main(void)
{
	ft_printf("%#x", 42);
	return (0);
}
*/
