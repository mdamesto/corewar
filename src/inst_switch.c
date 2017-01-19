#include "asm.h"

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

static void norme1(char **data)
{
	if(!(ft_strcmp(data[0], "fork")))
		live_zjump_fork_lfork(data[1], "0c", 2);
	else if(!(ft_strcmp(data[0], "lld")))
		ld_lld_and(data[1], "0d");
	else if(!(ft_strcmp(data[0], "lddi")))
		ldi_lldi(data[1], "0e");
	else if(!(ft_strcmp(data[0], "lfork")))
		live_zjump_fork_lfork(data[1], "0f", 2);
	else if(!(ft_strcmp(data[0], "aff")))
		aff(data[1], "10");
	else 
	{
		ft_putstr("\n HERE: ");
		ft_putstr(data[0]);
		ft_error(EBDINST);
	}
}

void	inst_switch(char **data)
{
	if(!(ft_strcmp(data[0], "live")))
		live_zjump_fork_lfork(data[1], "01", 4);
	else if(!(ft_strcmp(data[0], "ld")))
		ld_lld_and(data[1], "02");
	else if(!(ft_strcmp(data[0], "st")))
		st(data[1], "03");
	else if(!(ft_strcmp(data[0], "add")))
		add_sub(data[1], "04");
	else if(!(ft_strcmp(data[0], "sub")))
		add_sub(data[1], "05");
	else if(!(ft_strcmp(data[0], "and")))
		ld_lld_and(data[1], "06");
	else if(!(ft_strcmp(data[0], "or")))
		or_xor(data[1], "07");
	else if(!(ft_strcmp(data[0], "xor")))
		or_xor(data[1], "08");
	else if(!(ft_strcmp(data[0], "zjmp")))
		live_zjump_fork_lfork(data[1], "09", 2);
	else if(!(ft_strcmp(data[0], "ldi")))
		ldi_lldi(data[1], "0a");
	else if(!(ft_strcmp(data[0], "sti")))
		sti(data[1], "0b");
	else
		norme1(data);
}