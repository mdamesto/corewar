#include "corewar.h"

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

char	**split_cor(int fd)
{
	char *data;
	char *tmp;
	char **ret;
	int size;

	data = ft_strnew(1);
	//ret = ft_tab_set(4, 0);
	ret = malloc(sizeof(char*) * 5);
	ret[4] = NULL;

	while (get_next_line(fd, &tmp))
		data = ft_strjoin_f(data, tmp, 1);
	
	data = ft_rmv_space_f(data);
	data = ft_strcut_f(data, 0, 8);

	ret[0] = hex_to_str(ft_strget(data, 0, 256));
	ret[1] = hex_to_prog_size(ft_strget(data, 256, 272));
	ret[2] = hex_to_str(ft_strget(data, 272, 4376));
	size = ft_atoi(ret[1]);
	ret[3] = ft_strget(data, 4376, 4376 + (2 * size));

	/* -------  CHAMP -------- */
	ft_putstr("IN SPLIT COR ------ \n");
	ft_putstr("Champ name: ");
	ft_putstr(ret[0]);
	ft_putstr("\n");
	ft_putstr("Champ size: ");
	ft_putstr(ret[1]);
	ft_putstr("\n");
	ft_putstr("Champ inst: ");
	ft_putstr(ret[3]);
	ft_putstr("\n");
	
	return (ret);
}

char	**cut_insts(char *insts)
{
	int n;
	int i;
	char **ret;

	i = 0;
	ret = ft_tab_set(100, 0);
	while (*insts) {
		n = get_inst_len(insts);
		ret[i++] = ft_strget(insts ,0, n);
		insts = ft_strcut(insts, 0, n);
		
		/* -------- inst cut --------*/
		/*ft_putstr("n: ");
		ft_putnbr(n);
		ft_putstr("   ");
		ft_putstr("ret[");
		ft_putnbr(i - 1);
		ft_putstr("]: ");*/
		//ft_putstr(ret[i - 1]);
		//ft_putstr("\n");
		/* -------------------------- */
	}
	return (ret);
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

void	get_champ(char *str, t_env *env)
{
	int i = 0;
	int fd; 
	t_champ *new;
	char **data;
	
	if (ft_check_ext(str, ".cor", 4))
		ft_error(E_BD_EXT, str);
	if ((fd = open(str, O_RDONLY)) < 0) 
		ft_error(E_OPEN, str);
	if (!(new = ft_memalloc(sizeof(t_champ))))
		ft_error(E_MALLOC, NULL);
	data = split_cor(fd);
	
	new->name = data[0];
	new->size = data[1];
	new->comment = data[2];
	new->inst = cut_insts(data[3]);
	
	if (env->next_champ_nb > 0)
	{
		new->nb = env->next_champ_nb;
		env->next_champ_nb = -1;
	}
	else
		new->nb = get_champ_nb(env, i);
	
	i = 0;
	while (env->champs[i])
	{
		ft_putstr("HERE\n");
		i++;
	}
	env->champs[i] = new;

	//env->champs[i++] = new;
	
	/* -------- CHAMP --------*/
	ft_putstr("\nChamp number: ");
	ft_putnbr(new->nb);
	ft_putstr("\n");
	ft_putstr("data[0]: ");
	ft_putstr(data[0]);
	ft_putstr("\n");
	ft_putstr("Champ name: ");
	ft_putstr(new->name);
	ft_putstr("\n");
	ft_putstr("Champ size: ");
	ft_putstr(new->size);
	ft_putstr("\n");
	ft_putstr("Champ comment: ");
	ft_putstr(new->comment);
	ft_putstr("\n");
	int j = 0;
	while (new->inst[j]) 
	{
		ft_putstr("inst[");
		ft_putnbr(j);
		ft_putstr("]: ");
		ft_putstr(new->inst[j++]);
		ft_putstr("\n");
	}
	/* ----------------------- */
}