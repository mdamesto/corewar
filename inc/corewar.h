/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
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

# define E_MALLOC		1
# define E_BD_ARG 		2
# define E_BD_OPT		3
# define E_CHP_NB		4
# define E_BD_EXT		5
# define E_OPEN			6
# define E_BD_OP		7


typedef struct	s_champ
{
	char 	*filename;
	char	*name;
	char	*size;
	char 	*comment;
	char 	**inst;
	int 	nb;
}				t_champ;

typedef struct	s_env
{
	char 	*mem;
	t_champ **champs;
	int		current_ctd;
	int		*lives;	
	int		dump;
	int		next_champ_nb;
}				t_env;

//error.c
void	ft_error(int code, char *str);

//env.c
void				init_env(void);
t_env				*get_env(t_env *env);
void				free_env(void);

//convert.c
char *hex_to_str(char *hex);
char *hex_to_prog_size(char *hex);

//inst_tools
int 	get_inst_len(char *str);

//get_champ.c
void	get_champ(char *str, t_env *env);

//parse_args.c
void	parse_args(int argc, char **argv);

#endif
	