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
	//ft_putstr("\n--------- LIVE ----------\n");
	char tmp[4];

	cpy_from_mem(tmp, mem, 4, MMS(pc + 1));
	if (env->lives_nb >= env->lives_tab_size)
	{
		env->lives_tab_size *= 2;
		env->lives = realloc(env->lives, sizeof(int) * env->lives_tab_size);
	}
	env->lives[env->lives_nb++] = hatole(tmp, 4);
	process->wait_cycle = 10;
	INC_PC(5);

	if (env->debug || DBG_LIVE)
		debug_live(tmp);
	
	return (0);
}