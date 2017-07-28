#include "ft_printf.h"

int		ft_putchar_count(char c)
{
	write(1, &c, 1);
	return (1);
}

void	printocto(t_flag flag)
{
	if (flag.c == 'x' || flag.c == 'p')
		ft_putstr("0x");
	if (flag.c == 'X')
		ft_putstr("0X");
	if (flag.c == 'o')
		ft_putchar('0');
}

int		printzero(t_flag flag, int len)
{
	int i;
	int chars;

	i = 0;
	chars = 0;
	if (flag.precision != -10000)
	{
		while(++i <= flag.zero - len)
			chars += ft_putchar_count(' ');
	}
	else
	{
		while(++i <= flag.zero - len)
			chars += ft_putchar_count('0');
	}
	return (chars);
}

int		printmarg(t_flag flag, int len)
{
	int i;
	int chars;

	i = 0;
	chars = 0;
	while(++i <= flag.marg - len)
			chars += ft_putchar_count(' ');
	return (chars);
}

int		printminus(t_flag flag, int len)
{
	int	i;
	int	chars;

	i = 0;
	chars = 0;
	while (++i <= flag.minus - len)
		chars += ft_putchar_count(' ');
	return (chars);
}

