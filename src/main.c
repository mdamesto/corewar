#include "corewar.h"

char	*str_to_hex(char *str)
{
	char **tab;
	char *hex;
	int i;

	tab = ft_tab_set(ft_strlen(str), 0);
	i = -1;
	while (str[++i])
		tab[i] = convert_hex_octnb((int)str[i], 1);
	hex = ft_tab_join(tab);
	ft_tab_free(tab);
	return (hex);
}


char *get_full_insts(t_env *env)
{
	char 	*insts;
	t_inst 	*tmp_inst;
	char 	*to_free;

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

char 	*format_final(char *final)
{
	char *final_format;
	int i;
	int j;

	final_format = ft_strnew(ft_strlen(final) * 2); // change for something around 1.5 ----------- TODO
	i = 0;
	j = 0;
	while(final[i])
	{
		if (i != 0 && !(i % 32))
		{
			final_format[j++] = '\n';
		}
		else if (i != 0&& !(i % 4))
			final_format[j++] = ' ';
		final_format[j++] = final[i++];
	}
	return (final_format);
}

void	create_champion(t_env *env)
{
	int fd_cor;
	char 	**tab;
	char 	*final;

	tab = ft_tab_set(5, 0);
	tab[0] = convert_hex_octnb(env->header->magic, 4); 		// 	magic
	tab[1] = str_to_hex(env->header->prog_name); 			//	name
	tab[1] = fill_hex_be(tab[1], 128);						//	name
	tab[2] = convert_hex_octnb(env->c_adress, 8);			//	prog_size
	tab[3] = str_to_hex(env->header->comment);				//	comment
	tab[3] = fill_hex_be(tab[3], 2048);						//	comment
	tab[4] = get_full_insts(env);							//	insts

	final = ft_tab_join(tab);
	final = format_final(final);

	 //--------------- DEBUG TAB -------------
	/*ft_putstr("\nMAGIC:");
	ft_putstr(tab[0]);
	ft_putstr("\nNAME:");
	ft_putstr(tab[1]);
	ft_putstr("\nNAME LEN:");
	ft_putstr(ft_itoa(ft_strlen(tab[1]) / 2));
	ft_putstr("\nSIZE:");
	ft_putstr(tab[2]);
	ft_putstr("\nCOMMENT:");
	ft_putstr(tab[3]);
	ft_putstr("\nCOMMENT LEN:");
	ft_putstr(ft_itoa(ft_strlen(tab[3]) / 2));
	ft_putstr("\nINSTS:");
	ft_putstr(tab[4]);*/
	//ft_putstr("\nFINAL:\n");
	//ft_putstr(final);
	//-----------------------------------------
	free(tab);

	fd_cor = open (ft_strjoin(env->filename, ".cor"), O_RDWR | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH);
	write(fd_cor, final, ft_strlen(final));
}


int		main(int argc, char **argv)
{
	t_env *env;

	if (argc == 2) 
	{
		init_env(argv[1]);
		env = get_env(NULL);
		parsing_champion(env);
		create_champion(env);
	}
	else
		ft_error(EBDARG);
	
	return (0);
}
