#include "ft_printf.h"

char	*s(va_list args, int mod)
{
	char	*str;
	if (mod == 0)
		str = va_arg(args, char*);
	else 
		str = NULL;
	return (str);
}
