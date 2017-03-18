/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 19:12:52 by mdamesto          #+#    #+#             */
/*   Updated: 2016/02/14 18:35:29 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM
# define ASM

# include "libft.h"
# include "op.h"
# include <stdint.h>

# define EBDARG			1
# define EOPEN			2
# define EMALLOC    	3
# define EGNL 			4
# define EEMPTYFILE 	5
# define ENONAME		6
# define ENOCOM			7
# define EPARSING		8
# define EBDINST		9
# define E_ARG_NB		10
# define E_BD_REG		11
# define E_BD_ARG		12
# define E_BD_DIR		13
# define E_BD_IND		14
# define E_UK_LBL		15
# define E_BD_LBL		16
# define E_BD_CHP		17
# define E_NM_LEN		18
# define E_CM_LEN		19	

/*# define EMALLOC_TXT "Error: Malloc Failed"
write(2, EMALLOC_TXT, sizeof(EMALLOC_TXT) - 1)*/


typedef struct		s_label
{
	char			*name;
	int 			adress;
	struct s_label 	*next;
}					t_label;

typedef struct		s_instr
{
	char			*content;
	int 			adress;
	int 			line;
	struct s_instr 	*next;
}					t_inst;

typedef struct	s_env
{
	header_t 	*header;
	t_label 	*labels;
	t_inst		*inst;
	char		*filename;
	int 		fd;
	int 		line_nb;
	uint32_t	c_adress;
	int 		add_to_adress;
	char		*line;		//line value
	char 		**data; 		//tmp splitted line
}				t_env;

//inst.c
void	inst_to_env(char *inst, char *args_code, char **args);
char	**init_args(void);

void	live_zjump_fork_lfork(char *data, char *inst, size_t siz);
void	add_sub(char *data, char *inst);
void	ld_lld(char *data, char *inst);
void	or_xor_and(char *data, char *inst);
void	ldi_lldi(char *data, char *inst);
void	sti(char *data, char *inst);
void	st(char *data, char *inst);
void	aff(char *data, char *inst);


void	ft_error(int code);

//gnl.c
int gnl(void);
int 	check_empty_line(char *line);

//parsing.c
void	parsing_champion(t_env *env);

//env.c
void	init_env(char *filename);
t_env	*get_env(t_env *env);
void	free_env(void);

//name_comment.c
void	get_name(t_env *env);
void	get_comment(t_env *env);

//label.c
void	print_labels(t_env *env);
void	add_label(t_env *env, char *label);
void	replace_labels(t_env *env);

//check_arg.c
int		check_arg(char *arg);

//get_arg.c
char	*get_dir(char *arg, int size);
char 	*get_reg(char *arg);
char 	*get_ind(char *arg); 

//print
void	print_name_comment(t_env *env);
void	print_add_inst(char *inst, char *args_code, char **args);
void	print_labels(t_env *env);
void	print_inst(t_env *env);
void	print_champ(char **tab, char *final);

//create champ
void			create_champion(t_env *env);

//convert
char	*str_to_hex(char *str);
char	*ret_to_oct(char *tmp, int oct_nb);

//inst_switch
void	inst_switch(char **data);

#endif
	