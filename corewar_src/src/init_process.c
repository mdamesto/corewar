#include "corewar.h"

t_process *new_process(int pc, int nb)
{
	t_process *new;
	int8_t i;

	int zero = 0;

	if (!(new = ft_memalloc(sizeof(t_process))))
		ft_error(E_MALLOC, NULL);
	
	new->reg = ft_tab_set(16, 4);
	i = -1;
	while (++i < 16)
		ft_memcpy(new->reg[i], &zero, 4);
	
	new->pc = pc;
	nb= revert_endian(nb);
	ft_memcpy(new->reg[0], &(nb), 4);
	new->carry = 0;
	new->wait_cycle = 0;

	return (new);
}

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

void static debug_process(t_env *env)
{
	int i;
	int j;

	ft_putstr("\n -------- PROCESS  --------\n");
	i = -1;
	while (env->champs[++i])
	{
		ft_putstr("\nCHAMPS[");
		ft_putnbr(i);
		ft_putstr("]:\n");
		j = -1;
		while (env->champs[i]->process[++j])
		{
			print_process(env->champs[i]->process[j]);
		}
		ft_putstr("\n");
	}
	ft_putstr("\n");
}

void	init_process(t_env *env)
{
	int i;

	i = -1;
	// ----------------------- TODO
	while (env->champs[++i])
	{
		ft_memcpy(&(env->mem[(MEM_SIZE / 4) * i]), env->champs[i]->inst, env->champs[i]->size);
		env->champs[i]->process[0] = new_process((MEM_SIZE / 4) * i, env->champs[i]->nb);
	}
	
	if (DBG_MEM)
	{
		ft_putstr("\n -------- MEM --------\n");
		ft_print_memory(env->mem, MEM_SIZE);
	}
	if (DBG_PRCS)
		debug_process(env);
}