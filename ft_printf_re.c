#include "ft_printf.h"

void	getformat(char **str, t_flag flag)
{
	int		i;

	i = -1;
	while (*str[++i])
	{
		if (*str[i] == 'l' || *str[i] == 'h' || *str[i] == 'j' || *str[i] == 'z')
		{
			*str += i;
			break ;
		}
	}
}

int		typeselect(va_list args, char *str)
{
	t_flag	flag;
	int		len;

	len = ft_strlen(str);
	flag.c = str[len - 1];
	str[len - 1] = '\0';
	getformat(&str, flag);
	
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
	return (chars);
}
