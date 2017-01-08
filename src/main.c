#include "corewar.h"

void	remove_comment(t_env *env) 
{
	// COMMENT_CHAR IN STRING (.name "HERE") MUST NOT START A COMMENT ---------------------- TODO
	int i;
	int j;
	char *tmp;

	i = 0;
	j = 0;
	tmp = ft_strnew(ft_strlen(env->line));
	
	while (env->line[i]) 
	{	
		while(env->line[i] && env->line[i] != COMMENT_CHAR)
			tmp[j++] = env->line[i++];
		if (env->line[i] == COMMENT_CHAR)
			i++;
		while (env->line[i] && env->line[i] != COMMENT_CHAR)
			i++;
		if (env->line[i] == COMMENT_CHAR)
			i++;
	}
	free(env->line);
	env->line = tmp;
}

int gnl(void)
{
	int ret;
	t_env *env;

	env = get_env(NULL);
	env->lc++;
	if ((ret = get_next_line(env->fd, &(env->line))) < 0)
		ft_error(EGNL);
	remove_comment(env);
	return (ret);
}

int		main(int argc, char **argv)
{
	t_env *env;

	if (argc == 2) 
	{
		init_env(argv[1]);
		env = get_env(NULL);
		parsing_champion(env);
	}
	else
		ft_error(EBDARG);
	
	return (0);
}
