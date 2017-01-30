#include "asm.h"

char	*get_content(char *line) 
{
	int i;
	//int j;
	//int k;
	char *ret;

	i = 0;
	//k = 0;
	
	/*while(line[i] && line[i] != '\"')
		i++;
	j = i + 1;
	while((line[j] && line[j] != '\"') || (line[j] && line[j - 1] == '\\'))
		j++;
	if (line[i] != '\"' || line[j] != '\"' || i == j)
		ft_error(EPARSING);
	ret = malloc(sizeof(char *) * (j - i));
	while (++i < j)
		ret[k++] = line[i];
	ret[k] = '\0';
	while (line[++i])
		if(line[i] != ' ' && line[i] != '	')
			ft_error(EPARSING);*/

	if (line[i++] != '\"')
		ft_error(EPARSING);
	while(line[i] && (line[i] != '\"' && line[i - 1] != '\\'))
		i++;
	if (line[i] != '\"')
		ft_error(EPARSING);
	ret = ft_strnew(i);
	i = 1;
	while(line[i] && (line[i] != '\"' && line[i - 1] != '\\'))
	{
		ret[i - 1] = line[i];
		i++;
	}
	while (line[++i])
		if(line[i] != ' ' && line[i] != '	')
			ft_error(EPARSING);

	return (ret);
}

void	get_name(t_env *env)
{
	int ret;
	char *content;

	ret = gnl();
	if (ret == 0)
		ft_error(EEMPTYFILE);
	if (ft_strncmp(env->line, ".name" , 5) != 0)
		ft_error(ENONAME);
	env->line = ft_strcut_f(env->line, 0, 5);
	env->line = ft_strtrim(env->line);
	content = get_content(env->line);
	if (!ft_strlen(content))
		ft_error(ENONAME);
	if (ft_strlen(content) > PROG_NAME_LENGTH + 1)
		ft_error(E_NM_LEN);
	ft_strcpy(env->header->prog_name, content);
	free(content);
}

void	get_comment(t_env *env)
{
	char *content;

	gnl();
	if (ft_strncmp(env->line, ".comment" , 8) != 0)
		ft_error(ENONAME);
	env->line = ft_strcut_f(env->line, 0, 8);
	env->line = ft_strtrim(env->line);
	content = get_content(env->line);
	if (!ft_strlen(content))
		ft_error(ENONAME);
	if (ft_strlen(content) > PROG_NAME_LENGTH + 1)
		ft_error(E_NM_LEN);
	ft_strcpy(env->header->comment, content);
	ft_putstr(content);
	free(content);
}