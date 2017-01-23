#include "corewar.h"

void	cpy_from_mem(char *dst, char *src, int siz, int pc)
{
	int ext;

	ext = 0;
	if ((pc + siz) >= MEM_SIZE)
		ext = ((pc + siz) % MEM_SIZE) + 1;
	ft_memcpy(dst, &src[pc], siz - ext);
	ft_memcpy(&dst[siz - ext], &src[0], ext);
}

void	cpy_to_mem(char *dst, char *src, int siz, int pc)
{
	int ext;

	ext = 0;
	if ((pc + siz) >= MEM_SIZE)
		ext = ((pc + siz) % MEM_SIZE) + 1;
	ft_memcpy(&dst[pc], src, siz - ext);
	ft_memcpy(&dst[0], &src[siz - ext], ext);
}

int exec_zjmp(unsigned char *mem, int pc, t_process *process)
{
	char arg1[4];

	//ft_memcpy(arg1, &(mem[pc + 1]), 4);
	ft_putstr("--------- In exec_zjump (exec_inst.c) ----------\n");
	ft_putstr("\npc: ");
	ft_putnbr(process->pc);
	ft_putstr("\n");
	
	//cpy_from_mem(arg1, mem, 4, pc + 1);
	
	ft_memcpy(arg1, &mem[pc + 1], 2);
	ft_putstr("\narg1: ");
	ft_print_memory(arg1, 2);
	ft_putstr("\n");
	ft_putstr("\nhatole(arg1): ");
	ft_putnbr(hatole(arg1, 2));
	ft_putstr("\n");
	ft_putstr("\nprocess->pc + (hatole(arg1, 2)  IDX_MOD): ");
	ft_putnbr(process->pc + (hatole(arg1, 2) % IDX_MOD));
	ft_putstr("\n");
	ft_putstr("\nMEM_SIZE");
	ft_putnbr(MEM_SIZE);
	ft_putstr("\n");


	// (-) % (+) > (-) ??

	//if (process->carry == 1) 
	//{
		if ((process->pc + (hatole(arg1, 2) % IDX_MOD)) >= 0)
			process->pc = (process->pc + (hatole(arg1, 2) % IDX_MOD)) % MEM_SIZE;
		else
			process->pc = MEM_SIZE - 1 + (process->pc + (hatole(arg1, 2) % IDX_MOD));
	//}
	/*else
		process->pc = (process->pc + 5) % MEM_SIZE;
	*/
	process->wait_cycle = 20;
	ft_putstr("\npc: ");
	ft_putnbr(process->pc);
	ft_putstr("\n");

	exit(0);
	return (0);
}