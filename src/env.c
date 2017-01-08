#include "corewar.h"

void	init_env(char *filename)
{
	t_env *new;
	new = NULL;

	if (!(new = malloc(sizeof(t_env))))
		ft_error(EMALLOC);
	ft_bzero(new, sizeof(t_env));
	if (!(new->header = malloc(sizeof(header_t))))
		ft_error(EMALLOC);
	ft_bzero(new->header, sizeof(header_t));
	new->header->prog_size = 0;
	new->filename = filename;
	if ((new->fd = open(new->filename, O_RDONLY)) < 0) 
		ft_error(EOPEN);
	new->lc = 0;
	get_env(new);
} 

t_env	*get_env(t_env *env)
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

void	free_env(void) {
	
	t_env *env;

	env = get_env(NULL);
	if (env)
	{
		/*if (env->elem)
			free(elem);*/
		free(env);
	}
}