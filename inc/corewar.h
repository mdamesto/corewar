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
# include "ncurses.h"

# define E_MALLOC		1
# define E_BD_ARG 		2
# define E_BD_OPT		3
# define E_CHP_NB		4
# define E_BD_EXT		5
# define E_OPEN			6
# define E_BD_OP		7
# define E_BD_CHP_SIZ	8

# define MMS(x) (x) % MEM_SIZE
# define INC_PC(x) process->pc = MMS(process->pc + (x))
# define INV_CARRY (process->carry ? (process->carry = 0): (process->carry = 1))
# define GET_REGNB(x) hatole((x), 1) - 1
# define GET_REGV(x) ft_memcpy((x), process->reg[GET_REGNB((x))], REG_SIZE)
# define GET_INDV(x, y) cpy_from_mem((x), mem, REG_SIZE, MMS((y) + MODFIX(hatole((x), 2), IDX_MOD)))
/*
** Fix'd the C remainder to be more like a modulo op. Added (-1) in 
** negative case to handle adress[0 - 255] for 256 adresses.
*/
# define MODFIX(x, y) (((x) % (y) < 0) ? (x) % (y) + (y): (x) % (y))

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
	int 	color;
}				t_champ;

typedef struct	s_env
{
	unsigned char 		mem[MEM_SIZE];
	t_champ 	**champs;
	int			cycle_to_die;
	int 		current_cycle;
	int 		cycle;
	int			*lives;
	int 		lives_nb;
	int 		lives_tab_size;
	int			dump;
	int 		next_fixed;
	int			next_champ_nb;
	bool		end;
	int 		debug;
}				t_env;

void render(t_env *env);

//error.c
void	ft_error(int code, char *str);

//env.c
void				init_env(void);
t_env				*get_env(t_env *env);
void				free_env(void);

//convert.c
int hatole(char *str, int size);
int revert_endian(int nb);
void revert_bytes(char *str, int len);
short revert_endian_2(short nb);

//inst_tools
char **get_args(unsigned char *mem, int pc, int *tab, t_process *process);
void	cpy_from_mem(char *dst, unsigned char *src, int siz, int pc);
void	cpy_to_mem(unsigned char *dst, char *src, int siz, int pc);

//get_champ.c
void	get_champ(char *str, t_env *env);

//parse_args.c
void	parse_args(int argc, char **argv, t_env *env);

//init_process.c
void	init_process(t_env *env);
void	print_process(t_process *process);
t_process *new_process(int pc, int nb);
t_process *fork_process(int pc, t_process *process);

//play_game.c
void	play_game(t_env *env);

//exec_inst
int	exec_inst(t_process *process, t_env *env, int i, int j);

int exec_live(unsigned char *mem, int pc, t_process *process, t_env *env);
int exec_ld_lld(unsigned char *mem, int pc, t_process *process);
int exec_st(unsigned char *mem, int pc, t_process *process);
int exec_add_sub(unsigned char *mem, int pc, t_process *process);
int exec_and_or_xor(unsigned char *mem, int pc, t_process *process);
int exec_zjmp(unsigned char *mem, int pc, t_process *process);
int exec_ldi_lldi(unsigned char *mem, int pc, t_process *process);
int exec_sti(unsigned char *mem, int pc, t_process *process);
int exec_fork_lfork(int i, int j, t_env *env);
int exec_aff(unsigned char *mem, int pc, t_process *process);

//args_switch.c
int		args_switch(unsigned char code, int *tab, int op);


# define DISPLAY 1

# define DBG_CHAMP 0
# define DBG_MEM 0
# define DBG_PRCS 0

# define DBG_INSTS 0
# define DBG_STI 0
# define DBG_LIVE 0
# define DBG_LD 0
# define DBG_ST 0
# define DBG_ADD 0
# define DBG_OR 0
# define DBG_ZJMP 0
# define DBG_LDI 0
# define DBG_FORK 0
# define DBG_AFF 0

#endif
	