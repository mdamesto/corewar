#include "corewar.h"

int exec_aff(unsigned char *mem, int pc, t_process *process)
{
	ft_putstr("--------- In exec_aff (exec_inst.c) ----------\n");
	char arg[4];
	int c;

	if (mem[pc + 1] != 0x40)
	{
		process->pc += 2;
		return (1);
	}
	ft_memcpy(arg, &mem[pc + 2], 1);
	ft_memcpy(arg, process->reg[GET_REGNB(arg)], 4);
	c = MODFIX(hatole(arg, 4), 256);
	
	// DEBUG
	ft_putstr("char: ");
	ft_putnbr(c);
	ft_putstr("\n");
	ft_print_memory(&c, 4);
	ft_putstr("aff output: ");

	write(1, &c, 1);
	process->pc += 3;
	return (0);
}