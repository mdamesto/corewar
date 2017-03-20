/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:11:04 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/28 16:17:53 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int s;
	long int r;

	s = 1;
	r = 0;
	while (*str == '\t' || *str == '\f' || *str == '\n' || *str == '\r' ||
*str == '\v' || *str == ' ' || *str == ' ')
		str++;
	if (*str == '-')
		s = -s;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str) > 0)
	{
		r = r * 10 + *str++ - '0';
		if (r > 2147483647)
		{
			if (s < 0)
				return (-2147483648);
			return (2147483647);
		}
	}
	if (s < 0)
		r = -r;
	return ((int)r);
}
