#include "asm.h"
#include <stdio.h>
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

uint32_t	convert_be(uint32_t data)
{
	uint32_t	ret;

	ret = (uint32_t)((data << 24) | ((data >> 8) << 16) | ((data >> 16) << 8) | (data >> 24));
	return (ret); 
}

#define ABS(x) (((x) < 0) ? -(x) : (x))

void			create_champion(t_env *env)
{
	int		fd_cor;
	char	**tab;
	char	*final;
	uint8_t	header[sizeof(header_t)];
	//char	name[] = "stayin' alive";
	//char	comment[] = "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive";
	ft_memset(&header[0], 0x42, sizeof(header_t));
	ft_putstr("\n HERE :   ");
	ft_putstr(env->header->prog_name);
	printf("HERE: %zu: %s\n", ft_strlen(env->header->prog_name), env->header->prog_name); fflush(NULL);
	ft_memcpy(&header[0], "\x00\xEA\x83\xF3", 4);
	size_t siz = ft_strlen(env->header->prog_name);
	ft_memcpy(&header[4], env->header->prog_name, siz);
	printf("Writing '%s', siz: %zu\n", env->header->prog_name, siz); fflush(NULL);
	ft_memset(&header[siz + 4], '\0', PROG_NAME_LENGTH - siz + 4);
	printf("Memsetting from %p/%c, siz: %zu\n", &header[siz + 4], header[siz + 4], (size_t)(PROG_NAME_LENGTH - siz + 4)); fflush(NULL);
	uint32_t yolo = convert_be(env->c_adress);
	ft_memcpy(&header[PROG_NAME_LENGTH + 8], &yolo, 4);
	printf("Writing '%u' at %p, siz: %zu\n", yolo, &header[PROG_NAME_LENGTH + 8], (size_t)4); fflush(NULL);
	siz = ft_strlen(env->header->comment);
	ft_memcpy(&header[PROG_NAME_LENGTH + 12], env->header->comment, siz);
	printf("Writing '%s', siz: %zu\n", env->header->comment, siz); fflush(NULL);
	ft_memset(&header[PROG_NAME_LENGTH + 12 + siz], '\0', COMMENT_LENGTH - siz + 4);
	printf("Memsetting from %p/%c, siz: %zu\n", &header[PROG_NAME_LENGTH + 12 + siz], header[PROG_NAME_LENGTH + 12 + siz], (size_t)(COMMENT_LENGTH - siz)); fflush(NULL);
	//ft_memcpy(&header[PROG_NAME_LENGTH + COMMENT_LENGTH + 8], env->data, env->data_siz)



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
	
	fd_cor = open (ft_strjoin(env->filename, ".cor"), O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	write(fd_cor, &header[0], sizeof(header_t));
	
	//write(fd_cor, final, ft_strlen(final));

	
	ft_putstr("\nChampion created: ");
	ft_putstr(ft_strjoin(env->filename, ".cor"));
	ft_putstr("\n");
	//print_champ(tab,final); //------ CHAMPION -------//
}
