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

/*void	replace_label(char **tab)
{
	char	*label;
	int 	dir;
	t_label	*tmp; 

	label = tab[1];
	dir = 0;
	
	if (label[0] == '%')
	{
		label = ft_strcut_beg(label, 1);
		dir = ft_atoi(label[ft_strlen(label - 1)]);
		label = ft_strncpy(labl, label, ft_strlen(label - 1));
	}

	tmp = env->labels;
	while (ft_strcmp(tmp->name, label))
	{
		if (tmp->next = NULL)
			ft_error(E_UK_LBL);
		tmp = tmp->next;
	}

	if (dir > 0)
		label = ret_to_oct(ft_itoa_base(ft_atoi(tmp->adress), 2), dir);
	else
	{

	}
}*/

void 	replace_labels(t_env *env) {
	t_env *tmp;
	tmp = env;
	/*char **tab;
	int i;

	i = 1;
	while (env->inst[i])
	{
		tab = ft_strsplit(env->inst[i], ':');
		if (tab[1])
		{
			ft_putstr("\nLABEL line: ");
			ft_putstr(ft_itoa(i));
			ft_putstr(" -- ");
			ft_putstr(tab[1]);
		}
		i++;
		ft_tab_free(tab);
	}*/
}