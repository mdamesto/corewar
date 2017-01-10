#include "corewar.h"

void	ld_lld(char **data, int i)
{
	char 	*inst;
	char	**args;
	char 	*args_code;

	inst = "000000010";
	if (ft_strlen(data[i]) == 3)
		inst = "00001101";

	args_code = "01010000";;
	args = init_args();

	if (!data[i] || !data[i + 1] || data[i + 2])
		ft_error(E_ARG_NB);
	
	if (check_arg(data[i]) == 1) 
		args[0] = get_reg(data[i]);
	else if (check_arg(data[i]) == 3)
	{
		args_code = "11010000";
		args[0] = get_ind(data[i]);
	}
	else
		ft_error(E_BD_ARG);

	if (check_arg(data[i + 1]) == 1)
		args[1] = get_reg(data[i + 1]);
	else 
		ft_error(E_BD_ARG);

	add_inst(inst, args_code, args);
}

void	st(char **data, int i)
{
	char	**args;
	char 	*args_code;

	args_code = "01010000";
	args = init_args();

	if (!data[i] || !data[i + 1] || data[i + 2])
		ft_error(E_ARG_NB);
	
	if (check_arg(data[i]) == 1)
		args[0] = get_reg(data[i]);
	else 
		ft_error(E_BD_ARG);
	if (check_arg(data[i + 1]) == 1) 
		args[1] = get_reg(data[i+ 1]);
	else if (check_arg(data[i + 1]) == 3)
	{
		args_code = "01110000";
		args[1] = get_ind(data[i+ 1]);
	}
	else
		ft_error(E_BD_ARG);

	add_inst("00000011", args_code, args);
}