#include "corewar.h"

int exec_ld_lld(unsigned char *mem, int pc, t_process *process)
{
	int address;
	int wait;
	char arg0[4];
	char arg1[1];

	address = -1;
	wait = 0;
	ft_putstr("--------- In exec_ld_lld (exec_inst.c) ----------\n");

	if (mem[pc + 1] == 0x90) // Get param 1 depend of arg_code
	{
		ft_memcpy(arg0, &mem[pc + 2], 4); //get arg0 (dir-4B)
		process->pc += 6;
	}
	else if(mem[pc + 1] == 0xd0)
	{
		ft_memcpy(arg0, &mem[pc + 2], 2); //get ind (ind-2B)
		if (mem[pc] == 0x02) //calc adress of data to get depend of op_code (IDX_MOD or not)
		{
			address = (pc + MODFIX(hatole(arg0, 2), IDX_MOD)) % MEM_SIZE;
			wait = 5;
		}
		else
		{
			address = MODFIX(pc + hatole(arg0, 2), MEM_SIZE);
			wait = 10;
		}
		ft_memcpy(arg0, &mem[address], REG_SIZE); //get data
		process->pc += 4;
	}
	else
	{
		process->pc += 2;
		exit(0);
		return (1);
	}
	
	// get param 2 (REG)
	ft_memcpy(arg1, &mem[process->pc], 1);
	process->pc++;
	if (arg1[0] > 0x0f)
		return (1);

	//	Do ld
	ft_memcpy(process->reg[GET_REGNB(arg1)], arg0, REG_SIZE);
	process->wait_cycle = wait;
	
	// DEBUG
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
	ft_print_memory(arg0, 4);
	ft_print_memory(process->reg[GET_REGNB(arg1)], 4);
	
	return (0);
}

/*int exec_ld(unsigned char *mem, int pc, t_process *process)
{
	char address[2];
	char arg1[4];
	char arg2[1];

	if (mem[pc + 1] == 0x90) // check args_code
	{
		ft_memcpy(arg1, &mem[pc + 2], 4); //get arg1 (dir-4B)
		ft_memcpy(arg2, &mem[pc + 6], 1); //get arg2 (reg-1B)
	}
	else if(mem[pc + 1] == 0xd0)
	{
		ft_memcpy(address, &mem[pc + 2], 2); //get address of data to get (ind-2B)
		ft_memcpy(arg1, &mem[pc + (hatole(address, 2) % IDX_MOD)], REG_SIZE); //get arg1 (dir 4B)
		ft_memcpy(arg2, &mem[pc + 4], 1); //get arg2 (reg-1B)
	}
	else 
	{
		process->pc += 2;
		//ft_putstr("\nError: wrong args_code");
		exit(0);
		return (1);
	}

	if (*arg2 <= 0x10 || *arg2 >= 0x01) //if reg valid do ld
	{
		ft_memcpy(process->reg[hatole(arg2, 1) - 1], arg1, REG_SIZE); // __TODO: if REG_SYZE > 4??
		process->wait_cycle = 5;
		process->pc += 7;
	}
	else //else pc += 7
	{
		process->pc += 7;
		//ft_putstr("\nError: wrong reg number");
		exit(0);
		return (1);
	}

	ft_putstr("--------- In exec_ld (exec_inst.c) ----------\n");
	if(mem[pc + 1] == 0xd0) {
		ft_putstr("\nadress IDX_MOD ");
		ft_putnbr(hatole(address, 2) % IDX_MOD);
	}
	ft_putstr("arg2: ");
	ft_print_memory(arg2, 1);
	ft_putstr("arg1: ");
	ft_print_memory(arg1, 4);

	ft_putstr("\nprocess->reg[");
	ft_putnbr(hatole(arg2, 1));
	ft_putstr("]: ");
	ft_print_memory(process->reg[hatole(arg2, 1) - 1], REG_SIZE);
	ft_putstr("process->wait_cycle: ");
	ft_putnbr(process->wait_cycle);
	ft_putstr("\nprocess->pc: ");
	ft_putnbr(process->pc);
	ft_putstr("process->pc: \n");

	exit(0);
	return (0);
}*/