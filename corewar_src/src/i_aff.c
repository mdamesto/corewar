#include "corewar.h"

static void	debug_aff(char c)
{
	ft_putstr("--------- AFF ----------\n");
	ft_putstr("aff output: ");
	ft_putnbr(c);
	ft_putstr("\n");
	ft_print_memory(&c, 1);
}


int exec_aff(unsigned char *mem, int pc, t_process *process)
{
	char arg[4];
	int c;

	INC_PC(2);
	if (mem[MMS(pc + 1)] != 0x40)
		return (1);
	cpy_from_mem(arg, mem, 1, pc + 2);
	INC_PC(1);
	if (*arg < 0 || *arg > 15)
		return (1);
	ft_memcpy(arg, process->reg[INT arg], 4);
	c = MODFIX(INT arg, 256);
	write(1, &c, 1);

	process->wait_cycle = 2;
	t_env *env;
	env = get_env(NULL);

	if (env->debug || DBG_AFF)
		debug_aff(c);
	
	return (0);
}