#include "corewar.h"

void	live_zjump_fork_lfork(char **data, int i)
{
	char 	*inst;
	char	**args;
	char 	**split;

	inst = "01"; // live
	if (data[i][1] == 'j') // zjump
		inst = "09";
	else if (data[i][1] == 'o') // fork
		inst = "0c";
	else if (data[i][1] == 'f') // lfork
		inst = "0f";
	i++;

	args = init_args();
	split = ft_strsplit(data[i], ',');

	if (!split[0] || split[1] || data[i + 1])
		ft_error(E_ARG_NB);

	if (check_arg(split[0]) == 2)
		args[0] = get_dir(split[0], 4);
	else
		ft_error(E_BD_ARG);

	if (split)
		free(split);
	add_inst(inst, NULL, args);
}

void	add_sub_and_or_xor(char **data, int i)
{
	char 	*inst;
	char	**args;
	char 	*args_code;
	char 	**split;

	inst = "04"; // add
	if (data[i][1] == 'u') // sub
		inst = "05";
	else if (data[i][1] == 'n') // and
		inst = "06";
	else if (data[i][1] == 'r') // or
		inst = "07";
	else if (data[i][1] == 'o') // xor
		inst = "08";
	i++;

	args_code = "54";
	args = init_args();
	split = ft_strsplit(data[i], ',');
	
	if (!split[0] || !split[1] || !split[2] || split[3] || data[i + 1])
		ft_error(E_ARG_NB);

	
	if (check_arg(split[0]) == 1 && check_arg(split[1]) == 1 && check_arg(split[2]) == 1) 
	{
		args[0] = get_reg(split[0]);
		args[1] = get_reg(split[0]);
		args[2] = get_reg(split[0]);
	}
	else 
		ft_error(E_BD_ARG);

	if (split)
		free(split);
	add_inst(inst, args_code, args);
}

void	aff(char **data, int i)
{
	char	**args;
	char 	**split;

	args = init_args();
	split = ft_strsplit(data[i], ',');

	if (!split[0] || split[1] || data[i + 1])
		ft_error(E_ARG_NB);
	
	write(1, "HERE", 4);
	if (check_arg(split[0]) == 1)
		args[0] = get_reg(split[0]);
	else
		ft_error(E_BD_ARG);


	if (split)
		free(split);
	add_inst("10", NULL, args);
}