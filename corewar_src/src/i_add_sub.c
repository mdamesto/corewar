#include "corewar.h"

static void	debug_add(char **args, int sum)
{
	ft_putstr("\n--------- ADD_SUB ----------\n");
	ft_putstr("process->reg[");
	ft_putnbr(INT args[2] + 1);
	ft_putstr("] = ");
	ft_putnbr(sum);
	ft_putstr(".\n");
}

int exec_add_sub(unsigned char *mem, int pc, t_process *process)
{
	int sum;
	int tab[2];
	char **args;

	INC_PC(2);
	if (mem[MMS(pc + 1)] != 0x54)
		return (1);
	ft_memcpy(tab, "\x01\x00\x00\x00\x01\x00\x00\x00", 8);
	if (!(args = get_args(mem, pc, &tab[0], process)))
		return (1);
	cpy_from_mem(args[2], mem, 1, process->pc);
	INC_PC(1);
	if (*args[2] < 0 || *args[2] > 15)
		return (1);

	if (mem[pc] == 0x04)
		sum = INT args[0] + INT args[1];
	if (mem[pc] == 0x05)
		sum = INT args[0] - INT args[1];
	ft_memcpy(process->reg[INT args[2]], &sum, 4);
	
	process->wait_cycle = 10;
	if (sum == 0)
		process->carry = 1;
	else
		process->carry = 0;

	t_env *env;
	env = get_env(NULL);

	if (env->debug || DBG_ADD)
		debug_add(args, sum);
	return (0);
}