#include "corewar.h"

static	char	**split_label(char *str) {
	char **ret;
	int i;

	ret = NULL;
	i = 0;
	while((ft_is_label_char(str[i]) || str[i] == ':') && !ret)
	{
		if (str[i] == ':')
		{
			ret = ft_tab_set(2, ft_strlen(str));
			ret[0] = ft_strcpy(ret[0], str);
			ret[0] = ft_strcut_end(ret[0], ft_strlen(str) - i);
			ret[1] = ft_strcpy(ret[1], str);
			ret[1] = ft_strtrim(ft_strcut_beg(ret[1], i + 1));
		}
		i++;
	}
	return (ret);
}

static	char	**split_first_word(char *str) {
	char **ret;
	int i;

	ret = NULL;
	i = 0;
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


static	void	get_label(t_env * env)
{
	int i;
	char **tmp;

	env->data = split_label(env->line);
	if (env->data)
	{
		i = -1;
		while(env->data[0][++i])
			if (!ft_is_label_char(env->data[0][i]))
				ft_error(E_BD_LBL);
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
			ft_tab_free(tmp);
		}
	}
	else
		env->data = split_first_word(env->line);
}

static	void	get_instruction(t_env *env)
{
	get_label(env);
	if (env->data)
		inst_switch(env->data);
	else
		ft_error(EBDINST);
	ft_tab_free(env->data);
}

void			parsing_champion(t_env *env) 
{
	ft_putstr("Starting parsing... ");
	get_name(env);
	get_comment(env);
	while(gnl() != 0) {
		get_instruction(env);
	}
	replace_labels(env);
	//print_name_comment(env)	/* ------- NAME_COMMENT ------ */
	print_labels(env); 		/* ------- PRINT LABELS ------ */ 
	print_inst(env);			/* ------ PRINT ALL INST ----- */
	ft_putstr("Parsing done!");
}
