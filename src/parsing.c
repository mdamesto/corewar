#include "corewar.h"

char	*get_content(char *line) 
{
	int i;
	int j;
	int k;
	char *ret;

	i = 0;
	k = 0;
	
	while(line[i] && line[i] != '\"')
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
	if (ft_strncmp(env->line, ".name \"", 7) != 0)
		ft_error(ENONAME);
	
	content = get_content(env->line);
	if (ft_strlen(content) <= PROG_NAME_LENGTH + 1)
		ft_strcpy(env->header->prog_name, content);
	free(content);

	ft_putstr("champion's name: ");
	ft_putstr(env->header->prog_name);
	write (1, "\n", 1);
}

void	get_comment(t_env *env)
{
	char *content;

	gnl();
	if (ft_strncmp(env->line, ".comment \"", 10) != 0)
		ft_error(ENOCOM);

	content = get_content(env->line);
	if (ft_strlen(content) <= COMMENT_LENGTH + 1)
		ft_strcpy(env->header->comment, content);
	free(content);

	ft_putstr("champion's comment: ");
	ft_putstr(env->header->comment);
	write (1, "\n", 1);

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

void	get_instructions(t_env *env)
{
	gnl();
	while (check_empty_line(env->line) == 1)
		gnl();
	ft_putstr(env->line);
}


char	*parsing_champion(t_env *env) 
{
	ft_putstr("*** starting parsing: ");
	ft_putstr(env->filename);
	ft_putstr(" ... \n");

	get_name(env);
	get_comment(env);
	get_instructions(env);
	
	ft_putstr("*** parsing done! \n");
	return ("temporary return");
}
