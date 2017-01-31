#include "corewar.h"

static void	debug_sti(unsigned char *mem, char **args, int address)
{
	ft_putstr("--------- STI ----------\n");
	/*ft_putstr("args[0]: ");
	ft_putnbr(hatole(args[0], 4));
	ft_print_memory(args[0], 4);
	ft_putstr("args[1]: ");
	ft_putnbr(hatole(args[1], 4));
	ft_print_memory(args[1], 4);*/
	ft_putstr("Copying 4 Bytes from reg[");
	ft_putnbr(hatole(args[2], 1));
	ft_putstr("] to mem[");
	ft_putnbr(address);
	ft_putstr("]\n");
	ft_print_memory(&mem[address], 4);
	ft_putstr("\n");
}

int exec_sti(unsigned char *mem, int pc, t_process *process)
{
	//ft_putstr("\n--------- STI ----------\n");
	char 		**args;
	int 		tab[2];
	int			sum;
	int 		address;

	INC_PC(2);
	if(args_switch(mem[MMS(pc + 1)], tab, 3))
		return (1);
	if (!(args = get_args(mem, pc, &tab[0], process)))
			return (1);
	cpy_from_mem(args[2], mem, 1, MMS(pc + 2));
	if (*args[2] > 0x0f)
	{
		ft_tab_free(args);
		return (1);
	}
	
	sum = hatole(args[0], 4) + hatole(args[1], 4);
	address = MMS((pc + MODFIX(sum, IDX_MOD)));
	process->wait_cycle = 25;
	cpy_to_mem(mem, process->reg[GET_REGNB(args[2])], REG_SIZE, address);
	
	if (DBG_INSTS || DBG_STI)
		debug_sti(mem, args, address);
	
	ft_tab_free(args);
	return (0);
}