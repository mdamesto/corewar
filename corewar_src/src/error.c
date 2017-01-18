#include "corewar.h"

void	ft_error(int code, char *str) {
	
	//t_env *env;

	ft_putstr_fd("\nError: ", 2);
	if (code == 1)
	{
		if (code == 1) 
			ft_putstr_fd("Malloc failed\n", 2);
		exit(code);
	}

	if (code == 2) 
		ft_putstr_fd("Invalid argument", 2);
	else if (code == 3)
		ft_putstr_fd("Invalid option", 2);
	else if (code == 4)
		ft_putstr_fd("Wrong champion number (2-4)", 2);
	else if (code == 5)
		ft_putstr_fd("Champion muts be .cor files", 2);
	else if (code == 6)
		ft_putstr_fd("Could not open the file", 2);
	else if (code == 6)
		ft_putstr_fd("Invalid champion's op code", 2);
	if (str)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
	}
	ft_putstr_fd("\n", 2);
	free_env();
	exit(code);
}