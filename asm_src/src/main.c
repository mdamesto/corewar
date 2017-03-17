#include "asm.h"

int		main(int argc, char **argv)
{
	t_env *env;

	//DO LOOP TO ASM MULTIPLE CHAMPIONS IN ONE CALL 
	if (argc == 2) 
	{
		init_env(argv[1]);
		env = get_env(NULL);
		parsing_champion(env);
		create_champion(env);
	}
	else
		ft_error(EBDARG);
	
	return (0);
}
