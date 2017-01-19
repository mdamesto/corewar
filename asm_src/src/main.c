#include "asm.h"

int		main(int argc, char **argv)
{
	t_env *env;

	if (argc == 2) 
	{
		init_env(argv[1]);
		env = get_env(NULL);
		parsing_champion(env);
		create_champion(env);
		ft_putstr("\nHERE------------\n");
	}
	else
		ft_error(EBDARG);
	
	return (0);
}
