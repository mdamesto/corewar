#include "corewar.h"

void	ft_error(int code) {
	
	t_env *env;

	if (code == 1) {
		ft_putstr_fd("Invalid number of arguments\n", 2);
		exit(code);
	}
	
	env = get_env(NULL);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(env->filename, 2);
	ft_putstr_fd(": ", 2);

	if (code == 2)
		ft_putstr_fd("Could not open the file\n", 2);
	else if (code == 3)
		ft_putstr_fd("Malloc failed\n", 2);
	else if (code == 4)
		ft_putstr_fd("gnl: read error\n", 2);
	else if (code == 5)
		ft_putstr_fd("Empty file\n", 2);
	else if (code == 6)
		ft_putstr_fd("Champion must have a name\n", 2);
	else if (code == 7)
		ft_putstr_fd("Champion must have a comment\n", 2);
	else if (code == 8) {
		ft_putstr_fd("Synthax error on ligne ", 2);
		ft_putstr_fd(ft_itoa(env->lc), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(env->line, 2);
		ft_putstr_fd("\n", 2);
	}
	free_env();
	exit(code);
}