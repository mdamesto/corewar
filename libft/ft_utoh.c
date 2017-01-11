/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtassett <mtassett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 16:57:29 by mtassett          #+#    #+#             */
/*   Updated: 2016/08/12 19:24:43 by mtassett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

inline static size_t	getsiz_hex2(uint64_t n, size_t r)
{
	if (n >= 0x100)
	{
		r += 2;
		n /= 0x100;
	}
	if (n >= 0x10)
		++r;
	return (r);
}

size_t					getsiz_hex(uint64_t n)
{
	size_t	r;

	r = 1;
	if (n >= 0x100000000)
	{
		r += 8;
		n /= 0x100000000;
	}
	if (n >= 0x10000)
	{
		r += 4;
		n /= 0x10000;
	}
	return (getsiz_hex2(n, r));
}


char	*ft_utoh(uint64_t n)
{
	static char const	base16[] = "0123456789abcdef";
	char				*new;
	size_t				siz;

	siz = getsiz_hex(n);
	if (!(new = (char*)malloc(siz + 1)))
		return (new);
	new += siz;
	*(new--) = '\0';
	while (siz--)
	{
		*(new--) = base16[n % 16];
		n /= 16;
	}
	return (new);
}
