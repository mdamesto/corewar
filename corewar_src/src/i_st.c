#include "corewar.h"

static void	debug_st(unsigned char *mem, char *arg0, char *arg1, int pc)
{
	ft_putstr("--------- ST ----------\n");
	ft_putstr("Copying reg[");
	ft_putnbr(INT arg0 + 1);
	ft_putstr("]: to ");
	if (mem[MMS(pc + 1)] == 0x50)
	{
		ft_putstr("\nreg[");
		ft_putnbr(INT arg1);
		ft_putstr("].");
	}
	else
	{
		ft_putstr("\n mem[");
		ft_putnbr(MODFIX(pc + (INT arg1 % IDX_MOD), MEM_SIZE));
		ft_putstr("].");
	}
	ft_putstr("\n");
}

int exec_st(unsigned char *mem, int pc, t_process *process)
{
	char arg0[4];
	char arg1[4];

	cpy_from_mem(arg0, mem, 1, pc + 2);
	if (*arg0 < 0 || *arg0 > 15)
		return (1);

	if (mem[MMS(pc + 1)] == 0x50) //if arg1 is reg (1B)
	{
		cpy_from_mem(arg1, mem, 1, pc + 3);
		if (*arg1 < 0 || *arg1 > 15)
			return (1);
		ft_print_memory(arg1, 4);
		ft_memcpy(process->reg[INT arg1], process->reg[INT arg0], REG_SIZE);
		INC_PC(4);
	}
	else if(mem[MMS(pc + 1)] == 0x70) //if arg1 is Ind (2B)
	{
		cpy_from_mem(arg1, mem, 2, pc + 3);
		cpy_to_mem(mem, process->reg[INT arg0], pc + (INT arg1 % IDX_MOD), process);
		INC_PC(5);
	}
	else
	{
		INC_PC(1); 
		return (1);
	}
	
	process->wait_cycle = 5;

	t_env *env;
	env = get_env(NULL);

	if (env->debug || DBG_ST)
		if (pc == 602 || pc == 607)
		{
			debug_st(mem, arg0, arg1, pc);
			//ft_print_memory(process->reg[INT arg0], 4);
		}
	return (0);
}