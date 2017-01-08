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

/*# define EMALLOC_TXT "Error: Malloc Failed"
write(2, EMALLOC_TXT, sizeof(EMALLOC_TXT) - 1)*/


typedef struct	s_env
{
	header_t 	*header;
	char		*filename;
	int 		fd;
	int 		lc; 		//line counter 
	char		*line;		//line value
	char		**instr;		//parsed data
}				t_env;

void	ft_error(int code);
int gnl(void);

//parsing.c
char	*parsing_champion(t_env *env);

//env.c
void	init_env(char *filename);
t_env	*get_env(t_env *env);
void	free_env(void);

#endif
	