#include "corewar.h"

int exec_sti(unsigned char *mem, int pc, t_process *process)
{
	ft_putstr("--------- In exec_sti (exec_inst.c) ----------\n");
	char 		**args;
	int			sum;
	int 		tab[2];
	int 		add;

	/*
	* 	Set tab depend on arg_code (mem[pc + 1])   
	*/
	if (mem[(pc + 1) % MEM_SIZE] == 0x54) 
		ft_memcpy(tab, "\x01\x00\x00\x00\x01\x00\x00\x00", 8); //set tab to int {1,1}
	else if (mem[(pc + 1) % MEM_SIZE] == 0x58)
		ft_memcpy(tab, "\x01\x00\x00\x00\x03\x00\x00\x00", 8); //set tab to int {1,3}
	else if (mem[(pc + 1) % MEM_SIZE] == 0x64) 
		ft_memcpy(tab, "\x03\x00\x00\x00\x01\x00\x00\x00", 8); //set tab to int {3,1}
	else if (mem[(pc + 1) % MEM_SIZE] == 0x68) 
		ft_memcpy(tab, "\x03\x00\x00\x00\x03\x00\x00\x00", 8); //set tab to int {3,3}
	else if (mem[(pc + 1) % MEM_SIZE]== 0x74) 
		ft_memcpy(tab, "\x02\x00\x00\x00\x01\x00\x00\x00", 8); //set tab to int {2,1}
	else if (mem[(pc + 1) % MEM_SIZE]== 0x78) 
		ft_memcpy(tab, "\x02\x00\x00\x00\x03\x00\x00\x00", 8); //set tab to int {2,3}
	else
	{
		process->pc += 2;
		return (1);
	}

	/*
	* 	get 2nd & 3rd param in args[0] & args[1] based on tab 
	* 	1st arg skipped in get_args(line 20)
	*/ 
	if (!(args = get_args(mem, pc + 1, &tab[0], process)))
			return (1);
	
	/*
	* 	Get first param(REG) in args[2] & increment pc
	* 	Have to sub len of params to pc (incremeneted in get_args())
	*/ 
	if (tab[0] == 3)
		tab[0] = 2;
	if (tab[1] == 3)
		tab[1] = 2;
	ft_memcpy(args[2], &mem[pc - tab[0] - tab[1] - 1], 1);
	process->pc += 1;
	
	/*
	* 	Get sum of arg[0] + arg[1], 
	* 	Get adress
	*	& Do sti
	*/
	sum = hatole(args[0], 4) + hatole(args[1], 4);
	if ((pc + (sum % IDX_MOD)) > 0)
		add = (pc + (sum % IDX_MOD)) % MEM_SIZE;
	else
		add = MEM_SIZE - 1 + (pc + (sum % IDX_MOD));
	process->wait_cycle = 25;
	ft_memcpy(&mem[add], process->reg[GET_REGNB(args[2])], REG_SIZE);
	
	/* --- DEBUG --- */
	ft_putstr("\nargs[0]: ");
	ft_print_memory(args[0], 4);
	ft_putnbr(hatole(args[0], 4));
	ft_putstr("\nargs[1]: ");
	ft_print_memory(args[1], 4);
	ft_putnbr(hatole(args[1], 4));
	ft_putstr("\nsum: ");
	ft_putnbr(sum);
	ft_putstr("\n ");
	ft_putstr("\nadd: ");
	ft_putnbr(add);
	ft_putstr("\n ");
	ft_print_memory(&mem[add], 4);
	
	exit(0);
	return (0);
}