/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 19:28:01 by mdamesto          #+#    #+#             */
/*   Updated: 2016/02/14 14:48:18 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		init_return(char **line, t_struct **t, int fd, int ret)
{
	int	r;

	r = 0;
	if (ret == 0)
	{
		(*t) = (t_struct*)malloc(sizeof(t_struct));
		(*t)->i = 0;
		(*t)->tmpbuf = NULL;
		(*t)->r = 1;
		if (line == NULL || fd < 0 || BUFF_SIZE <= 0)
			return (-1);
		*line = ft_strnew(0);
	}
	if (ret == 1)
	{
		line[0][(*t)->i] = '\0';
		r = (*t)->r;
		free(*t);
		if (r == 0)
			if (line[0][0] != '\0')
				return (1);
	}
	return (r);
}

void	line_buff_up(char **line, int fd, char **buf, t_struct *t)
{
	char	*tmp;
	int		len;

	if (t->i % 32 == 0)
	{
		len = ft_strlen(*line);
		tmp = ft_strnew(len);
		ft_strcpy(tmp, *line);
		free(*line);
		*line = ft_strnew(len + 32);
		ft_strcpy(*line, tmp);
		free(tmp);
	}
	if (!**buf)
	{
		*buf = ft_strnew(BUFF_SIZE);
		t->r = read(fd, *buf, BUFF_SIZE);
		if (t->tmpbuf)
			free(t->tmpbuf);
		t->tmpbuf = *buf;
	}
}

int		get_next_line(int const fd, char **line)
{
	static char	*buf = "";
	t_struct	*t;

	if (init_return(line, &t, fd, 0) == -1)
		return (-1);
	while (*buf != '\n')
	{
		
		if (t->i % 32 == 0 || !*buf)
			line_buff_up(line, fd, &buf, t);
		if (*buf != '\n')
			line[0][t->i++] = *buf++;
		if ((t->r == 0 && *buf == '\0') || t->r == -1)
			return (init_return(line, &t, fd, 1));
	}
	buf++;
	init_return(line, &t, fd, 1);
	return (1);
}
