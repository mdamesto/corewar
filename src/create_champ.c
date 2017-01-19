#include "asm.h"

static char 	*get_full_insts(t_env *env)
{
	char	*insts;
	t_inst	*tmp_inst;
	char	*to_free;

	insts = ft_strnew(1);
	tmp_inst = env->inst;
	while(tmp_inst)
	{
		to_free = insts;
		insts = ft_strjoin(insts, tmp_inst->content);
		tmp_inst = tmp_inst->next;
		if (to_free)
			free(to_free);
	}
	return (insts);
}

static char 	*format_final(char *final)
{
	char	*final_format;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(final);
	len = len + ((len / 2) + 1);
	final_format = ft_strnew(len);
	i = 0;
	j = 0;
	while(final[i])
	{
		if (i != 0 && !(i % 32))
			final_format[j++] = '\n';
		else if (i != 0&& !(i % 4))
			final_format[j++] = ' ';
		final_format[j++] = final[i++];
	}
	return (final_format);
}

void			create_champion(t_env *env)
{
	int		fd_cor;
	char	**tab;
	char	*final;

	ft_putstr("\nCreating champion ...");
	final = NULL;
	tab = ft_tab_set(5, 0);
	tab[0] = convert_hex_octnb(env->header->magic, 4); 		// 	magic
	tab[1] = str_to_hex(env->header->prog_name); 			//	name
	tab[1] = fill_hex_be(tab[1], PROG_NAME_LENGTH);			//	name
	tab[2] = convert_hex_octnb(env->c_adress, 8);			//	prog_size
	tab[3] = str_to_hex(env->header->comment);				//	comment
	tab[3] = fill_hex_be(tab[3], COMMENT_LENGTH + 4);		//	comment
	tab[4] = get_full_insts(env);							//	insts
	final = ft_tab_join(tab);
	final = format_final(final);
	free(tab);
	fd_cor = open (ft_strjoin(env->filename, ".cor"), O_RDWR | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH);
	write(fd_cor, final, ft_strlen(final));
	ft_putstr("\nChampion created: ");
	ft_putstr(ft_strjoin(env->filename, ".cor"));
	ft_putstr("\n");
	//print_champ(tab,final); //------ CHAMPION -------//
}
