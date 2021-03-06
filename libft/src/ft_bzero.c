/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:38:26 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/25 20:48:21 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	long	*bp;
	char	*sp;

	bp = s;
	while (n > 8)
	{
		*bp++ = '\0';
		n -= 8;
	}
	sp = (char *)bp;
	while (n--)
		*sp++ = '\0'; 
}