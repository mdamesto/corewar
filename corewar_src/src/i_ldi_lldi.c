#include "corewar.h"

int exec_ldi_lldi(unsigned char *mem, int pc, t_process *process)
{
	ft_putstr("--------- In exec_lld_lldi (exec_inst.c) ----------\n");
	char 		**args;
	int			sum;
	int 		tab[2];
	int 		address;

	args = NULL;
	address = 0;
	// Set tab depend on arg_code
	if (mem[(pc + 1) % MEM_SIZE] == 0x54) 
		ft_memcpy(tab, "\x01\x00\x00\x00\x01\x00\x00\x00", 8); //set tab to int {1,1}
	else if (mem[(pc + 1) % MEM_SIZE] == 0x64) 
		ft_memcpy(tab, "\x01\x00\x00\x00\x03\x00\x00\x00", 8); //set tab to int {1,3}
	else if (mem[(pc + 1) % MEM_SIZE] == 0x94) 
		ft_memcpy(tab, "\x03\x00\x00\x00\x01\x00\x00\x00", 8); //set tab to int {3,1}
	else if (mem[(pc + 1) % MEM_SIZE] == 0xa4) 
		ft_memcpy(tab, "\x03\x00\x00\x00\x03\x00\x00\x00", 8); //set tab to int {3,3}
	else if (mem[(pc + 1) % MEM_SIZE]== 0xd4) 
		ft_memcpy(tab, "\x02\x00\x00\x00\x01\x00\x00\x00", 8); //set tab to int {2,1}
	else if (mem[(pc + 1) % MEM_SIZE]== 0xe4) 
		ft_memcpy(tab, "\x02\x00\x00\x00\x03\x00\x00\x00", 8); //set tab to int {2,3}
	else
	{
		process->pc += 2;
		return (1);
	}

	//	get arg[0] & arg[1] based on tab. 
	//	Ex: tab = {1, 3} ===> args[0] = GET_REGV(REG) && args[1] = DIR(siz = 2) ) 
	if (!(args = get_args(mem, pc, &tab[0], process)))
			return (1);
	// get sum of arg[0] + arg[1];
	sum = hatole(args[0], 4) + hatole(args[1], 4);

	//	Get args3 -> reg
	ft_memcpy(args[2], &mem[pc], 1);
	process->pc++;
	if (args[2][0] > 0x0f)
		return (1);

	// get adress -- depend of op_code (IDX_MOD or not) 
	if (mem[pc] == 0x0a)
	{
		address = (pc + MODFIX(sum, IDX_MOD)) % MEM_SIZE;
		process->wait_cycle = 25;

	}
	else if (mem[pc] == 0x0e)
	{
		address = MODFIX(pc + sum, MEM_SIZE);
		process->wait_cycle = 50;
	}
	
	// ld mem[add] in reg[arg2]
	ft_memcpy(process->reg[hatole(args[2], 1)], &mem[address], REG_SIZE);
	
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
	ft_putstr("\naddress: ");
	ft_putnbr(address);
	ft_putstr("\n ");
	ft_print_memory(process->reg[hatole(args[2], 1) - 1], 4);
	exit(0);
	return (0);
}