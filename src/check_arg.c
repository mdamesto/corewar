#include "corewar.h"

int		check_arg(char *arg)
{
	int i;
	char *tmp;
	int nb;
	
	tmp = ft_strnew(10);
	if (arg[0] == 'r')
	{
		i = 1;
		while (arg[i]) 
		{
			tmp[i - 1] = arg[i];
			if (i > 2 || !ft_isdigit(arg[i++]))
				ft_error(E_BD_REG);
		}
		nb = ft_atoi(tmp);
		if (nb < 1 || nb > 16)
			ft_error(E_BD_REG);
		return (1);
	}
	else if (arg[0] == DIRECT_CHAR)
	{
		if (arg[1] == LABEL_CHAR)
			return (2);
		else
		{
			i = 1;
			while (arg[i])
			{
				tmp[i - 1] = arg[i];
				if (i > 10 || !ft_isdigit(arg[i++]))
					ft_error(E_BD_DIR);
			}
			nb = ft_atoi(tmp);
			if (nb < 0 || nb > 2147483647)
				ft_error(E_BD_DIR);
			return (2);
		}
	}
	else
	{
		if (arg[0] == LABEL_CHAR)
			return (3);
		else
		{
			i = 0;
			while (arg[i])
			{
				tmp[i - 1] = arg[i];
				if (i > 5 || !ft_isdigit(arg[i++]))
					ft_error(E_BD_IND);
			}
			nb = ft_atoi(tmp);
			if (nb < 0 || nb > 65535)
				ft_error(E_BD_IND);
			return (3);
		}
	}
}

char 	*get_reg(char *arg) 
{
	t_env *env;
	int i;
	char *tmp;

	tmp = ft_strnew(3);
	env = get_env(NULL);
	env->add_to_adress++;
	i = 1;
	while (arg[i]) 
	{
		tmp[i - 1] = arg[i];
		i++;
	}
	return (convert_hex_octnb(ft_atoi(tmp), 1));
}

 char	*get_dir(char *arg, int size)
 {
	t_env *env;
	int i;
	char *tmp;

	tmp = ft_strnew(10);
	env = get_env(NULL);
	env->add_to_adress += size;
	if (arg[1] == LABEL_CHAR)
	{
		arg[0] = LABEL_CHAR;
		arg[1] = DIRECT_CHAR;
		return (ft_strjoin(ft_strjoin(arg, ft_itoa(size)), ":"));
	}
	else
	{
		i = 1;
		while (arg[i]) 
		{
			tmp[i - 1] = arg[i];
			i++;
		}
		return (convert_hex_octnb(ft_atoi(tmp), size));
	}
}

char	*get_ind(char *arg)
 {
	t_env *env;
	int i;
	char *tmp;

	tmp = ft_strnew(10);
	env = get_env(NULL);
	env->add_to_adress += 2;
	if (arg[0] == LABEL_CHAR)
		return (ft_strjoin(arg, ":"));
	else
	{
		i = 0;
		while (arg[i]) 
		{
			tmp[i - 1] = arg[i];
			i++;
		}
		return (convert_hex_octnb(ft_atoi(tmp), 2));
	}
}