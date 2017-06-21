#include "ft_printf.h"

char	*ch(va_list args, char c, int mod)

{
	char	*str;
	
	str = ft_strnew(1);
	if (mod == 0 && c != 'C')
		*str = (char)va_arg(args, unsigned int);
	if (mod == 1 || c == 'C')
		*str = (char)va_arg(args, wchar_t);
	return (str);
}
