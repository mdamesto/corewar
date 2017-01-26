#include "corewar.h"
#include <stdio.h>

int		ft_check_ext(char *file, char *ext, size_t siz)
{
	int i;

	i = ft_strlen(file) - siz;
	while (siz--)
	{
		if (file[i++] != *(ext++))
			return (1);
	}
	return (0);
}

int 	get_champ_nb(t_env *env, int i)
{
	int j;
	int n;
	int b;

	n = 1;
	b = 1;
	while (b)
	{
		b = 0;
		j = 0;
		while (j < i)
		{
			if (n == env->champs[j]->nb)
			{
				n++;
				b = 1;
			}
			j++;
		}
	}
	return n;
}

int get_size(char *data)
{
	int ret;

	if (data[0] || data[1])
		ft_error(E_BD_CHP_SIZ, NULL);
	ret = 0;
	ret = data[3] + data[2] * 16;
	return (ret);
}


void	split_header_prog(int fd, t_champ *champ)
{
	char data[sizeof(header_t) + CHAMP_MAX_SIZE + 9];
	int n;
	char tmp[4];

	n = read(fd, data, (sizeof(header_t) + CHAMP_MAX_SIZE + 9));
	
	ft_memcpy(champ->name, &data[4], PROG_NAME_LENGTH);
	ft_memcpy(tmp, &data[4 + PROG_NAME_LENGTH + 4], 4);
	champ->size = get_size(tmp);
	ft_memcpy(champ->comment, &data[4 + PROG_NAME_LENGTH + 8], COMMENT_LENGTH);
	ft_memcpy(champ->inst, &data[4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4], champ->size);
	if (!(champ->process = ft_memalloc(sizeof(t_process*) * 100))) //imp a good method to realloc it ---- TODO
		ft_error(E_MALLOC, NULL);
	champ->alive = true;

	ft_putnbr(champ->size);
	if (n != (4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4 + champ->size))
		ft_error(E_BD_CHP_SIZ, NULL);
}

void static debug_champ(int i, t_champ *new)
{
	ft_putstr("\n---- CHAMPS ----\n");
	ft_putstr("\ni: ");
	ft_putnbr(i - 1);
	ft_putstr("\n");
	ft_putstr("\nChamp number: ");
	ft_putnbr(new->nb);
	ft_putstr("\n");
	ft_putstr("champ name: ");
	ft_putstr(new->name);
	ft_putstr("\n");
	ft_putstr("champ size: ");
	ft_putnbr(new->size);
	ft_putstr("\n");
	ft_putstr("champ comment: ");
	ft_putstr(new->comment);
	ft_putstr("\n");
	ft_putstr("champ inst: \n");
	ft_print_memory(new->inst, new->size);
	ft_putstr("\n");
}

void	get_champ(char *str, t_env *env)
{
	static int i = 0;
	int fd; 
	t_champ *new;
	
	if (ft_check_ext(str, ".cor", 4))
		ft_error(E_BD_EXT, str);
	if ((fd = open(str, O_RDONLY)) < 0) 
		ft_error(E_OPEN, str);
	if (!(new = ft_memalloc(sizeof(t_champ))))
		ft_error(E_MALLOC, NULL);
	split_header_prog(fd, new);
	if (env->next_champ_nb > 0)
	{
		new->nb = env->next_champ_nb;
		env->next_champ_nb = -1;
	}
	else
		new->nb = get_champ_nb(env, i);
	env->champs[i++] = new;

	if (DBG_CHAMP)
		debug_champ(i, new);
}