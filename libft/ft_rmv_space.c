/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmv_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:27:15 by mdamesto          #+#    #+#             */
/*   Updated: 2016/01/22 15:36:07 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 	*ft_rmv_space(char *str)
{
	int i;
	int len;
	char *tmp;

	i = 0;
	len = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '	'))
			i++;
		while (str[i] && str[i] != ' ' && str[i] != '	')
		{
			i++;
			len++;
		}
		len++;
	}
	tmp = ft_strnew(len);
	i = 0;
	len = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '	'))
			i++;
		while (str[i] && str[i] != ' ' && str[i] != '	')
			tmp[len++] = str[i++];
		tmp[len++] = ' ';
	}
	tmp[len] = '\0';
	free(str);
	return (tmp);
}