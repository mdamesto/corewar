#include "corewar.h"

t_process *fork_process(int pc, t_process *process)
{
	t_process *new;
	int8_t i;

	if (!(new = ft_memalloc(sizeof(t_process))))
		ft_error(E_MALLOC, NULL);
	
	new->reg = ft_tab_set(16, 4);
	i = -1;
	while (++i < 16)
		ft_memcpy(new->reg[i], process->reg[i], 4);
	
	new->pc = pc;
	new->carry = process->carry;
	new->wait_cycle = process->wait_cycle;

	return (new);
}

void	print_process(t_process *process)
{
	int i;

	i = -1;
	ft_putstr("pc: ");
	ft_putnbr(process->pc);
	ft_putstr("\nwait_cycle: ");
	ft_putnbr(process->wait_cycle);
	ft_putstr("\ncarry: ");
	ft_putnbr(process->carry);
	ft_putstr("\n");
	while (++i < 16)
	{
		ft_putstr("reg[");
		ft_putnbr(i);
		ft_putstr("]: ");
		ft_print_memory(process->reg[i], 4);
	}
}

int exec_fork_lfork(int i, int j, t_env *env)
{
	ft_putstr("--------- In exec_fork_lfork (exec_inst.c) ----------\n");
	t_process *process;
	t_process *fork;
	char arg[4];
	int fork_pc;

	process = env->champs[i]->process[j];
	
	ft_memset(arg, 0x00, 2);
	ft_memcpy(&arg[2], &env->mem[process->pc + 1], 2); 

	if (env->mem[process->pc] == 0x0c)
	{
		process->wait_cycle = 800;
		fork_pc = (process->pc + MODFIX(hatole(arg, 4), IDX_MOD)) % MEM_SIZE;
	}
	else
	{
		process->wait_cycle = 1000;
		fork_pc = MODFIX(process->pc + hatole(arg, 4), MEM_SIZE);
	}

	fork = fork_process(fork_pc, process);
	while (env->champs[i]->process[++j])
		;
	env->champs[i]->process[j] = fork;



	ft_putstr("arg: ");
	ft_print_memory(arg, 4);
	int nb = hatole(arg, 4);
	ft_print_memory(&nb, 4);
	ft_putnbr(nb);
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

	exit (0);
	return (0);
}