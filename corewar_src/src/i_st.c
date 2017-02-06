#include "corewar.h"

static void	debug_st(unsigned char *mem, char *arg0, char *arg1, int pc)
{
	ft_putstr("--------- ST ----------\n");
	ft_putstr("Copying reg[");
	ft_putnbr(GET_REGNB(arg0) + 1);
	ft_putstr("]: to ");
	if (mem[MMS(pc + 1)] == 0x50)
	{
		ft_putstr("\nreg[");
		ft_putnbr(GET_REGNB(arg1));
		ft_putstr("].");
	}
	else
	{
		ft_putstr("\n mem[");
		ft_putnbr(MODFIX(pc + (*(int*)arg1 % IDX_MOD), MEM_SIZE));
		ft_putstr("].");
	}
	ft_putstr("\n");
}

int exec_st(unsigned char *mem, int pc, t_process *process)
{
	char arg0[1];
	char arg1[4];


	cpy_from_mem(arg0, mem, 1, MMS(pc + 2));
	if (*arg0 < 1 || *arg0 > 16)
		return (1);

	if (mem[MMS(pc + 1)] == 0x50) //if arg1 is reg (1B)
	{
		cpy_from_mem(arg1, mem, 1, MMS(pc + 3));
		if (*arg1 < 1 || *arg1 > 16)
			return (1);
		ft_memcpy(process->reg[GET_REGNB(arg1)], process->reg[GET_REGNB(arg0)], REG_SIZE);
		INC_PC(4);
	}
	else if(mem[MMS(pc + 1)] == 0x70) //if arg1 is Ind (2B)
	{
		ft_putstr("\nHERE: ");
		ft_print_memory(process->reg[GET_REGNB(arg0)], 4);
		cpy_from_mem(arg1, mem, 2, MMS(pc + 3));
		cpy_to_mem(mem, process->reg[GET_REGNB(arg0)], REG_SIZE, MODFIX(pc + (*(int*)arg1 % IDX_MOD), MEM_SIZE));
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
		debug_st(mem, arg0, arg1, pc);

	return (0);
}