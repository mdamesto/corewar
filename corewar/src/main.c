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

char	**split_cor(fd)
{
	char *data;
	char *tmp;
	char **ret;

	ret = ft_tab_set(4, 0);
	data = ft_strnew(1);
	while (get_next_line(fd, &tmp))
		data = ft_strjoin_f(data, tmp, 1);
	data = ft_rmv_space_f(data);
	data = ft_strcut_f(data, 0, 8);
	ret[0] = ft_strget(data, 0, 256);
	ft_putstr(ret[0]);
	ft_putstr("\n");
	ret[1] = ft_strget(data, 256, 272);
	ft_putstr(ret[1]);
	ft_putstr("\n");
	ret[2] = ft_strget(data, 272, 4376);
	ret[3] = ft_strget(data, 4376, 4390);
	ft_putstr(ret[3]);
	ft_putstr("\n");
	exit(1);
	return (ret);
}

void	get_champ(char *str)
{
	int fd;
	t_champ *new;
	char **data;

	if (ft_check_ext(str, ".cor", 4))
		ft_error(E_BD_EXT, str);
	if ((fd = open(str, O_RDONLY)) < 0) 
		ft_error(E_OPEN, str);
	if (!(new = ft_memalloc(sizeof(t_champ*))))
		ft_error(E_MALLOC, NULL);
	data = split_cor(fd);
	
	/* ------- DATA --------- */
	int i;

	i = 0;
	while (i < 4)
		ft_putstr(data[i]);
	/* ----------------------- */
	
	//new->filename = str;
	/*new->name = get_champ_name(data);
	new->size = get_champ_size(data);
	new->comment = get_champ_comment(data);
	new->insts = get_champ_insts(data);*/
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