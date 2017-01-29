#include "corewar.h"

static void	debug_or(char **args, int sum)
{
	ft_print_memory(args[0], 4);
	ft_print_memory(args[1], 4);
	ft_print_memory(&sum, 4);
	ft_putstr("Copying sum: ");
	ft_putnbr(revert_endian(sum));
	ft_putstr(" to reg[");
	ft_putnbr(hatole(args[2], 1));
	ft_putstr("].\n");
}

int exec_and_or_xor(unsigned char *mem, int pc, t_process *process)
{
	//ft_putstr("\n--------- AND_OR_XOR ----------\n");
	char 		**args;
	uint32_t	sum;
	int 		tab[2];

	INC_PC(2);

	if(args_switch(mem[MMS(pc + 1)], tab, 1))
		return (1);

	if (!(args = get_args(mem, MMS(pc + 2), tab, process)))
			return (1);
	
	cpy_from_mem(args[2], mem, 1, MMS(process->pc));
	INC_PC(1);
	if (*args[2] > 0x0f)
		return (1);

	if (mem[pc] == 0x06) 							//	if and
		sum = *(int*)args[0] & *(int*)args[1];
	else if (mem[pc] == 0x07) 						//	if or
		sum = *(int*)args[0] | *(int*)args[1];
	else 											// 	if xor
		sum = *(int*)args[0] ^ *(int*)args[1];

	ft_memcpy(process->reg[GET_REGNB(args[2])], &sum, REG_SIZE);
	process->wait_cycle = 6;
	
	if (sum == 0)
		process->carry = 1;
	else
		process->carry = 0;
	
	if (DBG_INSTS || DBG_OR)
		debug_or(args, sum);
	return (0);
}