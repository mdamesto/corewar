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
	env->c_adress++;
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

char	*replace_label(char **split, int adress, t_env *env)
{
	char *label_name;
	int dir;
	t_label *tmp;
	int i;

	label_name = split[1];
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

	if (dir) {
		ft_putstr("\n SPLIT[1]:");
		ft_putstr("\ntmp->adress - adress: ");
		ft_putstr(ft_itoa(tmp->adress - adress));
		ft_putstr("\nreturn from itoa base: ");
		ft_putstr(ft_itoa_base(tmp->adress - adress, 2));

		split[1] = ret_to_oct(ft_itoa_base((tmp->adress - adress), 2), dir);
		ft_putstr("\nsplit[1]: ");
		ft_putstr(split[1]);


		//CONVERT TO 11111111 for -1
	}
	
	i = 1;
	while(split[i])
		split[0] = ft_strjoin(split[0], split[i++]);

	return (split[0]);
}

void 	replace_labels(t_env *env) {
	t_inst *tmp;
	char **split;

	tmp = env->inst;
	while (tmp) 
	{
		split = ft_strsplit(tmp->content, LABEL_CHAR);
		if (split[1])
		{
			tmp->content = replace_label(split, tmp->adress, env);

		}
		else
			tmp = tmp->next;
		ft_tab_free(split);
	}
}

