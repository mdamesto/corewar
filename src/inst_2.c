#include "asm.h"

void	ld_lld_and(char *data, char *inst)
{
	char	**args;
	char 	*args_code;
	char 	**split;


	args_code = "50";;
	args = init_args();
	split = ft_strsplit(data, ',');
	ft_tab_trim(split);

	if (!split[0] || !split[1] || split[2])
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

void	ldi_lldi(char *data, char *inst)
{
	char	**args;
	char 	**tab_args_code;
	char 	*args_code;
	char 	**split;


	tab_args_code = ft_tab_set(4, 2);
	ft_strcpy(tab_args_code[3], "00");
	args = init_args();
	split = ft_strsplit(data, ',');
	ft_tab_trim(split);
	
	if (!split[0] || !split[1] || !split[2] || split[3])
		ft_error(E_ARG_NB);

	
	if (check_arg(split[0]) == 1) 
	{
		args[0] = get_reg(split[0]);
		ft_strcpy(tab_args_code[0], "01");
	}
	else if(check_arg(split[0]) == 2)
	{
		args[0] = get_dir(split[0], 2);
		ft_strcpy(tab_args_code[0], "10");
	}
	else if(check_arg(split[0]) == 3)
	{
		args[0] = get_ind(split[0]);
		ft_strcpy(tab_args_code[0], "11");
	}
	else 
		ft_error(E_BD_ARG);

	if (check_arg(split[1]) == 1)
	{ 
		args[1] = get_reg(split[1]);
		ft_strcpy(tab_args_code[1], "01");
	}
	else if(check_arg(split[1]) == 2)
	{
		args[1] = get_dir(split[1], 2);
		ft_strcpy(tab_args_code[1], "10");
	}
	else 
		ft_error(E_BD_ARG);

	if (check_arg(split[2]) == 1)
		 ft_strcpy(tab_args_code[2], "01");
	else 
		ft_error(E_BD_ARG);

	args_code = convert_hex_octnb(ft_bin_to_int(ft_tab_join(tab_args_code)), 1);
	
	ft_tab_free(tab_args_code);
	if (split)
		free(split);
	add_inst(inst, args_code, args);
}


void	st(char *data, char *inst)
{
	char	**args;
	char 	*args_code;
	char 	**split;

	args_code = "50";
	args = init_args();
	split = ft_strsplit(data, ',');
	ft_tab_trim(split);

	if (!split[0] || !split[1] || split[2])
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
	add_inst(inst, args_code, args);
}

void	sti(char *data, char *inst)
{
	char	**args;
	char 	**tab_args_code;
	char 	*args_code;
	char 	**split;


	tab_args_code = ft_tab_set(4, 2);
	ft_strcpy(tab_args_code[3], "00");
	args = init_args();
	split = ft_strsplit(data, ',');
	ft_tab_trim(split);
	
	if (!split[0] || !split[1] || !split[2] || split[3])
		ft_error(E_ARG_NB);

	
	if (check_arg(split[0]) == 1) 
	{
		args[0] = get_reg(split[0]);
		ft_strcpy(tab_args_code[0], "01");
	}
	else
		ft_error(E_BD_ARG);

	if (check_arg(split[1]) == 1) 
	{
		args[1] = get_reg(split[1]);
		ft_strcpy(tab_args_code[1], "01");
	}
	else if(check_arg(split[1]) == 2)
	{
		args[1] = get_dir(split[1], 2);
		ft_strcpy(tab_args_code[1], "10");
	}
	else if(check_arg(split[1]) == 3)
	{
		args[1] = get_ind(split[1]);
		ft_strcpy(tab_args_code[1], "11");
	}
	else 
		ft_error(E_BD_ARG);

	if (check_arg(split[2]) == 1)
	{
		args[2] = get_reg(split[2]); 
		ft_strcpy(tab_args_code[2], "01");
	}
	else if(check_arg(split[2]) == 2)
	{
		args[2] = get_dir(split[2], 2);
		ft_strcpy(tab_args_code[2], "10");
	}
	else 
		ft_error(E_BD_ARG);

	args_code = convert_hex_octnb(ft_bin_to_int(ft_tab_join(tab_args_code)), 1);
	
	ft_tab_free(tab_args_code);
	if (split)
		free(split);
	add_inst(inst, args_code, args);
}



