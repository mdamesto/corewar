#include "corewar.h"

int exec_st(unsigned char *mem, int pc, t_process *process)
{
	char arg1[1];
	char arg2[2];

	if (mem[pc + 1] == 0x50)
	{
		ft_putstr("\nmem");
		ft_print_memory(&mem[pc + 3], 1);
		ft_memcpy(arg1, &mem[pc + 2], 1); 
		ft_memcpy(arg2, &mem[pc + 3], 1);
		if ((*arg2 <= 0x10 || *arg1 >= 0x01) && (*arg2 <= 0x10 || *arg1 >= 0x01))
		{
			ft_putstr("\narg1: ");
			ft_putnbr(hatole(arg1, 1));
			ft_putstr("\n");
			ft_print_memory(arg1, 1);
			ft_putstr("\narg2: ");
			ft_putnbr(hatole(arg2, 1));
			ft_putstr("\n");
			ft_print_memory(arg2, 1);

			ft_memcpy(process->reg[hatole(arg2, 1)], process->reg[hatole(arg1, 1)], REG_SIZE);
		}
		else
			return (1);
		process->pc += 4;
	}
	else if(mem[pc + 1] == 0x70)
	{
		ft_memcpy(arg1, &mem[pc + 2], 1);
		ft_memcpy(arg2, &mem[pc + 3], 2);
		if (*arg1 <= 0x10 || *arg1 >= 0x01)
			ft_memcpy(&mem[hatole(arg2, 2) % IDX_MOD], process->reg[hatole(arg1, 1) - 1], REG_SIZE);
		else
			return (1);
		process->pc += 5;
	}
	else 
	{
		process->pc += 2;
		exit(0);
		return (1);
	}
	process->wait_cycle = 5;

	/* ------ REG LD ------ */
	ft_putstr("\n--------- In exec_ld (exec_inst.c) ----------\n");
	ft_putstr("\nprocess->reg[");
	ft_putnbr(hatole(arg1, 1));
	ft_putstr("]: ");
	ft_print_memory(process->reg[hatole(arg1, 1) - 1], REG_SIZE);
	ft_putstr("\nmem[");
	ft_putnbr(hatole(arg2, 2) % IDX_MOD);
	ft_putstr("]: ");
	ft_print_memory(&mem[hatole(arg2, 2) % IDX_MOD], REG_SIZE);
	ft_putstr("process->wait_cycle: ");
	ft_putnbr(process->wait_cycle);
	ft_putstr("\nprocess->pc: ");
	ft_putnbr(process->pc);
	ft_putstr("process->pc: \n");

	exit(0);
	return (0);
}