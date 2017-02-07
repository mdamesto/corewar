#include "corewar.h"

static void	debug_or(char **args, int sum)
{
	ft_putstr("\n--------- AND_OR_XOR ----------\n");
	ft_print_memory(args[0], 4);
	ft_print_memory(args[1], 4);
	ft_print_memory(&sum, 4);
	ft_putstr("Copying sum: ");
	ft_putnbr(sum);
	ft_putstr(" to reg[");
	ft_putnbr(INT args[2] + 1);
	ft_putstr("].\n");
}

int exec_and_or_xor(unsigned char *mem, int pc, t_process *process)
{
	char 		**args;
	int			sum;
	int 		tab[2];

	INC_PC(2);

	if(args_switch(mem[MMS(pc + 1)], tab, 1))
		return (1);
	if (!(args = get_args(mem, pc, tab, process)))
			return (1);
	
	cpy_from_mem(args[2], mem, 1, process->pc);
	INC_PC(1);
	if (*args[2] < 0 || *args[2] > 15)
	{
		ft_tab_free(args);
		return (1);
	}

	if (mem[pc] == 0x06) 							//	if and
		sum = INT args[0] & INT args[1];
	else if (mem[pc] == 0x07) 						//	if or
		sum = INT args[0] | INT args[1];
	else 											// 	if xor
		sum = INT args[0] ^ INT args[1];

	ft_memcpy(process->reg[INT args[2]], &sum, 4);
	
	process->wait_cycle = 6;
	if (sum == 0)
		process->carry = 1;
	else
		process->carry = 0;
	
	t_env *env;
	env = get_env(NULL);

	if (env->debug || DBG_OR)
		debug_or(args, sum);
	
	ft_tab_free(args);
	return (0);
}