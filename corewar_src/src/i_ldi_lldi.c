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
	ft_putnbr(INT args[2] + 1);
	ft_putstr("]\n");
	ft_print_memory(process->reg[INT args[2]], 4);
	ft_putstr("\n");
}

int exec_ldi_lldi(unsigned char *mem, int pc, t_process *process)
{
	//TO TEST !!!!!!!
	char 		**args;
	int 		tab[2];
	int 		address;

	INC_PC(2);
	if(args_switch(mem[MMS(pc + 1)], tab, 2))
		return (1);
	if (!(args = get_args(mem, pc, &tab[0], process)))
			return (1);
	cpy_from_mem(args[2], mem, 1, process->pc);
	INC_PC(1);
	if (*args[2] < 0 || *args[2] > 15)
	{
		ft_tab_free(args);
		return (1);
	}

	address = pc + INT args[0] + INT args[1];
	process->wait_cycle = 50;
	if (mem[pc] == 0x0a)
	{
		address = pc + (INT args[0] + INT args[1]) % IDX_MOD;
		process->wait_cycle = 25;
	}
	
 	cpy_from_mem(process->reg[INT args[2]], mem, REG_SIZE, address);
 	
 	if(INT process->reg[INT args[2]] == 0)
 		process->carry = 1;
 	else
		process->carry = 0;

 	t_env *env;
	env = get_env(NULL);
 	if (env->debug || DBG_LDI)
		debug_ldi(args, address, process);

	ft_tab_free(args);
	return (0);
}