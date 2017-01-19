#include "corewar.h"

t_process *new_process(int pc, int nb)
{
	t_process *new;

	if (!(new = ft_memalloc(sizeof(t_process))))
		ft_error(E_MALLOC, NULL);
	new->pc = pc;
	ft_memcpy(new->r1, &nb, 4);
	new->carry = 0;
	new->wait_cycle = 0;

	return (new);
}

void	init_champs(t_env *env)
{
	int i;

	i = -1;
	while (env->champs[++i])
	{
		ft_memcpy(&(env->mem[(MEM_SIZE / 4) * i]), env->champs[i]->inst, env->champs[i]->size);
		env->champs[i]->process[0] = new_process((MEM_SIZE / 4) * i, env->champs[i]->nb);
	}
	
	/* -------------------- MEM PROCESS -------------------- */
	ft_putstr("\n -------- MEM (init_champs.c)--------\n");
	ft_print_memory(env->mem, MEM_SIZE);
	
	ft_putstr("\n -------- PROCESS (init_champs.c) --------\n");
	i = -1;
	int j;
	while (env->champs[++i])
	{
		ft_putstr("\nCHAMPS[");
		ft_putnbr(i);
		ft_putstr("]:\n");
		j = -1;
		while (env->champs[i]->process[++j])
		{
			ft_putstr("process[");
			ft_putnbr(j);
			ft_putstr("   //->pc: ");
			ft_putnbr(env->champs[i]->process[j]->pc);
			ft_putstr("   //->r1: ");
			ft_putnbr(convert_big_endian(env->champs[i]->process[j]->r1));
		}
		ft_putstr("\n");
	}
	ft_putstr("\n");
	/* --------------------------------------------------------- */
}