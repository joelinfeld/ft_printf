#include "ft_printf.h"

void	toprint(t_flag flag)
{
	int i;
	if (flag.space && !flag.plus)
		ft_putchar(' ');
	if (flag.plus && flag.str[0] != '-')
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
	ft_putstr(flag.str);
	if (flag.minus)
	{
		i = -1;
		while(++i < flag.minus)
			ft_putchar(' ');
	}
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

	i = -1;
	while (str[++i])
	{
		if (str[i] == '+')
			flag->plus = 1;
		if (str[i] == '-')
			flag->minus = ft_atoi(&str[i]);
		if (str[i] == '#')
			flag->octothorpe = ft_atoi(&str[i]);
		if (str[i] == '0')
			flag->zero = ft_atoi(&str[i]);
		if (str[i] == ' ')
			flag->space = 1;
	}
}

void	getformat(char **str, t_flag *flag)
{
	int		i;
	char	*flagstr;

	i = -1;
	while (*str[++i])
	{
		if (*str[i] == 'l' || *str[i] == 'h' || *str[i] == 'j' || *str[i] == 'z')
		{
			break ;
		}
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
	
	flag.mod, flag.octothorpe, flag.zero, flag.minus, flag.plus, flag.space = 0;
	len = ft_strlen(str);
	flag.c = str[len - 1];
	str[len - 1] = '\0';
	getformat(&str, &flag);
	getmod(str, &flag);
	flag.str = conhub(args, flag.c, flag.mod);
	toprint(flag);
	return (0);
}
int		findflag(char **str, char *format)
{
	int		i;
	char	*cpy;

	i = -1;
	while (format[++i])
	{
		if (ft_strchr("spdiouxXcSDOUxC", format[i]))
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

	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			skip = findflag(&str, (char*)&format[++i]);
			typeselect(args, str);
			i += skip;
		}
		else if (format[i])
			ft_putchar(format[i]);
	}
	va_end(args);
	return (0);
}
