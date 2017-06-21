#include "ft_printf.h"

char	*s(va_list args, char c, int mod)
{
	char	*str;
	if (mod == 0 && c != 'S')
		str = va_arg(args, char*);
	if (mod == 1 || c == 'S')
		str = (char*)va_arg(args, wchar_t*);
	return (str);
}
