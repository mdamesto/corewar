/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:13:20 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/28 15:22:03 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_chrcnt(char const *s, char c)
{
	size_t i;

	if (!s || !c)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s == c)
		{
			i++;
			while (*s++ == c)
				;
		}
		s++;
	}
	return (i);
}

static char		*ft_strdup_mod(const char *s, size_t start, size_t end)
{
	char	*new;
	size_t	size;
	size_t	i;

	i = 0;
	size = end - start;
	if (!(new = ft_strnew(size)))
		return (NULL);
	while (i < size)
	{
		new[i] = s[start + i];
		i++;
	}
	return (new);
}

static char		*create_str(const char *s, size_t *last, size_t *cur)
{
	char	*tmp;

	if (*last == *cur)
		return (NULL);
	tmp = ft_strdup_mod(s, *last, *cur);
	*last = *cur;
	return (tmp);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	cur;
	size_t	last;
	size_t	i;
	size_t	len;

	len = ft_chrcnt(s, c);
	if (!(tab = (char**)malloc(sizeof(char *) * (len + 1))) || !s || !c)
		return (NULL);
	last = 0;
	i = 0;
	while (s[last] == c)
		last++;
	while (i < len)
	{
		cur = last;
		while (s[cur] != c && s[cur])
			cur++;
		tab[i++] = create_str(s, &last, &cur);
		while (s[last] == c)
			last++;
	}
	if (len == 0 && *s)
		tab[0] = ft_strdup(s);
	return (tab);
}
