/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 19:12:52 by mdamesto          #+#    #+#             */
/*   Updated: 2016/02/14 18:35:29 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR
# define COREWAR

# include "libft.h"
# include "op.h"

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

/*# define EMALLOC_TXT "Error: Malloc Failed"
write(2, EMALLOC_TXT, sizeof(EMALLOC_TXT) - 1)*/


typedef struct		s_label
{
	char			*name;
	int 			adress;
	struct s_label 	*next;
}					t_label;

typedef struct	s_env
{
	header_t 	*header;
	t_label 	*labels;
	char		*filename;
	int 		fd;
	int 		line_nb; 		//line counter
	int 		c_adress; 
	char		*line;		//line value
	int 		inst_nb;
	char 		**data; 		//tmp splitted line
	char		**inst;		//parsed data
}				t_env;

void	ft_error(int code);

//gnl.c
int gnl(void);

//parsing.c
char	*parsing_champion(t_env *env);

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
char	*get_dir(char *arg, int size);
char 	*get_reg(char *arg);
char 	*get_ind(char *arg); 

//inst.c
void	add_inst(char *inst, char *args_code, char **args);
char	*ret_to_oct(char *tmp, int oct_nb);
char	**init_args(void);
void	print_inst(t_env *env);

void	live_zjump_fork_lfork(char **data, int i);
void	add_sub_and_or_xor(char **data, int i);
void	ld_lld(char **data, int i); 
void	st(char **data, int i);
void	aff(char **data, int i);




#endif
	