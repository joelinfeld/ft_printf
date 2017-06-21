#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_flag
{
	int			mod = 0;
	int			octothorpe = 0;
	int			zero = 0;
	int			minus = 0;
	int			plus = 0;
	int			space = 0;
	char 		c;
	char		*str;
}				t_flag;

char			*di(va_list args, char c, int mod);
char			*o(va_list args, char c, int mod);
char			*u(va_list args, char c, int mod);
char			*x(va_list args, int mod);
char			*X(va_list args, int mod);
char			*c(va_list args, char c, int mod);
char			*s(va_list args, char c, int mod);
char			*p(va_list args, char c, int mod);

#endif 
