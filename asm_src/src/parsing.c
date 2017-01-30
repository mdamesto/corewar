#include "asm.h"

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
	char *label;

	i = -1;
	label = NULL;
	while (env->line[++i] && env->line[i] != ' ' && env->line[i] != '	' && env->line[i] != LABEL_CHAR)
			ft_putnbr(i);
	if (i == 0)
	{
		if (env->line[i])
			ft_error(E_BD_LBL);
		else
			return ;
	}
	if (env->line[i] == LABEL_CHAR)
		label = ft_strtrim(ft_strget(env->line, 0, i));
	else
		env->data = split_first_word(env->line);
	if (label)
	{
		i = -1;
		while(label[++i])
			if (!ft_is_label_char(label[i]))
				ft_error(E_BD_LBL);
		add_label(env, label);
		env->line = ft_strcut_f(env->line, 0, ft_strlen(label) + 1);
		if (check_empty_line(env->line))
			gnl();
		get_label(env);
	}

}

static	void	get_instruction(t_env *env)
{
	get_label(env);
	if (*(env->data))
		inst_switch(env->data);
}

void			parsing_champion(t_env *env) 
{
	ft_putstr("Starting parsing... ");
	get_name(env);
	get_comment(env);
	while(gnl() != 0) 
		get_instruction(env);
	replace_labels(env);
	//print_name_comment(env)	/* ------- NAME_COMMENT ------ */
	print_labels(env); 		/* ------- PRINT LABELS ------ */ 
	print_inst(env);			/* ------ PRINT ALL INST ----- */
	ft_putstr("Parsing done!");
}
