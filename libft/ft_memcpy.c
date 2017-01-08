/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:40:30 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/25 20:50:59 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dstchar;
	char	*srcchar;

	dstchar = dst;
	srcchar = (char *)src;
	i = 0;
	while (i < n)
	{
		dstchar[i] = srcchar[i];
		i++;
	}
	return (dst);
}
