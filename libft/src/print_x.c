/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:54:14 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/18 17:42:56 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	calibrate_format_x(t_printf_format *format, char *hexa,
								unsigned long x)
{
	if (format->flags.hashtag)
		format->flags.hashtag++;
	if (format->precision_size == 0 && x == 0)
		format->hide_print = 1;
	if (!format->hide_print)
	{
		format->precision_size -= ft_strlen(hexa);
		if (format->precision_size < 0)
			format->precision_size = 0;
		format->pad_size -= (format->precision_size + ft_strlen(hexa));
		if (x)
		{
			if (format->flags.hashtag)
				format->pad_size -= 2;
		}
		else
			format->flags.hashtag = 0;
		if (format->pad_size < 0)
			format->pad_size = 0;
	}
	format->flags.plus = 0;
	format->flags.space = 0;
}

char		*get_hexa_x(unsigned long x, char type)
{
	char	*otp;
	int		i;

	otp = ft_strnew(21);
	i = 0;
	while (x > 15)
	{
		otp[i] = ft_printf_hexa_table(x % 16, type);
		x /= 16;
		i++;
	}
	otp[i] = ft_printf_hexa_table(x % 16, type);
	otp[i + 1] = '\0';
	ft_strrev(otp);
	return (otp);
}

int			print_x(t_printf_format format, unsigned long x)
{
	char	*hexa;

	hexa = get_hexa_x(x, format.type);
	calibrate_format_x(&format, hexa, x);
	free(hexa);
	return (format.pad_size + (format.hide_print ? 0 : (format.precision_size +
									ft_strlen(hexa)) + format.flags.hashtag));
}
