#include "corewar.h"

void				init_env(void)
{
	t_env *new;

	if (!(new = ft_memalloc(sizeof(t_env))))
		ft_error(E_MALLOC, NULL);
	
	if (!(new->champs = (t_champ**)ft_memalloc(sizeof(t_champ*) * (MAX_PLAYERS + 1))))
		ft_error(E_MALLOC, NULL);
	new->champs[0] = NULL;
	new->champs[1] = NULL;
	new->champs[2] = NULL;
	new->champs[3] = NULL;
	new->champs[4] = NULL;

	ft_memset(new->mem, '\0', MEM_SIZE);
	
	new->cycle_to_die = CYCLE_TO_DIE;
	new->current_cycle = 0;
	new->cycle = 0;

	if (!(new->lives = (int *)ft_memalloc(sizeof(int) * 1000)))
		ft_error(E_MALLOC, NULL);
	new->lives_nb = 0;

	new->dump = -1;
	new->next_champ_nb = -1;
	new->end = false;
	
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

void				free_env(void)
{
	
	t_env *env;

	env = get_env(NULL);
	if (env)
	{
		free(env);
	}
}