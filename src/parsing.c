#include "corewar.h"

void	live(char **data, int i)
{
	int j;
	int reg_nb;
	char tmp[2];
	t_env *env;

	env = get_env(NULL);
	if (!data[i] || data[i + 1])
		ft_error(EINSTARG);
	
	if (data[i][j] == 'r')
	{
		ft_bzero(tmp, 3);
		j = 1;
		while (data[i][j]) {
			if (!ft_isdigit(data[i][j++]) || j > 2)
				ft_error(EBDREG);
			tmp[j - 1] = data[i][j];
		}
		reg_nb = ft_atoi(tmp);
		if (reg_nb < 1 || reg_nb > 16)
			ft_error(EBDREG);
		env->inst[env->inst_nb] = ""
		// int to binary + create fulll string... ---------------------------------------------- TODO
	}
}


static void norme1(char **data, int i)
{
	/*else if(data[i] == "zjmp")
		zjmp(data, i);
	else if(data[i] == "ldi")
		ldi(data, i);
	else if(data[i] == "sti")
		sti(data, i);
	else if(data[i] == "fork")
		fork(data, i);
	else if(data[i] == "lld")
		lld(data, i);
	else if(data[i] == "lldi")
		lldi(data, i);
	else if(data[i] == "lfork")
		lfork(data, i);
	else if(data[i] == "aff")
		aff(data, i);*/
	else
		ft_error(EBDINST);
}
void	op_switch(char **data, int i)
{
	if(data[i] == "live")
		live(data, i + 1);
	/*else if(data[i] == "ld")
		ld(data, i);
	else if(data[i] == "st")
		st(data, i);
	else if(data[i] == "add")
		add(data, i);
	else if(data[i] == "sub")
		sub(data, i);
	else if(data[i] == "and")
		and(data, i);
	else if(data[i] == "or")
		or(data, i);
	else if(data[i] == "xor")
		xor(data, i);*/
	else
		norme1(data, i);
}

void	get_instructions(t_env *env)
{
	char **data;
	int i;

	i = 0;
	data = ft_strsplit_space(env->line);
	if (data[0][ft_strlen(data[0]) - 1] == ':' && ft_strlen(data[0]) > 1) 
	{
		add_label(env, data[0]);
		if (!data[1]) {
			gnl();
			ft_tab_free(data);
			data = ft_strsplit_space(env->line);
		}
		else
			i++;
	}
	op_switch(data, i);

	ft_putstr("// INSTRUCTION \n");
	while (data[i]) 
	{
		ft_putstr(data[i]);
		write (1, "\n", 1);
		i++;
	}
	ft_tab_free(data);
}


char	*parsing_champion(t_env *env) 
{
	ft_putstr("*** starting parsing: ");
	ft_putstr(env->filename);
	ft_putstr(" ... \n");

	get_name(env);
	get_comment(env);
	while(gnl() != 0) {
		get_instructions(env);
	}
	print_labels(env);
	ft_putstr("*** parsing done! \n");
	return ("temporary return");
}
