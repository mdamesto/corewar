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

int 	check_empty_line(char *line){
	int i;

	i = 0;
	while (line[i]) 
	{
		if (line[i] != ' ' && line[i] != '	')
			return (0);
		i++;
	}
	return (1);
}

int gnl(void)
{
	int ret;
	int loop;
	t_env *env;

	loop = 1;
	ret = 1;
	env = get_env(NULL);
	while (loop == 1 && ret > 0) {
		env->line_nb++;
		if ((ret = get_next_line(env->fd, &(env->line))) < 0)
			ft_error(EGNL);
		remove_comment(env);
		loop = check_empty_line(env->line);
	}
	return (ret);
}