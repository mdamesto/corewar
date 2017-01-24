#include "corewar.h"

int	exec_inst(t_process *process, t_env *env)
{
	unsigned char *mem;
	uint32_t pc; 

	mem = env->mem;
	pc = process->pc;
	if (mem[pc] == 0x01)
		exec_live(mem, pc, process, env);
	else if (mem[pc] == 0x02)
		exec_ld_lld(mem, pc, process);
	else if (mem[pc] == 0x03)
		exec_st(mem, pc, process);
	else if (mem[pc] == 0x04)
		exec_add_sub(mem, pc, process);
	else if (mem[pc] == 0x05)
		exec_add_sub(mem, pc, process);
	else if (mem[pc] == 0x06)
		exec_and_or_xor(mem, pc, process);
	else if (mem[pc] == 0x07)
		exec_and_or_xor(mem, pc, process);
	else if (mem[pc] == 0x08)
		exec_and_or_xor(mem, pc, process);
	else if (mem[pc] == 0x09)
		exec_zjmp(mem, pc, process);
	else if (mem[pc] == 0x0a)
		exec_ldi_lldi(mem, pc, process);
	else if (mem[pc] == 0x0b)
		exec_sti(mem, pc, process);
	else if (mem[pc] == 0x0c)
		return (1);
	else if (mem[pc] == 0x0d)
		exec_ld_lld(mem, pc, process);
	else if (mem[pc] == 0x0e)
		exec_ldi_lldi(mem, pc, process);
	else if (mem[pc] == 0x0f)
		return (1);
	else if (mem[pc] == 0x10)
		exec_aff(mem, pc, process);
	else 
		process->pc++;
	return (0);
}