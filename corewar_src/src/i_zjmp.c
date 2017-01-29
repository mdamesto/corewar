#include "corewar.h"

static void	debug_zjmp(int pc, t_process *process)
{
	if(process->carry)
	{
		ft_putstr("Zjmp from ");
		ft_putnbr(pc);
		ft_putstr(" to ");
		ft_putnbr(process->pc);
		ft_putstr(".\n");
	}
}

int exec_zjmp(unsigned char *mem, int pc, t_process *process)
{
	
	//ft_putstr("\n--------- ZJMP ----------\n");
	char arg[2];

	ft_memcpy(arg, &mem[pc + 1], 2);
	revert_bytes(arg, 2);

	if (process->carry == 1)
		INC_PC(MODFIX(*(short int*)arg % IDX_MOD, MEM_SIZE));
	else
		INC_PC(3);
	process->wait_cycle = 20;

	if (DBG_INSTS || DBG_ZJMP)
		debug_zjmp(pc, process);
	return (0);
}