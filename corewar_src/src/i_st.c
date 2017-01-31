#include "corewar.h"

static void	debug_st(unsigned char *mem, char *arg0, char *arg1, int pc)
{
	ft_putstr("--------- ST ----------\n");
	ft_putstr("Copying reg[");
	ft_putnbr(GET_REGNB(arg0));
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
		ft_putnbr(MMS(pc + MODFIX(hatole(arg1, 2), IDX_MOD)));
		ft_putstr("].");
	}
	ft_putstr("\n");
}

int exec_st(unsigned char *mem, int pc, t_process *process)
{
	//ft_putstr("\n--------- ST ----------\n");
	char arg0[1];
	char arg1[2];

	INC_PC(2);
	cpy_from_mem(arg0, mem, 1, MMS(pc + 2));
	if (mem[MMS(pc + 1)] == 0x50) //if arg1 is reg (1B)
	{
		cpy_from_mem(arg1, mem, 1, MMS(pc + 3));
		INC_PC(2);
		if (*arg0 > 0x0f && *arg1 > 0x0f)
			return (1);
		ft_memcpy(process->reg[GET_REGNB(arg1)], process->reg[GET_REGNB(arg0)], REG_SIZE);
	}
	else if(mem[MMS(pc + 1)] == 0x70) //if arg1 is Ind (2B)
	{
		cpy_from_mem(arg1, mem, 2, MMS(pc + 3));
		INC_PC(3);
		if (*arg0 > 0x0f)
			return (1);
		ft_memcpy(&mem[MMS(pc + MODFIX(hatole(arg1, 2), IDX_MOD))], process->reg[GET_REGNB(arg0)], REG_SIZE);
	}
	else 
		return (1);
	process->wait_cycle = 5;

	if (DBG_INSTS || DBG_ST)
		debug_st(mem, arg0, arg1, pc);

	return (0);
}