/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:22:42 by mdamesto          #+#    #+#             */
/*   Updated: 2016/01/21 15:51:04 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *c;
	char *r;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	c = (char *)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	r = c;
	if (c == NULL)
		return (NULL);
	while (*s1)
	{
		*c = *s1;
		c++;
		s1++;
	}
	while (*s2)
	{
		*c = *s2;
		c++;
		s2++;
	}
	*c = '\0';
	return (r);
}
