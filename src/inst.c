#include "corewar.h"

void	live_zjump_fork_lfork(char **data, int i)
{
	char 	*inst;
	char	**args;

	inst = "01"; // live
	if (data[i][1] == 'j') // zjump
		inst = "09";
	else if (data[i][1] == 'o') // fork
		inst = "0c";
	else if (data[i][1] == 'f') // lfork
		inst = "0f";
	i++;

	args = init_args();

	if (!data[i] || data[i + 1])
		ft_error(E_ARG_NB);

	if (check_arg(data[i]) == 2)
		args[0] = get_dir(data[i], 4);
	else
		ft_error(E_BD_ARG);

	add_inst(inst, NULL, args);
}

void	add_sub_and_or_xor(char **data, int i)
{
	char 	*inst;
	char	**args;
	char 	*args_code;

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
	
	if (!data[i] || !data[i + 1] || !data[i + 2] || data[i + 3])
		ft_error(E_ARG_NB);
	
	if (check_arg(data[i]) == 1 && check_arg(data[i]) == 1 && check_arg(data[i]) == 1) 
	{
		args[0] = get_reg(data[i]);
		args[1] = get_reg(data[i + 1]);
		args[2] = get_reg(data[i + 2]);
	}
	else 
		ft_error(E_BD_ARG);

	add_inst(inst, args_code, args);
}

void	aff(char **data, int i)
{
	char	**args;

	args = init_args();

	if (!data[i] || data[i + 1])
		ft_error(E_ARG_NB);
	
	if (check_arg(data[i]) == 1)
		args[0] = get_reg(data[i]);
	else
		ft_error(E_BD_ARG);

	ft_putstr(args[0]);
	add_inst("10", NULL, args);
}