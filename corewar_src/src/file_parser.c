/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:19:28 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/20 19:10:13 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void	invalid_file_error(void)
{
	ft_printf("invalid file. terminating VM\n");
	exit(0);
}

static int	get_instructions(t_player *player, int fd, unsigned int bufint)
{
	unsigned char	*buf;
	unsigned int	i;

	i = 0;
	buf = (unsigned char *)malloc(sizeof(unsigned char));
	while (read(fd, buf, 1))
	{
		player->instructions[i] = *buf;
		i++;
		if (i > bufint)
		{
			ft_printf("\nerror instructions count : %d vs %d\n", i, bufint);
			invalid_file_error();
		}
	}
	if (i != bufint)
	{
		ft_printf("\nerror instructions count : %d vs %d\n", i, bufint);
		invalid_file_error();
	}
	free(buf);
	return (1);
}

static int	get_bufint(t_player *player, unsigned int *bufint, int fd)
{
	unsigned char *buf;

	buf = (unsigned char *)malloc(sizeof(unsigned char) * 4);
	if (read(fd, buf, 4) != 4)
		invalid_file_error();
	*bufint = (buf[0] << 24) + (buf[1] << 16) + (buf[2] << 8) + buf[3];
	if (*bufint > CHAMP_MAX_SIZE)
	{
		ft_printf("error size, too big : %d vs %d\n", *bufint, CHAMP_MAX_SIZE);
		invalid_file_error();
		player->instructions_size = *bufint;
	}
	else
		player->instructions_size = *bufint;
	free(buf);
	return (1);
}

static int	check_header(int fd)
{
	unsigned char	*buf;
	unsigned int	bufint;

	buf = (unsigned char *)malloc(sizeof(unsigned char) * 4);
	if (read(fd, buf, 4) != 4)
		invalid_file_error();
	bufint = (buf[1] << 16) + (buf[2] << 8) + buf[3];
	if (bufint != COREWAR_EXEC_MAGIC)
	{
		ft_printf("header error : %#x vs %#x\n", bufint, COREWAR_EXEC_MAGIC);
		invalid_file_error();
	}
	free(buf);
	return (1);
}

t_player	*file_parser(int fd)
{
	t_player		*player;
	unsigned char	*buf;
	unsigned int	bufint;

	player = player_init();
	buf = (unsigned char *)malloc((2048 > CHAMP_MAX_SIZE) ?
								2048 + 4 : CHAMP_MAX_SIZE + 4);
	if (!check_header(fd))
		return (NULL);
	if (read(fd, buf, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
		invalid_file_error();
	player->name = ft_strcpy(player->name, (char *)buf);
	if (read(fd, buf, 4) != 4)
		invalid_file_error();
	if (!get_bufint(player, &bufint, fd))
		return (NULL);
	if (read(fd, buf, COMMENT_LENGTH + 4) != COMMENT_LENGTH + 4)
		invalid_file_error();
	if (!get_instructions(player, fd, bufint))
		return (NULL);
	free(buf);
	return (player);
}
