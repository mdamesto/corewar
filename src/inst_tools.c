#include "corewar.h"

char 	*get_full_inst(char *inst, char *args_code, char **args)
{
	int i;
	char *full_inst;
	
	i = 0;
	full_inst = args[i];
	while (args[i + 1]) 
	{
		full_inst = ft_strjoin(full_inst, args[i + 1]);
		i++;
	}
	if(args_code)
		full_inst = ft_strjoin(ft_strjoin(inst, args_code), full_inst);
	else
		full_inst = ft_strjoin(inst, full_inst);

	return(full_inst);
}

t_inst	*new_inst(t_env *env, char *inst)
{
	t_inst *new;

	new = malloc(sizeof(t_inst));
	new->content = inst;
	new->adress = env->c_adress;
	new->line = env->line_nb;

	return (new);
}

void	inst_to_env(t_env *env, char *inst)
{
	t_inst *new;
	t_inst *tmp;

	new = new_inst(env, inst);
	if (!(env->inst)) {
		env->inst = new;
	}
	else
	{
		tmp = env->inst;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	add_inst(char *inst, char *args_code, char **args)
{
	t_env *env;
	char *full_inst;

	env = get_env(NULL);
	if (args_code)
		env->add_to_adress += 2;
	else
		env->add_to_adress++;
	
	full_inst = get_full_inst(inst, args_code, args);
	
	inst_to_env(env, full_inst);

	env->c_adress += env->add_to_adress;
	env->add_to_adress = 0;

	// ------- PRINT INST+ARGS ------ //
	/*i = 0;
	ft_putstr("\ninst: ");
	ft_putstr(inst);
	if(args_code)
	{
		ft_putstr("\nargs_code: ");
		ft_putstr(args_code);
	}
	ft_putstr("\n");
	while (args[i]) {
		ft_putstr("arg[");
		ft_putstr(ft_itoa(i));
		ft_putstr("]: ");
		ft_putstr(args[i++]);
		ft_putstr("  ");
	}
	write(1, "\n", 1);*/
	// ------------------------------- // 
}

char	*ret_to_oct(char *tmp, int oct_nb) 
{
	int i;
	char *ret;
	int ret_len;
	int tmp_len;

	ret_len = (oct_nb * 2);
	ret = ft_strnew(ret_len);
	i = 0;
	while (i < ret_len)
		ret[i++] = '0';
	tmp_len = ft_strlen(tmp);

	i = 0;
	ret_len = ret_len - tmp_len;
	while ( i < tmp_len) {
		ret[ret_len + i] = tmp[i];
		i++;
	}
	return (ret);
}

char	**init_args(void) 
{
	char **args;
	int i;

	args = malloc(sizeof(char*) * 4);
	i = 0;
	while (i < 4)
		args[i++] = NULL;
	return (args);
}

void	print_inst(t_env *env)
{
	t_inst *tmp;

	ft_putstr("\n\nINSTRUCTIONS:\n");
	tmp = env->inst;
	while (tmp->next)
	{
		ft_putstr(tmp->content);
		ft_putstr("\n");
		tmp = tmp->next;
	}
	ft_putstr(tmp->content);
	ft_putstr("\n");
}
