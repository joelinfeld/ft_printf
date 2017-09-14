/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 12:19:53 by jinfeld           #+#    #+#             */
/*   Updated: 2017/09/12 20:02:39 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int			len;
	int			edit;
	char		c;
	char		*str;
	wchar_t		*wstr;
}				t_flag;

char			*di(va_list args, char c, int mod);
char			*o(va_list args, char c, int mod);
char			*u(va_list args, char c, int mod);
char			*x(va_list args, int mod);
char			*capx(va_list args, int mod);
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
char			*conhub(va_list args, char c, int mod);
wchar_t			*wconhub(va_list args, char c, int mod);
void			getmod(t_flag *flag, char *str);
void			flagnew(t_flag *flag);
int				setflagvalue(int *n, int value, int cur);
int				setflagminus(t_flag *flag, char *str);
void			flagparse(t_flag *flag, char *str, va_list args);
int				handleprecision(t_flag *flag, int len);
int				rightpad(t_flag flag, int len);
int				leftpad(t_flag flag, int *len);
void			ft_wputstr(wchar_t *str);
void			ft_wputchar(wchar_t c);
int				putflagstr(t_flag flag);
int				demprintz(t_flag flag);
int				printlen(t_flag *flag);
int				wprintlen(t_flag *flag);
int				ft_printf(const char *format, ...);
void			ddelete(char **str);
#endif
