/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itabl_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:04:28 by mdamesto          #+#    #+#             */
/*   Updated: 2016/02/14 18:10:33 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_itab_len(int **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		;
	return (i);
}
