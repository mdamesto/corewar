#include "corewar.h"

int		ft_atoi_check(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			ft_error(E_BD_ARG, str);
	return (ft_atoi(str));
}

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
	ret = ft_tab_set(4, 0);

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

int	get_n_to_cut(char a, char b, int size)
{
	int n;

	n = 0;
	if (a == '5') 
		n = 2;
	else if(a == 'a')
		n = 2 * size;
	else if (a == 'f')
		n = 4;
	else if (a == '6' || a == '9')
		n = 1 + size;
	else if (a == '7' || a == 'd')
		n = 3;
	else if (a == 'b' || a == 'e')
		n = 2 + size;
	if (b == '4')
		n += 1;
	else if (b == '8')
		n += size;
	else if (b == 'c')
		n += 2;
	return ((n + 2) * 2);
}

char	**cut_inst(char *str)
{
	int n;
	int i;
	char **ret;

	i = 0;
	ret = ft_tab_set(100, 0);
	while (*str) {
		n = 0;
		/*ft_putstr("code: ");
		ft_putchar(str[0]);
		ft_putchar(str[1]);
		ft_putstr("\n");*/

		if(str[0] == '1' && str[1] == '0')
			n += 4;
		else if(str[0] == '0' && ft_ishex(str[1]))
		{
			if(str[1] == '1' )
				n += 10;
			else if (str[1] == '9' || str[1] == 'c' || str[1] == 'f')
				n += 6;
			else if(str[1] == '4' || str[1] == '5')
				n += 10;
			else if (str[1] == 'a' || str[1] == 'b' || str[1] == 'e' || str[1] == '3') //op for wich size direct = 2
				n += get_n_to_cut(str[2], str[3], 2);
			else if (str[1] == '2' || str[1] == '6' || str[1] == '7' || str[1] == '8' || str[1] == 'd') //op for wich size direct = 4
				n += get_n_to_cut(str[2], str[3], 4);
		}
		else
			; // error wrong opcode?

		/*ft_putstr("n: ");
		ft_putnbr(n);
		ft_putstr("   ");
		ft_putstr("ret[");
		ft_putnbr(i);
		ft_putstr("]: ");*/
		ret[i++] = ft_strget(str ,0, n);
		//ft_putstr(ret[i - 1]);
		//ft_putstr("\n");
		str = ft_strcut(str, 0, n);
	}
	return (ret);
}

void	get_champ(char *str)
{
	int fd;
	t_champ *new;
	char **data;
	t_env *env;

	env = get_env(NULL);
	if (ft_check_ext(str, ".cor", 4))
		ft_error(E_BD_EXT, str);
	if ((fd = open(str, O_RDONLY)) < 0) 
		ft_error(E_OPEN, str);
	if (!(new = ft_memalloc(sizeof(t_champ*))))
		ft_error(E_MALLOC, NULL);
	
	data = split_cor(fd);
	new->name = data[0];
	new->size = data[1];
	new->comment = data[2];
	new->inst = cut_inst(data[3]);
	
	/* -------- CHAMP --------*/
	ft_putstr("Champ name: ");
	ft_putstr(new->name);
	ft_putstr("\n");
	ft_putstr("Champ size: ");
	ft_putstr(new->size);
	ft_putstr("\n");
	ft_putstr("Champ comment: ");
	ft_putstr(new->comment);
	ft_putstr("\n");
	ft_putstr("Champ inst: ");
	int i = 0;
	while (new->inst[i]) 
	{
		ft_putstr("inst[");
		ft_putnbr(i);
		ft_putstr("]: ");
		ft_putstr(new->inst[i++]);
		ft_putstr("\n");
	}
}

void	parse_args(int argc, char **argv)
{
	t_env *env;
	int i;

	env = get_env(NULL);
	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (!ft_strncmp(argv[i], "-dump\0", 6))
			{
				if (argv[++i]) 
				{
					env->dump = ft_atoi_check(argv[i]);
					ft_putstr("\nDUMP = ");
					ft_putnbr(env->dump);
				}
				else
					ft_error(E_BD_ARG, NULL);
			}
			else if(!ft_strncmp(argv[i], "-n\0", 3))
			{
				if (argv[++i]) 
				{
					env->next_champ_nb = ft_atoi_check(argv[++i]);
					ft_putstr("\nNEXT CHAMP NB = ");
					ft_putnbr(env->next_champ_nb);
				}
				else
					ft_error(E_BD_ARG, NULL);
			}
			else
				ft_error(E_BD_OPT, argv[i]);
		}
		else
			get_champ(argv[i]);
	}
	if (!env->champs[1])
		ft_error(E_CHP_NB, NULL);
}

int main(int argc, char **argv)
{
	init_env();
	parse_args(argc, argv);
	return 0;
}