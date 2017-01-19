#include "corewar.h"

int exec_live(char *mem, int adress, t_process *process, t_env *env)
{
	char tmp[4];

	ft_memcpy(tmp, &(mem[adress]), 4);
	env->lives[env->lives_nb++] = convert_big_endian(tmp);
	process->wait_cycle = 10;
	process->pc = adress + 4;
}

void	exec_inst(t_process *process, t_env *env)
{
	char *mem
	uint32_t adress; 

	mem = env->mem;
	adress = process->pc;
	if (mem[adress] == 0x01)
		exec_live(mem, adress + 1, process, env);
	else if (mem[adress] == 0x02)
		;
	else if (mem[adress] == 0x02)
		;
	else if (mem[adress] == 0x03)
		;
	else if (mem[adress] == 0x04)
		;
	else if (mem[adress] == 0x05)
		;
	else if (mem[adress] == 0x06)
		;
	else if (mem[adress] == 0x07)
		;
	else if (mem[adress] == 0x08)
		;
	else if (mem[adress] == 0x09)
		;
	else if (mem[adress] == 0x0a)
		;
	else if (mem[adress] == 0x0b)
		;
	else if (mem[adress] == 0x0c)
		;
	else if (mem[adress] == 0x0d)
		;
	else if (mem[adress] == 0x0e)
		;
	else if (mem[adress] == 0x0f)
		;
	else if (mem[adress] == 0x10)
		;
	else
		;
}