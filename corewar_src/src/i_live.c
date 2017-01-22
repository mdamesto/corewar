#include "corewar.h"

int exec_live(unsigned char *mem, int pc, t_process *process, t_env *env)
{
	char tmp[4];

	ft_memcpy(tmp, &(mem[pc + 1]), 4);
	env->lives[env->lives_nb++] = hatole(tmp, 4);
	process->wait_cycle = 10;
	process->pc = pc + 5;
	
	exit(0);
	return (0);
}