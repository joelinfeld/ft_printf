#include "ft_printf.h"

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
