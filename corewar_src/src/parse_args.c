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

void	get_opt(char *opt, char *value, t_env *env)
{
	if (!ft_strncmp(opt, "-dump\0", 6))
	{
		if (value) 
		{
			env->dump = ft_atoi_check(value);
			//ft_putstr("\nDUMP = ");
			//ft_putnbr(env->dump);
		}
		else
			ft_error(E_BD_ARG, NULL);
	}
	else if(!ft_strncmp(opt, "-n\0", 3))
	{
		if (value) 
		{
			env->next_champ_nb = ft_atoi_check(value);
			//ft_putstr("\nNEXT CHAMP NB = ");
			//ft_putnbr(env->next_champ_nb);
		}
		else
			ft_error(E_BD_ARG, NULL);
	}
	else
		ft_error(E_BD_OPT, opt);
}

void	parse_args(int argc, char **argv, t_env *env)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-')
		{
			get_opt(argv[i], argv[i + 1], env);
			i++;
		}
		else
			get_champ(argv[i], env);
	}
	if (!env->champs[1])
		ft_error(E_CHP_NB, NULL);
	//sort_by_champ_nb(env); ----------------- TODO
}
