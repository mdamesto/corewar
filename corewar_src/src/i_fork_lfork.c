#include "corewar.h"

static void	debug_fork(char *arg, t_process *process, t_process *fork )
{
	ft_putstr("arg: ");
	ft_putnbr(hatole(arg, 2));
	ft_print_memory(arg, 2);
	ft_putstr("\nprocess->pc + MODFIX(hatole(arg, 4), IDX_MOD):  ");
	ft_putnbr(process->pc + MODFIX(hatole(arg, 4), IDX_MOD));
	ft_putstr("\n(process->pc + MODFIX(hatole(arg, 4), IDX_MOD)) modulo MEM_SIZE: ");
	ft_putnbr((process->pc + MODFIX(hatole(arg, 4), IDX_MOD)) % MEM_SIZE);
	ft_putstr("\nMODFIX(process->pc + hatole(arg, 4), MEM_SIZE):  ");
	ft_putnbr(MODFIX(process->pc + hatole(arg, 4), MEM_SIZE));
	ft_putstr("\n");
	ft_putstr("\nPROCESS: \n");
	print_process(process);
	ft_putstr("\nFORK: \n");
	print_process(fork);
}

int exec_fork_lfork(int i, int j, t_env *env)
{
	//ft_putstr("\n--------- FORK_LFORK ----------\n");
	t_process *process;
	t_process *fork;
	char arg[2];
	int fork_pc;

	process = env->champs[i]->process[j];
	cpy_from_mem(arg, env->mem, 2, MMS(process->pc + 1));
	revert_bytes(arg, 2);

	if (env->mem[process->pc] == 0x0c)	//	if fork
	{
		process->wait_cycle = 800;
		fork_pc = MODFIX(process->pc + (*(short int*)arg % IDX_MOD), MEM_SIZE);
	}
	else								//	if lfork
	{
		process->wait_cycle = 1000;
		INV_CARRY;
		fork_pc = MODFIX(process->pc + *(short int*)arg, MEM_SIZE);
	}

	fork = fork_process(fork_pc, process);

	/*ft_putstr("arg: ");
	ft_putnbr(*(short int*)arg);
	ft_putstr(" pc: ");
	ft_putnbr(process->pc);
	ft_putstr(" fork pc: ");
	ft_putnbr(fork_pc);
	ft_putstr("\n");*/
	
	INC_PC(3);
	while (env->champs[i]->process[++j])
		;
	env->champs[i]->process[j] = fork;
	if (DBG_INSTS || DBG_FORK)
		debug_fork(&arg[0], process, fork);
	return (0);
}