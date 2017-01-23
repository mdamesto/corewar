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
# define E_BD_CHP_SIZ	8

# define GET_REGNB(x) hatole((x), 1) - 1
# define GET_REGV(x) ft_memcpy((x), process->reg[GET_REGNB((x))], REG_SIZE)
# define GET_INDV(x, y) ft_memcpy((x), &mem[(y) + (hatole((x), 2) % IDX_MOD)], REG_SIZE)
/*
** Fix'd the C remainder to be more like a modulo op. Added (-1) in 
** negative case to handle adress[0 - 255] for 256 adresses.
*/
# define MODFIX(x, y) (((x) % (y) < 0) ? (x) % (y) + (y - 1): (x) % (y))

typedef struct	s_process
{
	int 	pc;
	char 	**reg;
	short	carry;
	int 	wait_cycle;

}				t_process;

typedef struct	s_champ
{
	char	name[PROG_NAME_LENGTH + 1];
	int		size;
	char 	comment[COMMENT_LENGTH + 1];
	char 	inst[CHAMP_MAX_SIZE + 1];
	int 	nb;
	t_process **process;
	bool	alive;
}				t_champ;

typedef struct	s_env
{
	unsigned char 		mem[MEM_SIZE];
	t_champ 	**champs;
	int			cycle_to_die;
	int 		current_cycle;
	int			*lives;
	int 		lives_nb;
	int			dump;
	int			next_champ_nb;
	bool		end;
}				t_env;

//error.c
void	ft_error(int code, char *str);

//env.c
void				init_env(void);
t_env				*get_env(t_env *env);
void				free_env(void);

//convert.c
//char *hex_to_str(char *hex);
//char *hex_to_prog_size(char *hex);
int hatole(char *str, int size);
int revert_endian(int nb);

//inst_tools
//int 	get_inst_len(char *str);
char **get_args(unsigned char *mem, int pc, int *tab, t_process *process);

//get_champ.c
void	get_champ(char *str, t_env *env);

//parse_args.c
void	parse_args(int argc, char **argv, t_env *env);

//init_champs.c
void	init_champs(t_env *env);

//play_game.c
void	play_game(t_env *env);

//exec_inst
int	exec_inst(t_process *process, t_env *env);

int exec_live(unsigned char *mem, int pc, t_process *process, t_env *env);
int exec_ld(unsigned char *mem, int pc, t_process *process);
int exec_st(unsigned char *mem, int pc, t_process *process);
int exec_add_sub(unsigned char *mem, int pc, t_process *process);
int exec_and_or_xor(unsigned char *mem, int pc, t_process *process);
int exec_zjmp(unsigned char *mem, int pc, t_process *process);
int exec_ldi_lldi(unsigned char *mem, int pc, t_process *process);
int exec_sti(unsigned char *mem, int pc, t_process *process);
int exec_fork_lfork(int i, int j, t_env *env);

#endif
	