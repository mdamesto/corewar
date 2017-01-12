#include "corewar.h"

void	ft_error(int code) {
	
	t_env *env;

	if (code == 1 || code == 2 || code == 3)
	{
		if (code == 1) 
			ft_putstr_fd("Invalid number of arguments\n", 2);
		else if (code == 2)
			ft_putstr_fd("Could not open the file\n", 2);
		else if (code == 3)
			ft_putstr_fd("Malloc failed\n", 2);
		exit(code);
	}
	
	env = get_env(NULL);
	ft_putstr_fd("\nError: ", 2);
	ft_putstr_fd(env->filename, 2);
	ft_putstr_fd(": ", 2);

	if (code == 4)
		ft_putstr_fd("gnl: read error\n", 2);
	else if (code == 5)
		ft_putstr_fd("Empty file\n", 2);
	else if (code == 6)
		ft_putstr_fd("Champion must have a name\n", 2);
	else if (code == 7)
		ft_putstr_fd("Champion must have a comment\n", 2);
	else if (code == 8) {
		ft_putstr_fd("Synthax error on line ", 2);
		ft_putstr_fd(ft_itoa(env->line_nb), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(env->line, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (code == 9) {
		ft_putstr_fd("Invalid instruction on line ", 2);
		ft_putstr_fd(ft_itoa(env->line_nb), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(env->line, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (code == 10) {
		ft_putstr_fd("Wrong number of args for instruction on line ", 2);
		ft_putstr_fd(ft_itoa(env->line_nb), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(env->line, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (code == 11) {
		ft_putstr_fd("Unknow registre on line ", 2);
		ft_putstr_fd(ft_itoa(env->line_nb), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(env->line, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (code == 12) {
		ft_putstr_fd("Wrong arg on line ", 2);
		ft_putstr_fd(ft_itoa(env->line_nb), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(env->line, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (code == 13) {
		ft_putstr_fd("Wrong Direct value on line ", 2);
		ft_putstr_fd(ft_itoa(env->line_nb), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(env->line, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (code == 14) {
		ft_putstr_fd("Wrong Indirect value on line ", 2);
		ft_putstr_fd(ft_itoa(env->line_nb), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(env->line, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (code == 15) {
		ft_putstr_fd("Unknow label\n", 2);
		//maybe add param to ft_error for 2nd parsing errors txt
	}
	free_env();
	exit(code);
}