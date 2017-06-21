#include "ft_printf.h"

char	*p(va_list args, int mod)
{
	char	*str;

	if (mod == 0)
		str = ft_itoa_base((uintmax_t)va_arg(args, void*), 16, 0);
	else
		str = NULL;
	return (str);
}
