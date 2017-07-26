#include "ft_printf.h"
#include <stdio.h>

char				*ft_itoa_base(uintmax_t n, int base, int caseflag);
void	numbers(t_flag flag)
{
	printf("marg: %d\nmod: %d\nocto: %d\nzero: %d\nminus: %d\nplus: %d\nspace: %d\n",
	flag.marg, flag.mod, flag.octothorpe, flag.zero, flag.minus, flag.plus, flag.space);
}

int		leftpad(t_flag flag, int len)
{
	int i;
	int	chars;
	
	chars = 0;
	i = 0;
	if (flag.space && !flag.marg && !flag.plus && ft_atoi(flag.str) >= 0 && !(flag.c == 'c' && ft_atoi(flag.str) == 0))
	{
		ft_putchar(' ');
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
	if (flag.octothorpe == 1 && ft_atoi(flag.str) != 0)
	{
		if (flag.c == 'x')
			ft_putstr("0x");
		if (flag.c == 'X')
			ft_putstr("0X");
		if (flag.c == 'o')
			ft_putchar('0');
	}
	if (flag.plus && flag.str[0] != '-' && (flag.c == 'd' || flag.c == 'D' || flag.c == 'i'))
	{
		ft_putchar('+');
		chars += 1;
		len += 1;
	}
	if (flag.str[0] == '-')
	{
		ft_putchar('-');
	}
	if (flag.zero && !flag.minus)
	{
		i = 0;
		if (flag.precision != -10000)
		{
			while(++i <= flag.zero -len)
			{
				ft_putchar(' ');
				chars += 1;
			}
		}
		else
		{
			while(++i <= flag.zero - len)
			{
				ft_putchar('0');
				chars += 1;
			}
		}
	}
	return (chars);
}

int		rightpad(t_flag flag, int len)
{
	int	i;
	int	chars;

	chars = 0;
	i = 0;
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

int		printlen(t_flag *flag)
{
	int	len;
	char *str;
	char *str2;
	int	i;
	//int	j;

	len = ft_strlen(flag->str);
	if (flag->str[0] == 0 && flag->c == 'c')
		len = 1;
	//printf("this is the string right before checking precision: %s\n", flag->str);
	if (flag->precision != -10000)
	{
		if (flag->precision && flag->c == 's')
		{
			if (flag->precision < len)
			{
				flag->str[flag->precision] = '\0';
				len = flag->precision;
			}
		}
		else if (flag->precision > len && flag->c != 's' && flag->c != 'c')
		{
			i = -1;
			str = ft_strnew(flag->precision);
			while (++i < flag->precision - len)
				str[i] = '0';
			/*
			j = 0;
			i -= 1;
			while (++i < flag->precision);
				str[i] = (flag->str)[j++];
			str[i] = '\0';
			*/
			
			len = flag->precision;
			//printf("this is flagstr: %s\n", flag->str);
			//printf("this is the string post transfer: %s\n", str);
			str2 = ft_strjoin(str, flag->str);
			flag->str = str2;
		}
	}
	//printf("this is the string right before printing: %s\n", flag->str);
	if (flag->octothorpe && ft_atoi(flag->str) != 0)
	{
		if (flag->c == 'x' || flag->c == 'X')
			len += 2;
		if (flag->c == 'o')
			len += 1;
	}
	return (len);
}
int		demprintz(t_flag flag)
{
	int len;
	int chars;

	chars = 0;
	if (flag.str[0] == '%')
	{
		ft_putstr(flag.str);
		return (1);
	}
	len = printlen(&flag);
	chars += leftpad(flag, len);
	if (flag.str[0] == '-')
		ft_putstr(&flag.str[1]);
	else
		ft_putstr(flag.str);
	chars += rightpad(flag, len);
	chars += len;
	return (chars);
}

/*
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
	if (flag.space && !flag.plus && ft_atoi(flag.str) >= 0 && flag.str)
	{
		ft_putchar(' ');
		chars += 1;
	}
	
	if (flag.precision >= 0  && flag.str && ft_strlen(flag.str) > 0)
	{
		if (flag.c == 's')
		{
			flag.str[flag.precision] = '\0';
			chars -= (len - flag.precision);
			len -= (len - flag.precision);
		}
		else
		{
			if (flag.precision > len)
			{
				i = 0;
				while (++i <= flag.precision - len)
				{
					ft_putchar('0');
					++chars;
				}
			}
		}
	}
	ft_putstr(flag.str);
	if (flag.str == NULL)
		chars = 0;
	return (chars);
}
*/

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
	int hold;

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
		}
		if (str[i] == '-')
		{
			hold = i;
			while (str[++i])
			{
				if (str[i] >= '0' && str[i] <= '9')
				{
					flag->minus = ft_atoi(&str[i]);
					break ;
				}
			}
			cur = 1;
			i = hold;
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
		}
		if (str[i] == '.')
		{
			flag->precision = ft_atoi(&str[i + 1]);
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
	//temporary precision set, will probably need a boolean
	flag.precision = -10000;
	len = ft_strlen(str);
	flag.c = str[len - 1];
	str[len - 1] = '\0';
	getformat(&str, &flag);
	getmod(&flag, str);
	flag.str = conhub(args, flag.c, flag.mod);
	return(demprintz(flag));
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
	ft_printf("%-5.10o\n", 2500);
	return (0);
}
*/
