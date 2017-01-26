#include "corewar.h"

static void	debug_add(char **args, int i)
{
	ft_putstr("process->reg[");
	ft_putnbr(hatole(args[2], 1));
	ft_putstr("] = ");
	ft_putnbr(i);
	ft_putstr(".\n");
}

int exec_add_sub(unsigned char *mem, int pc, t_process *process)
{
	ft_putstr("\n--------- ADD_SUB ----------\n");
	int i;

	int tab[2];
	char **args;

	INC_PC(2);
	if (mem[MMS(pc + 1)] != 0x54)
		return (1);
	ft_memcpy(tab, "\x01\x00\x00\x00\x01\x00\x00\x00", 8);
	if (!(args = get_args(mem, pc + 2, &tab[0], process)))
		return (1);
	cpy_from_mem(args[2],mem, 1, process->pc);
	INC_PC(1);
	if (*args[2] > 0x0f)
		return (1);
	
	if (mem[pc] == 0x04)
		i = revert_endian(hatole(args[0], 4) + hatole(args[1], 4));
	if (mem[pc] == 0x05)
		i = revert_endian(hatole(args[0], 4) - hatole(args[1], 4));
	
	ft_memcpy(process->reg[GET_REGNB(args[2])], &(i), REG_SIZE);
	process->wait_cycle = 10;
	INV_CARRY;
	
	if (DBG_INSTS || DBG_ADD)
		debug_add(args, revert_endian(i));
	return (0);
}