#include "ft_printf.h"
#include <stdio.h>

int		leftpad(t_flag flag, int *len)
{
	int	chars;
	
	chars = 0;
	if (flag.plus && !flag.isneg  && (flag.c == 'd' || flag.c == 'D' || flag.c == 'i'))
		*len += 1;
	if (flag.space && *len >= flag.marg && !flag.plus && ft_atoi(flag.str) >= 0 && !(flag.c == 'c' && ft_atoi(flag.str) == 0) && !flag.isneg)
		chars += ft_putchar_count(' ');
	if (flag.marg)
		chars += printmarg(flag, *len);
	if (flag.octothorpe == 1 && ft_atoi(flag.str) != 0)
		printocto(flag);
	if (flag.c == 'p')
		printocto(flag);
	if (flag.plus && !flag.isneg && (flag.c == 'd' || flag.c == 'D' || flag.c == 'i'))
		chars += ft_putchar_count('+');
	if (flag.isneg)
		ft_putchar('-');
	if (flag.zero && !flag.minus)
		chars += printzero(flag, *len);
	return (chars);
}

int		rightpad(t_flag flag, int len)
{
	int	chars;

	chars = 0;
	if (flag.minus)
		chars += printminus(flag, len);
	return (chars);
}

int		handleprecision(t_flag *flag, int len)
{
	int	i;
	char *str;
	char *str2;

	i = 0;
	if (flag->precision && flag->c == 's' && flag->str != NULL)
	{
		if (flag->precision < len)
		{
			str = ft_strnew(flag->precision);
			str = ft_strncpy(str, flag->str, flag->precision);
			flag->str = str;
			flag->str[flag->precision] = '\0';
			len = ft_strlen(flag->str);
		}		
	}
	if (flag->precision > len && flag->c != 's' && flag->c != 'c' && flag->str != NULL)
	{
		i = -1;
		str = ft_strnew(flag->precision - len);
		while (++i < flag->precision - len)
			str[i] = '0';
		str2 = ft_strjoin(str, flag->str);
		flag->str = str2;
		len = ft_strlen(flag->str);
	}
	if (flag->precision < len && flag->c != 's' && flag->c != 'c' && flag->str != NULL)
	{
		if (flag->str[0] == '0')
		{
			flag->str[0] = '\0';
			len = 0;
		}
	}
	return (len);
}

int		printlen(t_flag *flag)
{
	int	len;
	
	if (flag->str != NULL)
		len = ft_strlen(flag->str);
	else
		len = 0;
	if (flag->str != NULL)
	{
		if ((flag->str[0] < 32 || flag->str[0] == 127) && flag->c == 'c')
			len = 1;
		if (flag->precision != -10000)
			len = handleprecision(flag, len);
	}
	if (flag->str != NULL && flag->octothorpe && ft_atoi(flag->str) != 0)
	{
		if (flag->c == 'x' || flag->c == 'X')
			len += 2;
		if (flag->c == 'o')
			len += 1;
	}
	if (flag->c == 'p')
		len += 2;
	if (flag->isneg)
		len++;
	return (len);
}

int		wprintlen(t_flag *flag)
{
	int len;
	int	i;

	i = -1;
	len = 0;
	if (flag->wstr != NULL)
		while (flag->wstr[++i])
	len = i;
	return (len);
}

void	ft_wputstr(wchar_t  *str)
{
	int	i;
	
	i = -1;
	while (str[++i])
		write(1, &str[i], 4);
}

void	ft_wputchar(wchar_t c)
{
	write(1, &c, 4);
}

int		demprintz(t_flag flag)
{
	int len;
	int chars;

	chars = 0;
	if (flag.str != NULL && flag.str[0] == '%')
	{
		ft_putstr(flag.str);
		return (1);
	}
	if (flag.wide)
		len = wprintlen(&flag);
	else
		len = printlen(&flag);
	chars += len;
	chars += leftpad(flag, &len);
	if (flag.wide)
	{
		if (flag.c == 'c')
			ft_wputchar(*flag.wstr);
		else
			ft_wputstr(flag.wstr);
	}
	else if(flag.str != NULL)
	{
		if (flag.c == 'c')
			ft_putchar(*flag.str);
		else
			ft_putstr(flag.str);
	}
	else 
	{
		ft_putstr("(null)");
		chars += 6;
	}
	chars += rightpad(flag, len);
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
		return (x(args, mod));
	else if (c == 's')
		return(s(args, mod));
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
		return (ws(args, c, mod));
	if (ft_strchr("Cc", c))
		return (wc(args, c, mod));
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

int		setflagvalue(int *n, int value, int cur)
{
	*n = value;
	return(cur);
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

void	flagparse(t_flag *flag, char *str)
{
	int	i;
	int cur;

	cur = 0;
	i = -1;
	if (str != NULL)
	{
		while (str[++i])
		{
			if (str[i] > '0' && str[i] <= '9' && cur == 0)
				cur = setflagvalue(&(flag->marg), ft_atoi(&str[i]), 1);
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
}

int		typeselect(va_list args, char *str)
{
	t_flag	flag;
	int		len;	
	
	flagnew(&flag);
	len = ft_strlen(str);
	flag.c = str[len - 1];
	str[len - 1] = '\0';
	getformat(&str, &flag);
	getmod(&flag, str);
	if (flag.c == 'S' || flag.c == 'C' || (flag.c == 's' && flag.mod == 1) || (flag.c == 'c' && flag.mod == 1))
	{
		flag.wstr = wconhub(args, flag.c, flag.mod);
		flag.wide = 1;
	}
	else
		flag.str = conhub(args, flag.c, flag.mod);
	if (flag.c == 'd' || flag.c == 'i' || flag.c == 'D' || flag.c == 'I')
	{
		if (flag.str && flag.str[0] == '-')
		{
			++flag.str;
			flag.isneg = 1;
		}
	}
	return(demprintz(flag));
}

int		findflag(char **str, char *format)
{
	int		i;
	char	*cpy;
	int		find = 0;
	i = 0;
	while (format[++i])
	{
		if (ft_strchr("SspdiouxXcDOUxC%", format[i]))
		{
			cpy = ft_strdup(format);
			cpy[i + 1] = '\0';
			*str = ft_strdup(cpy);
			ft_strdel(&cpy);
			find = 1;
			break ;
		}
	}
	if (!find)
		i = 0;
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
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			skip = findflag(&str, (char*)&format[i]);
			if (skip)
				chars += typeselect(args, str);
			i += skip;
		}
		else if (format[i])
			chars += ft_putchar_count(format[i]);
		i++;
	}
	va_end(args);
	return (chars);
}

/*
int		main(void)
{
	int	n;
	n = 28;
	ft_printf("%cHello World\n", 0);
	return (0);
}
*/
