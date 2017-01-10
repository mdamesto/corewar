#include "corewar.h"

void	add_inst(char *inst, char *args_code, char **args)
{
	int i;
	t_env *env;

	i = 0;
	env = get_env(NULL);
	if (args_code)
		env->c_adress += 2;
	else
		env->c_adress++;
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

	write(1, "\n", 1);
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
