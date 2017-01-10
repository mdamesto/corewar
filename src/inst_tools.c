#include "corewar.h"

void	add_inst(char *inst, char *args_code, char **args)
{
	int i;
	t_env *env;
	char *full_inst;

	i = 0;
	env = get_env(NULL);
	if (args_code)
		env->c_adress += 2;
	else
		env->c_adress++;
	
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
	env->inst[env->inst_nb] = full_inst;
	env->inst_nb++;

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

	ret_len = (oct_nb * 8);
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
	int i;

	i = 1;
	while (i < env->inst_nb)
	{
		ft_putstr(env->inst[i]);
		ft_putstr("\n");
		i++;
	}
}
