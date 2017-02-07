#include "corewar.h"

void				init_env(void)
{
	t_env *new;

	if (!(new = ft_memalloc(sizeof(t_env))))
		ft_error(E_MALLOC, NULL);
	
	if (!(new->champs = (t_champ**)ft_memalloc(sizeof(t_champ*) * (MAX_PLAYERS + 1))))
		ft_error(E_MALLOC, NULL);
	ft_memset(new->mem, '\0', MEM_SIZE);
	new->cycle_to_die = CYCLE_TO_DIE;
	new->current_cycle = 0;
	new->cycle = 0;
	new->lives_nb = 0;
	new->lives_tab_size = 64;
	if (!(new->lives = (int *)ft_memalloc(sizeof(int) * new->lives_tab_size)))
		ft_error(E_MALLOC, NULL);
	new->dump = -1;
	new->next_fixed = 0;
	new->end = false;
	new->debug = DBG_INSTS;
	new->process_nb = 0;

	get_env(new);
}

t_env				*get_env(t_env *env)
{
	static t_env *save = NULL;

	if (env == NULL)
		return (save);
	else
	{
		save = env;
		return (save);
	}
}

void				free_process(t_process *process)
{
	if (process)
	{
		if (process->reg)
			ft_tab_free(process->reg);
		free(process);
	}
}

void				free_champ(t_champ *champ)
{
	int i;

	i = 0;
	if (champ)
	{
		if (champ->process)
		{
			while (champ->process[i])
			{
				free_process(champ->process[i]);
				i++;
			}
			free(champ->process);
		}
		free(champ);
	}
}

void				free_env(void)
{
	t_env *env;
	int i;

	env = get_env(NULL);
	i = 0;
	if (env)
	{
		if (env->champs)
		{
			while(env->champs[i])
			{
				free_champ(env->champs[i]);
				i++;
			}
			free(env->champs);
		}
		if (env->lives)
			free(env->lives);
		free(env);
	}
}