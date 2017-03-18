#include "asm.h"

char	*get_content(t_env *env)
{
	int		i;
	int		j;
	char	*ret;

	ret = ft_strnew(COMMENT_LENGTH);
	i = 0;
	j = 0;
	if (env->line[i++] != '"')
		ft_error(EPARSING);
	while (env->line[i] != '"')
	{
		ret[j++] = env->line[i];
		if (!env->line[i + 1])
		{
			ret[j++] = '\n';
			env->line_nb++;
			if (get_next_line(env->fd, &(env->line)) != 1)
				ft_error(EPARSING);
			i = -1;
		}
		if (j > COMMENT_LENGTH)
			ft_error(EPARSING);
		i++;
	}
	if (env->line[i + 1])
		ft_error(EPARSING);
	ret[j] = '\0';
	return (ret);
}

void	get_name(t_env *env)
{
	int		ret;
	char	*content;

	ret = gnl();
	if (ret == 0)
		ft_error(EEMPTYFILE);
	if (ft_strncmp(env->line, ".name", 5) != 0)
		ft_error(ENONAME);
	env->line = ft_strcut_f(env->line, 0, 5);
	env->line = ft_strtrim(env->line);
	content = get_content(env);
	if (ft_strlen(content) > PROG_NAME_LENGTH + 1)
		ft_error(E_NM_LEN);
	ft_strcpy(env->header->prog_name, content);
	free(content);
}

void	get_comment(t_env *env)
{
	char *content;

	gnl();
	if (ft_strncmp(env->line, ".comment", 8) != 0)
		ft_error(ENONAME);
	env->line = ft_strcut_f(env->line, 0, 8);
	env->line = ft_strtrim(env->line);
	content = get_content(env);
	ft_strcpy(env->header->comment, content);
	free(content);
}
