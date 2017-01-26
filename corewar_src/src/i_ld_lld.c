#include "corewar.h"

static void	debug_ld(unsigned char *mem, char *arg1, int address, t_process *process)
{
	if (address != -1)
	{
		ft_putstr("adress: ");
		ft_putnbr(address);
		ft_putstr("\n");
		ft_print_memory(&mem[address], 4);
		ft_putstr("\n");
	}
	ft_putstr("reg nb: ");
	ft_putnbr(hatole(arg1, 1));
	ft_putstr("\n");
	ft_print_memory(process->reg[GET_REGNB(arg1)], 4);
}

int exec_ld_lld(unsigned char *mem, int pc, t_process *process)
{
	ft_putstr("\n--------- LD_LLD ----------\n");
	//-------------------------- TODO (clean it)
	int address;
	int wait;
	char arg0[4];
	char arg1[1];

	address = -1;
	wait = 0;

	INC_PC(2);
	if (mem[MMS(pc + 1)] == 0x90) //if arg0 is DIR (4B)
	{
		cpy_from_mem(arg0, mem, 4, MMS(pc + 2));
		INC_PC(4);
	}
	else if(mem[MMS(pc + 1)] == 0xd0)
	{
		cpy_from_mem(arg0, mem, 2, MMS(pc + 2)); //if arg0 is Ind (2B)
		revert_bytes(arg0, 2);
		if (mem[pc] == 0x02) //if op is ld (IDX_MOD)
		{
			address = MODFIX(pc + *(short int*)arg0 % IDX_MOD, MEM_SIZE);
			wait = 5;
		}
		else //if op is lld
		{
			address = MODFIX(pc + *(short int*)arg0, MEM_SIZE);
			wait = 10;
		}
		cpy_from_mem(arg0, mem, REG_SIZE, address);
		INC_PC(2);
	}
	else
		return (1);
	
	cpy_from_mem(arg1, mem, 1, process->pc);
	INC_PC(1);
	if (arg1[0] > 0x0f)
		return (1);

	ft_memcpy(process->reg[GET_REGNB(arg1)], arg0, REG_SIZE);
	process->wait_cycle = wait;
	
	if (hatole(arg0, 4) == 0)
		process->carry = 1;
	else
		process->carry = 0;
	
	if(DBG_INSTS || DBG_LD)
		debug_ld(mem, arg1, address, process);
	
	return (0);
}