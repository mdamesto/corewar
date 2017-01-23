#include "corewar.h"

bool	is_alive(int nb, int *lives, int lives_nb)
{
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
					//ft_putstr("\nexec instr: ");
					if (exec_inst(champs[i]->process[j], env) == 1)
						exec_fork_lfork(i, j, env);
				}
				else
					champs[i]->process[j]->wait_cycle--;
			}
		}
		if (++env->current_cycle == env->cycle_to_die) {
			check_live(env);
		}

	}

	ft_putstr(env->champs[0]->name);
	ft_putstr(" (champion nb: ");
	ft_putnbr(env->champs[0]->nb);
	ft_putstr(") won the game!\n");
}
