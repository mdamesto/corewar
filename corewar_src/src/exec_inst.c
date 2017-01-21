#include "corewar.h"

int exec_live(unsigned char *mem, int pc, t_process *process, t_env *env)
{
	char tmp[4];

	ft_memcpy(tmp, &(mem[pc + 1]), 4);
	env->lives[env->lives_nb++] = atole(tmp);
	process->wait_cycle = 10;
	process->pc = pc + 5;
	
	exit(0);
	return (0);
}

int exec_ld(unsigned char *mem, int pc, t_process *process)
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
		ft_memcpy( address, &mem[pc + 2], 2); //get address of data to get (ind-2B)
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

	/* ----- ADRESS & ARGS -----*/
	ft_putstr("--------- In exec_ld (exec_inst.c) ----------\n");
	if(mem[pc + 1] == 0xd0) {
		ft_putstr("\nadress IDX_MOD ");
		ft_putnbr(hatole(address, 2) % IDX_MOD);
	}
	ft_putstr("arg2: ");
	ft_print_memory(arg2, 1);
	ft_putstr("arg1: ");
	ft_print_memory(arg1, 4);

	/* ------ REG LD ------ */
	ft_putstr("\nprocess->reg[");
	ft_putnbr(hatole(arg2, 1));
	ft_putstr("]: ");
	ft_print_memory(process->reg[0], REG_SIZE);
	ft_putstr("process->wait_cycle: ");
	ft_putnbr(process->wait_cycle);
	ft_putstr("\nprocess->pc: ");
	ft_putnbr(process->pc);
	ft_putstr("process->pc: \n");

	exit(0);
	return (0);
}

int exec_st(unsigned char *mem, int pc, t_process *process)
{
	char arg1[1];
	char arg2[2];

	if (mem[pc + 1] == 0x50)
	{
		ft_memcpy(arg1, &mem[pc + 2], 1); 
		ft_memcpy(arg2, &mem[pc + 3], 1);
		if ((*arg2=1 <= 0x10 || *arg1 >= 0x01) && (*arg2=1 <= 0x10 || *arg1 >= 0x01))
			ft_memcpy(process->reg[hatole(arg2, 2)], process->reg[hatole(arg1, 1)], REG_SIZE);
		else
			return (1);
		process->pc += 4;
	}
	else if(mem[pc + 1] == 0x70)
	{
		ft_memcpy(arg1, &mem[pc + 2], 1);
		ft_memcpy(arg2, &mem[pc + 3], 2);
		if (*arg1 <= 0x10 || *arg1 >= 0x01)
			ft_memcpy(&mem[hatole(arg2, 2) % IDX_MOD], process->reg[hatole(arg1, 1)], REG_SIZE);
		else
			return (1);
		process->pc += 5;
	}
	else 
	{
		process->pc += 2;
		exit(0);
		return (1);
	}
	process->wait_cycle = 5;
	exit(0);
	return (0);
}

void	exec_inst(t_process *process, t_env *env)
{
	unsigned char *mem;
	uint32_t pc; 

	mem = env->mem;
	pc = process->pc;
	if (mem[pc] == 0x01)
		exec_live(mem, pc, process, env);
	else if (mem[pc] == 0x02)
		exec_ld(mem, pc, process);
	else if (mem[pc] == 0x02)
		exec_st(mem, pc, process);
	else if (mem[pc] == 0x03)
		;
	else if (mem[pc] == 0x04)
		;
	else if (mem[pc] == 0x05)
		;
	else if (mem[pc] == 0x06)
		;
	else if (mem[pc] == 0x07)
		;
	else if (mem[pc] == 0x08)
		;
	else if (mem[pc] == 0x09)
		;
	else if (mem[pc] == 0x0a)
		;
	else if (mem[pc] == 0x0b)
		;
	else if (mem[pc] == 0x0c)
		;
	else if (mem[pc] == 0x0d)
		;
	else if (mem[pc] == 0x0e)
		;
	else if (mem[pc] == 0x0f)
		;
	else if (mem[pc] == 0x10)
		;
	else
		;
}