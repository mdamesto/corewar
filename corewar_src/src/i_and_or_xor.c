#include "corewar.h"

int exec_and_or_xor(unsigned char *mem, int pc, t_process *process)
{
	char 		**args;
	uint32_t	and;
	int 		tab[2];

	args = NULL;
	ft_putstr("--------- In exec_and (exec_inst.c) ----------\n");
	
	// Set tab depend on arg_code
	if (mem[pc + 1] == 0x54) 
		ft_memcpy(tab, "\x01\x00\x00\x00\x01\x00\x00\x00", 8); //set tab to int {1,1}
	else if (mem[pc + 1]== 0x64) 
		ft_memcpy(tab, "\x01\x00\x00\x00\x04\x00\x00\x00", 8); //set tab to int {1,4}
	else if (mem[pc + 1]== 0x74) 
		ft_memcpy(tab, "\x01\x00\x00\x00\x02\x00\x00\x00", 8); //set tab to int {1,2}
	else if (mem[pc + 1]== 0x94) 
		ft_memcpy(tab, "\x04\x00\x00\x00\x01\x00\x00\x00", 8); //set tab to int {4,1}
	else if (mem[pc + 1]== 0xa4) 
		ft_memcpy(tab, "\x04\x00\x00\x00\x04\x00\x00\x00", 8); //set tab to int {4,4}
	else if (mem[pc + 1]== 0xb4) 
		ft_memcpy(tab, "\x04\x00\x00\x00\x02\x00\x00\x00", 8); //set tab to int {4,2}
	else if (mem[pc + 1]== 0xd4) 
		ft_memcpy(tab, "\x02\x00\x00\x00\x01\x00\x00\x00", 8); //set tab to int {2,1}
	else if (mem[pc + 1]== 0xe4) 
		ft_memcpy(tab, "\x02\x00\x00\x00\x04\x00\x00\x00", 8); //set tab to int {2,4}
	else if (mem[pc + 1]== 0xf4) 
		ft_memcpy(tab, "\x02\x00\x00\x00\x02\x00\x00\x00", 8); //set tab to int {2,2}
	else
	{
		process->pc += 2;
		exit(0);
		return (1);
	}

	//	get arg[0] & arg[1] based on tab. 
	//	Ex: tab = {1, 4} ===> args[0] = GET_REGV(REG) && args[1] = DIR ) 
	if (!(args = get_args(mem, pc, &tab[0], process)))
	{
			exit(0);
			return (1);
	}

	//	Get args3 -> reg
	ft_memcpy(args[2], &mem[pc], 1);
	process->pc++;

	//	Use the binary op depend on op_code
	if (mem[pc] == 0x06)
		and = *(int*)args[0] & *(int*)args[1];
	else if (mem[pc] == 0x07)
		and = *(int*)args[0] | *(int*)args[1];
	else if (mem[pc] == 0x08)
		and = *(int*)args[0] ^ *(int*)args[1];

	//	Copy result in args[3] (REG)
	ft_memcpy(process->reg[hatole(args[2], 1) - 1], &and, REG_SIZE);
	
	// DEBUG
	ft_print_memory(args[0], 4);
	ft_print_memory(args[1], 4);
	ft_print_memory(&and, 4);
	ft_print_memory(process->reg[hatole(args[2], 1) - 1], 4);
	
	exit(0);
	return (0);
}