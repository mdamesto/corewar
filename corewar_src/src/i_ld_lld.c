#include "corewar.h"

static void	debug_ld(char *arg0, char *arg1)
{
	ft_putstr("\n--------- LD_LLD ----------\n");
	ft_putstr("loaded: ");
	ft_putnbr(INT arg0);
	ft_putstr("\n");
	ft_putstr("to reg nb: ");
	ft_putnbr((INT arg1) + 1);
	ft_putstr("\n");
}

int exec_ld_lld(unsigned char *mem, int pc, t_process *process)
{
	int address;
	char arg0[4];
	char arg1[4];

	INC_PC(2);
	if (mem[MMS(pc + 1)] == 0x90) //if arg0 is DIR (4B)
	{
		cpy_from_mem(arg0, mem, REG_SIZE, pc + 2);
		INC_PC(4);

	}
	else if(mem[MMS(pc + 1)] == 0xd0) //if arg0 is Ind (2B)
	{
		cpy_from_mem(arg0, mem, 2, pc + 2);
		address = pc + INT arg0;
		if (mem[pc] == 0x02) //if op is ld (IDX_MOD)
			address = pc + INT arg0 % IDX_MOD;
		cpy_from_mem(arg0, mem, REG_SIZE, address);
		INC_PC(2);
	}
	else
		return (1);
	
	process->wait_cycle = 10;
	if (mem[pc] == 0x02)
		process->wait_cycle = 5;

	cpy_from_mem(arg1, mem, 1, process->pc);
	INC_PC(1);
	if (arg1[0] < 0 || arg1[0] > 15)
		return (1);
	
	ft_memcpy(process->reg[INT arg1], arg0, REG_SIZE);
	
	if (INT arg0 == 0)
		process->carry = 1;
	else
		process->carry = 0;
	
	t_env *env;
	env = get_env(NULL);

	if(env->debug || DBG_LD)
		debug_ld(arg0, arg1);
	
	return (0);
}