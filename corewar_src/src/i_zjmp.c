#include "corewar.h"

static void	debug_zjmp(int pc, t_process *process)
{
	ft_putstr("\n--------- ZJMP ----------\n");
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
	char arg[4];

	cpy_from_mem(arg, mem, 2, pc + 1);

	if (process->carry == 1)
		INC_PC(MODFIX(INT arg % IDX_MOD, MEM_SIZE));
	else
		INC_PC(3);
	process->wait_cycle = 20;

	t_env *env;
	env = get_env(NULL);

	if (env->debug || DBG_ZJMP)
		debug_zjmp(pc, process);

	process->carry = 0;

	return (0);
}