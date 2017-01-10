#include "corewar.h"

static void norme1(char **data, int i)
{
	if(!(ft_strncmp(data[i], "st", 2)))
		st(data, i + 1);
	else if(!(ft_strncmp(data[i], "ld", 2)))
		ld_lld(data, i);
	else if(!(ft_strncmp(data[i], "lld", 3)))
		ld_lld(data, i);
	else if(!(ft_strncmp(data[i], "aff", 3)))
		aff(data, i + 1);
	//LDI // STI------------------> TODO
	else
		ft_error(EBDINST);
}
void	inst_switch(char **data, int i)
{
	if(!(ft_strncmp(data[i], "live", 4)))
		live_zjump_fork_lfork(data, i);
	else if(!(ft_strncmp(data[i], "zjump", 4)))
		live_zjump_fork_lfork(data, i);
	else if(!(ft_strncmp(data[i], "fork", 4)))
		live_zjump_fork_lfork(data, i);
	else if(!(ft_strncmp(data[i], "lfork", 5)))
		live_zjump_fork_lfork(data, i);
	else if(!(ft_strncmp(data[i], "add", 3)))
		add_sub_and_or_xor(data, i);
	else if(!(ft_strncmp(data[i], "sub", 3)))
		add_sub_and_or_xor(data, i);
	else if(!(ft_strncmp(data[i], "and", 3)))
		add_sub_and_or_xor(data, i);
	else if(!(ft_strncmp(data[i], "or", 2)))
		add_sub_and_or_xor(data, i);
	else if(!(ft_strncmp(data[i], "xor", 3)))
		add_sub_and_or_xor(data, i);
	else
		norme1(data, i);
}

void	get_instructions(t_env *env)
{
	int i;
	int j;

	i = 0;
	env->data = ft_strsplit_space(env->line);

	if (env->data[0][ft_strlen(env->data[0]) - 1] == ':' && ft_strlen(env->data[0]) > 1) 
	{
		add_label(env, env->data[0]);
		if (!env->data[1]) {
			gnl();
			ft_tab_free(env->data);
			env->data = ft_strsplit_space(env->line);
		}
		else
			i++;
	}
	
	j = i;
	// ------- DEBUG: DATA ------ //
	/* ft_putstr("\ndata: ");
	while (env->data[j]) 
	{
		ft_putstr(env->data[j]);
		write (1, " ", 1);
		j++;
	}*/
	// --------------------------- // 
	
	inst_switch(env->data, i);
	ft_tab_free(env->data);
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
	
	print_labels(env); 	// ------- PRINT LABELS ------ // 
	print_inst(env);		// ------ PRINT ALL INST ----- //
	
	/* TODO */ replace_labels(env); 
	ft_putstr("\n*** parsing done! \n");
	return ("temporary return");
}
