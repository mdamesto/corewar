#include "corewar.h"

static void	debug_live(char *tmp)
{
	ft_putstr("--------- LIVE ----------\n");
	ft_putstr("           ");
	ft_putnbr(hatole(tmp, 4));
	ft_putstr("\n");
}

int exec_live(unsigned char *mem, int pc, t_process *process, t_env *env)
{
	ft_putstr("\n--------- LIVE ----------\n");
	char tmp[4];

	cpy_from_mem(tmp, mem, 4, MMS(pc + 1));
	env->lives[env->lives_nb++] = hatole(tmp, 4);
	process->wait_cycle = 10;
	INC_PC(5);

	if (DBG_INSTS || DBG_LIVE)
		debug_live(tmp);
	return (0);
}