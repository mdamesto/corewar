#include "corewar.h"

static void	debug_ldi(char **args, int address, t_process *process)
{
	ft_putstr("--------- LDI_LLDI ----------\n");
	/*ft_putstr("args[0]: ");
	ft_putnbr(hatole(args[0], 4));
	ft_print_memory(args[0], 4);
	ft_putstr("args[1]: ");
	ft_putnbr(hatole(args[1], 4));
	ft_print_memory(args[1], 4);*/
	ft_putstr("Copying 4 Bytes from mem[");
	ft_putnbr(address);
	ft_putstr("] to reg[");
	ft_putnbr(GET_REGNB(args[2]));
	ft_putstr("]\n");
	ft_print_memory(process->reg[GET_REGNB(args[2])], 4);
	ft_putstr("\n");
}

int exec_ldi_lldi(unsigned char *mem, int pc, t_process *process)
{
	//ft_putstr("\n--------- LDI_LLDI ----------\n");
	char 		**args;
	int 		tab[2];
	int 		address;
	int			sum;

	INC_PC(2);
	if(args_switch(mem[MMS(pc + 1)], tab, 2))
		return (1);
	if (!(args = get_args(mem, pc, &tab[0], process)))
			return (1);
	cpy_from_mem(args[2], mem, 1, process->pc);
	INC_PC(1);
	if (*args[2] > 0x0f)
	{
		ft_tab_free(args);
		return (1);
	}
	
	sum = hatole(args[0], 4) + hatole(args[1], 4);
	
	if (mem[pc] == 0x0a) 		// 	if ldi
	{
		address = (pc + MODFIX(sum, IDX_MOD)) % MEM_SIZE;
		process->wait_cycle = 25;
	}
	else						//	if lldi
	{
		address = MODFIX(pc + sum, MEM_SIZE);
		process->wait_cycle = 50;
	}
	
 	cpy_from_mem(process->reg[GET_REGNB(args[2])], mem, REG_SIZE, address);
 	
 	GET_REGV(args[2]);
 	if(hatole(args[2], 4) == 0)
 		process->carry = 1;
	else
		process->carry = 0;
	
	if (DBG_INSTS || DBG_LDI)
		debug_ldi(args, address, process);

	ft_tab_free(args);
	return (0);
}