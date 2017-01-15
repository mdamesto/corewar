#include "corewar.h"

void				init_env(void)
{
	t_env *new;
	if (!(new = ft_memalloc(sizeof(t_env*))))
		ft_error(E_MALLOC, NULL);
	if (!(new->mem = ft_memalloc(sizeof(void *) * MEM_SIZE)))
		ft_error(E_MALLOC, NULL);
	if (!(new->champs = ft_memalloc(sizeof(t_champ*) * MAX_PLAYERS)))
		ft_error(E_MALLOC, NULL);
	new->current_ctd = CYCLE_TO_DIE;
	new->dump = -1;
	new->next_champ_nb = -1;
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