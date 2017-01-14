#include "corewar.h"

static void norme1(char **data)
{
	if(!(ft_strcmp(data[0], "fork")))
		live_zjump_fork_lfork(data[1], "0c");
	else if(!(ft_strcmp(data[0], "lld")))
		ld_lld_and(data[1], "0d");
	else if(!(ft_strcmp(data[0], "lddi")))
		ldi_lldi(data[1], "0e");
	else if(!(ft_strcmp(data[0], "lfork")))
		live_zjump_fork_lfork(data[1], "0f");
	else if(!(ft_strcmp(data[0], "aff")))
		aff(data[1], "10");
	else 
	{
		ft_putstr("\n HERE: ");
		ft_putstr(data[0]);
		ft_error(EBDINST);
	}
}

void	inst_switch(char **data)
{
	if(!(ft_strcmp(data[0], "live")))
		live_zjump_fork_lfork(data[1], "01");
	else if(!(ft_strcmp(data[0], "ld")))
		ld_lld_and(data[1], "02");
	else if(!(ft_strcmp(data[0], "st")))
		st(data[1], "03");
	else if(!(ft_strcmp(data[0], "add")))
		add_sub(data[1], "04");
	else if(!(ft_strcmp(data[0], "sub")))
		add_sub(data[1], "05");
	else if(!(ft_strcmp(data[0], "and")))
		ld_lld_and(data[1], "06");
	else if(!(ft_strcmp(data[0], "or")))
		or_xor(data[1], "07");
	else if(!(ft_strcmp(data[0], "xor")))
		or_xor(data[1], "08");
	else if(!(ft_strcmp(data[0], "zjump")))
		live_zjump_fork_lfork(data[1], "09");
	else if(!(ft_strcmp(data[0], "ldi")))
		ldi_lldi(data[1], "0a");
	else if(!(ft_strcmp(data[0], "sti")))
		sti(data[1], "0b");
	else
		norme1(data);
}


int 	is_label_char(char c)
{
	int i;
	char *label_char = "abcdefghijklmnopqrstuvwxyz_0123456789";

	i = -1;
	while(label_char[++i])
	{
		if (label_char[i] == c)
			return (1);
	}
	return (0);
}

char **split_label(char *str) {
	char **ret;
	int i;

	ret = NULL;
	i = 0;
	while((is_label_char(str[i]) || str[i] == ':') && !ret)
	{
		if (str[i] == ':')
		{
			ft_putstr("\n LABEL: ");
			ret = ft_tab_set(2, ft_strlen(str));
			ret[0] = ft_strcpy(ret[0], str);
			ret[0] = ft_strcut_end(ret[0], ft_strlen(str) - i);
			ft_putstr("\n ret[0]: ");
			ft_putstr(ret[0]);
			ret[1] = ft_strcpy(ret[1], str);
			ret[1] = ft_strtrim(ft_strcut_beg(ret[1], i + 1));
			ft_putstr("\n ret[1]: ");
			ft_putstr(ret[1]);
		}
		i++;
	}
	return (ret);
}

char **split_first_word(char *str) {
	char **ret;
	int i;

	ret = NULL;
	i = 0;
	ft_putstr("\n INSTR: ");
	ft_putstr(str);
	while(str[i] && !ret)
	{
		if (str[i] == ' ' || str[i] == '	')
		{
			ret = ft_tab_set(2, ft_strlen(str));
			ret[0] = ft_strcpy(ret[0], str);
			ret[0] = ft_strcut_end(ret[0], ft_strlen(str) - i);
			ret[1] = ft_strcpy(ret[1], str);
			ret[1] = ft_strtrim(ft_strcut_beg(ret[1], i));
		}
		i++;
	}
	return (ret);
}


void	get_instructions(t_env *env)
{
	int i;
	char **tmp;

	i = 0;

	env->data = split_label(env->line);
	if (env->data)
	{
		i = -1;
		while(env->data[0][++i])
		{
			if (!is_label_char(env->data[0][i]))
				ft_error(E_BD_LBL);

		}
		add_label(env, env->data[0]);

		if (!ft_strlen(env->data[1]))
		{
			gnl();
			ft_tab_free(env->data);
			env->data = split_first_word(env->line);
		}
		else
		{
			tmp = env->data;
			env->data = split_first_word(env->data[1]);
			//ft_tab_free(tmp);
		}
	}
	else
		env->data = split_first_word(env->line);

	if (env->data)
		inst_switch(env->data);
	else
		ft_error(EBDINST);
	ft_tab_free(env->data);
}

void	parsing_champion(t_env *env) 
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
	//print_inst(env);		// ------ PRINT ALL INST ----- //
	
	replace_labels(env); 

	print_inst(env);		// ------ PRINT ALL INST ----- //
	
	ft_putstr("\n*** parsing done! \n");
}
