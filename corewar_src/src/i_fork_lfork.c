#include "corewar.h"

static void	debug_fork(int pc, int j )
{
	ft_putstr("--------- FORK_LFORK ----------\n");
	ft_putstr("fork to: ");
	ft_putnbr(pc);
	ft_putstr("\n");
	ft_putstr("process nb: ");
	ft_putnbr(j);
	ft_putstr("\n");

}

/*add_fork_process(t_champ *champ, j, t_process *fork)
{
	int i;
	int len;
	t_process **new;

	len = j;
	while (champ->process[++len])
		;
	new = malloc(sizeof(t_champ*) * (len + 1));
	new[len] = NULL;
	i = -1;
	while (++i <= j)
		new[i] = champ->process[i];
	new[i] = fork;
	while (++i < len)
		new[i] = champ->process[i - 1];
	free(champ->process);
	champ->process = new;
}*/

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
	fork = fork_process(fork_pc, process, env);
	
	//add_fork_process(env->champs[i], j, fork);

	while (env->champs[i]->process[++j])
		;
	if(!(env->champs[i]->process = realloc(env->champs[i]->process, sizeof(t_process*) * (j + 2))))
		ft_error(E_MALLOC, NULL);
	env->champs[i]->process[j] = fork;
	env->champs[i]->process[j + 1] = NULL;
	INC_PC(3);

	if (env->debug || DBG_FORK)
		debug_fork(fork_pc, j);
	
	return (0);
}