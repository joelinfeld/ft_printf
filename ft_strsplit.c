/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:55:20 by jinfeld           #+#    #+#             */
/*   Updated: 2017/01/26 01:03:32 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordlen(char const *s, char c, int i)
{
	size_t wordlen;

	wordlen = 0;
	while (s[i])
	{
		if (s[i] != c)
			wordlen++;
		else
			break ;
		i++;
	}
	return (wordlen);
}

static size_t	words(char const *s, char c)
{
	size_t	words;
	int		i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			words++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;

	if (s)
	{
		i = 0;
		j = 0;
		if (!(res = (char **)malloc(sizeof(char *) * (words(s, c) + 1))))
			return (NULL);
		while (s[i] && j < (int)words(s, c))
		{
			if (s[i] == c)
				i++;
			else
			{
				res[j++] = ft_strsub(s, (unsigned int)i, wordlen(s, c, i));
				while (s[i] && s[i] != c)
					i++;
			}
		}
		res[j] = NULL;
		return (res);
	}
	return (NULL);
}
