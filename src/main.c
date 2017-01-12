#include "corewar.h"

void	create_champion(t_env *env)
{
	int fd_cor;
	char *magic;

	fd_cor = open ("champion.cor", O_RDWR | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH);
	magic = convert_hex_octnb(env->header->magic, 4);
	ft_putstr(magic);
	write(fd_cor, magic, ft_strlen(magic));
	write(fd_cor, "next", 4);


}


int		main(int argc, char **argv)
{
	t_env *env;

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
