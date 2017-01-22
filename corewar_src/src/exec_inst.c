#include "corewar.h"

void	exec_inst(t_process *process, t_env *env)
{
	unsigned char *mem;
	uint32_t pc; 

	mem = env->mem;
	pc = process->pc;
	if (mem[pc] == 0x01)
		exec_live(mem, pc, process, env);
	else if (mem[pc] == 0x02)
		exec_ld(mem, pc, process);
	else if (mem[pc] == 0x03)
		exec_st(mem, pc, process);
	else if (mem[pc] == 0x04)
		exec_add_sub(mem, pc, process);
	else if (mem[pc] == 0x05)
		exec_add_sub(mem, pc, process);
	else if (mem[pc] == 0x06)
		exec_and(mem, pc, process);
	else if (mem[pc] == 0x07)
		exec_and(mem, pc, process);
	else if (mem[pc] == 0x08)
		exec_and(mem, pc, process);
	else if (mem[pc] == 0x09)
		;
	else if (mem[pc] == 0x0a)
		;
	else if (mem[pc] == 0x0b)
		;
	else if (mem[pc] == 0x0c)
		;
	else if (mem[pc] == 0x0d)
		;
	else if (mem[pc] == 0x0e)
		;
	else if (mem[pc] == 0x0f)
		;
	else if (mem[pc] == 0x10)
		;
	else
		;
}