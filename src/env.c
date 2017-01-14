#include "corewar.h"

char *get_path(char *str)
{
	char *ret;
	int i;

	ret = NULL;
	i = ft_strlen(str);
	while(str[--i])
	{
		if (str[i] == '/')
		{
			ret = ft_strnew(i + 1);
			ft_strncpy(ret, str, i + 1);
		}
	}
	return(ret);
}

char 	*check_filename(char *filename)
{
	int len;
	char *ret;

	len = ft_strlen(filename) - 1;

	if (filename[len] == 's' && filename[len - 1] == '.') 
	{
		ret = ft_strnew(len - 1);
		ft_strncpy(ret, filename, len - 1);
		return (ret);
	}
	else
		return (NULL);
}

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
	new->header->magic = COREWAR_EXEC_MAGIC;

	if (!(new->filename = check_filename(filename)))
		ft_error(E_BD_CHP);
	new->path = get_path(filename);
	if ((new->fd = open(filename, O_RDONLY)) < 0) 
		ft_error(EOPEN);
	
	new->line_nb = 0;
	new->c_adress = 0;
	new->add_to_adress = 0;

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
		if (env->data)
			ft_tab_free(env->data);
		free(env);
	}
}