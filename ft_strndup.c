#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char *res;
	res = ft_strnew(n);
	if (res)
		ft_strncpy(res, s1, n);
	return (res);
}
