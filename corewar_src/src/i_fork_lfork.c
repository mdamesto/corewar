#include "corewar.h"

static void	debug_fork(int pc)
{
	ft_putstr("--------- FORK_LFORK ----------\n");
	ft_putstr("fork to: ");
	ft_putnbr(pc);
	ft_putstr("\n");

}

int exec_fork_lfork(int i, int j, t_env *env)
{
	t_process *process;
	t_process *fork;
	char arg[4];
	int fork_pc;

	process = env->champs[i]->process[j];
	cpy_from_mem(arg, env->mem, 2, MMS(process->pc + 1));

	if (env->mem[process->pc] == 0x0c)	//	if fork
	{
		process->wait_cycle = 800;
		fork_pc = MODFIX(process->pc + (*(int*)arg % IDX_MOD), MEM_SIZE);
	}
	else								//	if lfork
	{
		process->wait_cycle = 1000;
		fork_pc = MODFIX(process->pc + *(int*)arg, MEM_SIZE);
	}
	fork = fork_process(fork_pc, process);
	
	while (env->champs[i]->process[++j])
		;
	if(!(env->champs[i]->process = realloc(env->champs[i]->process, sizeof(t_process*) * (j + 2))))
		ft_error(E_MALLOC, NULL);
	env->champs[i]->process[j] = fork;
	env->champs[i]->process[j + 1] = NULL;
	INC_PC(3);

	if (env->debug || DBG_FORK)
		debug_fork(fork_pc);
	
	return (0);
}