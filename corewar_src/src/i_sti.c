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
	ft_putnbr(INT args[2] + 1);
	ft_putstr("] to mem[");
	ft_putnbr(MODFIX(address, MEM_SIZE));
	ft_putstr("]\n");
	ft_print_memory(&mem[MODFIX(address, MEM_SIZE)], 4);
	ft_putstr("\n");
}

int exec_sti(unsigned char *mem, int pc, t_process *process)
{
	char 		**args;
	int 		tab[2];
	int 		address;

	INC_PC(2);
	if(args_switch(mem[MMS(pc + 1)], tab, 3))
		return (1);
	if (!(args = get_args(mem, pc, &tab[0], process)))
			return (1);
	cpy_from_mem(args[2], mem, 1, MMS(pc + 2));
	if (*args[2] < 0 || *args[2] > 15)
	{
		ft_tab_free(args);
		return (1);
	}
	
	address = pc + INT args[0] + INT args[1];
	cpy_to_mem(mem, process->reg[INT args[2]], address, process);
	process->wait_cycle = 25;

	
	t_env *env;
	env = get_env(NULL);

	if (env->debug || DBG_STI)
		debug_sti(mem, args, address);
	
	ft_tab_free(args);
	return (0);
}