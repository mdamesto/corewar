#include "corewar.h"
#include <stdio.h> /// CARE

bool	is_alive(int nb, int *lives, int lives_nb)
{
	int i;

	i = lives_nb;
	ft_putstr("champ nb: ");
	ft_putnbr(nb);
	ft_putstr("\nTAB LIVES:");
	while (i--)
	{
		ft_putstr(" ");
		ft_putnbr(lives[i]);
	}
	ft_putstr("\n");
	
	while (lives_nb-- > 0)
	{
		if (nb == lives[lives_nb])
			return (true);
	}
	return (false);
}

bool	remove_champ(uint8_t i, t_champ **champs)
{
	t_champ *tmp;

	tmp = champs[i];
	if (!champs[1])
		return false;
	while (champs[i + 1]) 
	{
		champs[i] = champs[i + 1];
		i++;
	}
	champs[i] = NULL;
	ft_putstr(tmp->name);
	ft_putstr(" (champion nb: ");
	ft_putnbr(tmp->nb);
	ft_putstr(") died...\n");
	return (true);
}

void	check_live(t_env *env)
{
	uint8_t i;

	i = 0;
	while (env->champs[i])
	{
		if(!is_alive(env->champs[i]->nb, env->lives, env->lives_nb))
		{	
			if(!remove_champ(i, env->champs))
				i++;
		}
		else
			i++;
	}
	i = 0;
	if (env->lives_nb >= NBR_LIVE)
		env->cycle_to_die -= CYCLE_DELTA;
	
	/*free(env->lives);
	if (!(env->lives = (int *)ft_memalloc(sizeof(int) * 1000)))
		ft_error(E_MALLOC, NULL);
	env->lives_nb = 0;*/

	env->current_cycle = 0;
	if (!env->champs[1])
		env->end = true;
}


void	play_game(t_env *env)
{
	t_champ **champs;
	int8_t i;
	int8_t j;

	champs = env->champs;
	while(!env->end)
	{
		i = -1;
		while (champs[++i])
		{
			j = -1;
			while (champs[i]->process[++j])
			{
				if (!champs[i]->process[j]->wait_cycle) 
				{
					/*ft_putstr("PLAYER [");
					ft_putnbr(i + 1);
					ft_putstr("] -- Process [");
					ft_putnbr(j + 1);
					ft_putstr("] -- PC: ");
					ft_putnbr(champs[i]->process[j]->pc);
					ft_putstr("\n");*/
					if (exec_inst(champs[i]->process[j], env, i, j) == 1)
						exec_fork_lfork(i, j, env);
				}
				else
					champs[i]->process[j]->wait_cycle--;
			}
		}
		if (++env->current_cycle == env->cycle_to_die) 
		{
			ft_putstr("CHECK_LIVE\n");
			check_live(env);
			getchar();
		}

	}

	ft_putstr(env->champs[0]->name);
	ft_putstr(" (champion nb: ");
	ft_putnbr(env->champs[0]->nb);
	ft_putstr(") won the game!\n");
}
