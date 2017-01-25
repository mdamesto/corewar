#include "corewar.h"

static void	debug_ld(unsigned char *mem, char *arg1, int address, t_process *process)
{
	ft_putstr("--------- LD_LLD ----------\n");
	if (address != -1)
	{
		ft_putstr("adress: ");
		ft_putnbr(address);
		ft_putstr("\n");
		ft_print_memory(&mem[address], 4);
	}
	ft_putstr("\nreg nb: ");
	ft_putnbr(GET_REGNB(arg1) + 1);
	ft_putstr("\n");
	ft_print_memory(process->reg[GET_REGNB(arg1)], 4);
}

int exec_ld_lld(unsigned char *mem, int pc, t_process *process)
{
	//-------------------------- TODO (clean it)
	int address;
	int wait;
	char arg0[4];
	char arg1[1];

	address = -1;
	wait = 0;

	if (mem[MMS(pc + 1)] == 0x90) // Get param 1 depend of arg_code
	{
		cpy_from_mem(arg0, mem, 4, MMS(pc + 2)); //get arg0 (dir-4B)
		INC_PC(6);
	}
	else if(mem[MMS(pc + 1)] == 0xd0)
	{
		cpy_from_mem(arg0, mem, 2, MMS(pc + 2)); //get ind (ind-2B)
		if (mem[pc] == 0x02) //calc adress of data to get depend of op_code (IDX_MOD or not)
		{
			address = MMS(pc + MODFIX(hatole(arg0, 2), IDX_MOD));
			wait = 5;
		}
		else
		{
			address = MODFIX(pc + hatole(arg0, 2), MEM_SIZE);
			wait = 10;
		}
		cpy_from_mem(arg0, mem, REG_SIZE, address); //get data
		INC_PC(4);
	}
	else
	{
		INC_PC(2);
		return (1);
	}
	
	cpy_from_mem(arg1, mem, 1, process->pc);
	INC_PC(1);
	if (arg1[0] > 0x0f)
		return (1);

	ft_memcpy(process->reg[GET_REGNB(arg1)], arg0, REG_SIZE);
	process->wait_cycle = wait;
	
	if(DBG_INSTS || DBG_LD)
		debug_ld(mem, arg1, address, process);
	
	return (0);
}