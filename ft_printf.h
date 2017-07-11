#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

typedef struct	s_flag
{
	int			marg;
	int			mod;
	int			octothorpe;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	char 		c;
	char		*str;
}				t_flag;

char			*di(va_list args, char c, int mod);
char			*o(va_list args, char c, int mod);
char			*u(va_list args, char c, int mod);
char			*x(va_list args, int mod);
char			*X(va_list args, int mod);
char			*ch(va_list args, char c, int mod);
char			*s(va_list args, char c, int mod);
char			*p(va_list args, int mod);

#endif 
