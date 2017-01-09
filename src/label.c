#include "corewar.h"

void	print_labels(t_env *env)
{
	t_label *tmp;

	ft_putstr("LABEL_LST: ");
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