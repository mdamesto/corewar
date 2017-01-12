#include "corewar.h"

void	ld_lld(char **data, int i)
{
	char 	*inst;
	char	**args;
	char 	*args_code;
	char 	**split;

	inst = "02";
	if (ft_strlen(data[i]) == 3)
		inst = "0d";
	i++;

	args_code = "01010000";;
	args = init_args();
	split = ft_strsplit(data[i], ',');

	if (!split[0] || !split[1] || split[2] || data[i + 1])
		ft_error(E_ARG_NB);
	
	if (check_arg(split[0]) == 1) 
		args[0] = get_reg(split[0]);
	else if (check_arg(split[0]) == 2){
		args_code = "90";
		args[0] = get_dir(split[0], 4);
	}
	else if (check_arg(split[0]) == 3)
	{
		args_code = "d0";
		args[0] = get_ind(split[0]);
	}
	else
		ft_error(E_BD_ARG);

	if (check_arg(split[1]) == 1)
		args[1] = get_reg(split[1]);
	else 
		ft_error(E_BD_ARG);

	if (split)
		free(split);
	add_inst(inst, args_code, args);
}

void	st(char **data, int i)
{
	char	**args;
	char 	*args_code;
	char 	**split;

	args_code = "50";
	args = init_args();
	split = ft_strsplit(data[i], ',');

	if (!split[0] || !split[1] || split[2] || data[i + 1])
		ft_error(E_ARG_NB);
	
	if (check_arg(split[0]) == 1)
		args[0] = get_reg(split[0]);
	else 
		ft_error(E_BD_ARG);
	
	if (check_arg(split[1]) == 1) 
		args[1] = get_reg(split[1]);
	else if (check_arg(split[1]) == 3)
	{
		args_code = "70";
		args[1] = get_ind(split[1]);
	}
	else
		ft_error(E_BD_ARG);

	if (split)
		free(split);
	add_inst("03", args_code, args);
}



