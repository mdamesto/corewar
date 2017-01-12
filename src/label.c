#include "corewar.h"

void	print_labels(t_env *env)
{
	t_label *tmp;

	ft_putstr("\nLABEL_LST: ");
	if (!env->labels)
		return ; 
	tmp = env->labels;
 	while (tmp->next)
 	{
 		ft_putstr(tmp->name);
 		ft_putstr("(");
 		ft_putstr(ft_itoa(tmp->adress));
 		ft_putstr(")/");
 		tmp = tmp->next;
 	}
 	ft_putstr(tmp->name);
 	ft_putstr("(");
 	ft_putstr(ft_itoa(tmp->adress));
 	ft_putstr(")\n");
}

void	add_label(t_env *env, char *label)
{ 
	t_label *new_label;
	t_label *tmp;
	int i;
	
	i = 0;
	new_label = malloc(sizeof(t_label));
	new_label->next = NULL;
	new_label->name = ft_strnew(ft_strlen(label));
	while (label[i] != ':') {
		new_label->name[i] = label[i];
		i++;
	}
	new_label->adress = env->c_adress;
	if (!env->labels)
		env->labels = new_label;
	else
	{
		tmp = env->labels;
		while (tmp->next) {
			tmp = tmp->next;
		}
		tmp->next = new_label;
	}
}

char 	*get_label_inst(t_label *label,  t_env *env)
{
	t_inst *inst;
	char *content;

	inst = env->inst;
	while (inst->adress != label->adress)
		inst = inst->next;
	content = ft_strnew(4);
	ft_strncpy(content, inst->content, 4);
	return (content);
}

char	*replace_label(char *label_name, int adress, t_env *env)
{
	int dir;
	t_label *tmp;

	dir = 0;
	if (label_name[0] == DIRECT_CHAR)
	{
		dir = ft_atoi(&(label_name[ft_strlen(label_name) - 1]));
		label_name = ft_strcut_beg(ft_strcut_end(label_name, 1), 1);
	}

	tmp = env->labels;
	while(ft_strcmp(tmp->name, label_name) != 0)
	{
		if (!tmp->next)
			ft_error(E_UK_LBL);
		tmp = tmp->next;
	}
	free(label_name);
	if (dir) 
		return (convert_hex_octnb(tmp->adress - adress, dir));
	else
	{
		return (get_label_inst(tmp, env));
	}
}

void 	replace_labels(t_env *env) {
	t_inst *tmp;
	char **split;

	// first handle dir labels
	tmp = env->inst;
	while (tmp) 
	{
		split = ft_strsplit(tmp->content, LABEL_CHAR);
		if (split[1] && split[1][0] == DIRECT_CHAR)
		{
			split[1] = replace_label(split[1], tmp->adress, env);
			tmp->content = ft_tab_join(split);
		}
		else
			tmp = tmp->next;
		ft_tab_free(split);
	}
	// 2nd time to handle ind label
	tmp = env->inst;
	while (tmp) 
	{
		split = ft_strsplit(tmp->content, LABEL_CHAR);
		if (split[1])
		{
			split[1] = replace_label(split[1], tmp->adress, env);
			tmp->content = ft_tab_join(split);
		}
		else
			tmp = tmp->next;
		ft_tab_free(split);
	}

}

