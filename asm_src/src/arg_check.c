#include "asm.h"

static	int		check_reg(char *arg)
{
	int i;
	char *tmp;
	int nb;

	i = 1;
	tmp = ft_strnew(10);
	while (arg[i]) 
	{
		tmp[i - 1] = arg[i];
		if (i > 2 || !ft_isdigit(arg[i++]))
			ft_error(E_BD_REG);
	}
	nb = ft_atoi(tmp);
	if (nb < 1 || nb > 256)
		ft_error(E_BD_REG);
	return (1);
}

static	int		check_dir(char *arg)
{
	int i;
	char *tmp;
	int nb;

	tmp = ft_strnew(10);
	if (arg[1] != LABEL_CHAR) // if label -> skip check
	{
		i = 1;
		while (arg[i])
		{
			tmp[i - 1] = arg[i];
			if ((!ft_isdigit(arg[i]) && arg[i] != '-') || i++ > 10)
				ft_error(E_BD_DIR);
		}
		nb = ft_atoi(tmp);
		if ((unsigned)nb > 4294967295)
			ft_error(E_BD_DIR);
	}
	return (2);
}

static	int		check_ind(char *arg)
{
	int i;
	char *tmp;
	int nb;

	tmp = ft_strnew(10);
	if (arg[0] != LABEL_CHAR)
	{
		i = 0;
		while (arg[i])
		{
			tmp[i] = arg[i];
			if ((!ft_isdigit(arg[i]) && arg[i] != '-') || i++ > 5)
				ft_error(E_BD_IND);
		}
		nb = ft_atoi(tmp);
		if (nb < -32768 || nb > 65535)
			ft_error(E_BD_IND);
	}
	return (3);
}

int				check_arg(char *arg)
{	
	if (arg[0] == 'r' && check_reg(arg))
		return (1);
	else if (arg[0] == DIRECT_CHAR && check_dir(arg))
		return (2);
	else
	{
		check_ind(arg);
		return (3);
	}
}
