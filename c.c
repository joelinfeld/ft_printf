#include "ft_printf.h"

char	*ch(va_list args, int mod)

{
	char	*str;
	
	str = ft_strnew(1);
	if (mod == 0)
		*str = (char)va_arg(args, unsigned int);
	return (str);
}
