#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include <locale.h>

typedef struct	s_flag
{
	int			marg;
	int			mod;
	int			octothorpe;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			precision;
	int			isneg;
	int			wide;
	char 		c;
	char		*str;
	wchar_t		*wstr;
}				t_flag;
char			*di(va_list args, char c, int mod);
char			*o(va_list args, char c, int mod);
char			*u(va_list args, char c, int mod);
char			*x(va_list args, int mod);
char			*X(va_list args, int mod);
char			*ch(va_list args, int mod);
char			*s(va_list args, int mod);
char			*p(va_list args, int mod);
wchar_t			*wc(va_list args, char c, int mod);
wchar_t			*ws(va_list args, char c, int mod);
int				ft_putchar_count(char c);
void			printocto(t_flag flag);
int				printzero(t_flag flag, int len);
int				printmarg(t_flag flag, int len);
int				printminus(t_flag flag, int len);

#endif 
