#include "corewar.h"
#include <stdio.h> /// CARE

bool	is_alive(int nb, int *lives, int lives_nb)
{
	/*int i;

	i = lives_nb;
	ft_putstr("champ nb: ");
	ft_putnbr(nb);
	ft_putstr("\nTAB LIVES:");
	while (i--)
	{
		ft_putstr(" ");
		ft_putnbr(lives[i]);
	}
	ft_putstr("\n");*/
	
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
	
	free(env->lives);
	if (!(env->lives = (int *)ft_memalloc(sizeof(int) * env->lives_tab_size)))
		ft_error(E_MALLOC, NULL);
	env->lives_nb = 0;

	env->current_cycle = 0;
	if (!env->champs[1])
		env->end = true;
}

int kbhit(void)
{
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}

void	play_game(t_env *env)
{
	t_champ **champs;
	int i;
	int j;
	//char ch;

	int lol = 0;

	champs = env->champs;
	while(/*!env->end*/1)
	{
		if (DISPLAY)
		{
			/*if (kbhit())
			{
				if (getch() == ' ')
					while ((ch = getch()) != ' ')
						;
				else
	            	render(NULL);
			}*/
	        //else 
	        //{
				i = -1;
				while (champs[++i])
				{
					j = -1;
					while (champs[i]->process[++j])
					{
						if (!champs[i]->process[j]->wait_cycle) 
						{
							if (exec_inst(champs[i]->process[j], env, i, j) == 1)
								exec_fork_lfork(i, j, env);
							//print_pc(champs[i]->process[j]->pc, champs[i]->process[j]->inc_pc, champs[i]->color, env);
							//champs[i]->process[j]->pc = MMS(champs[i]->process[j]->pc + champs[i]->process[j]->inc_pc);
							//champs[i]->process[j]->inc_pc = 0;
						}
						else
							champs[i]->process[j]->wait_cycle--;
					}
				}
				env->cycle++;
				if (++env->current_cycle > env->cycle_to_die)
					check_live(env);
				//render(env);
			//}
		}
		else
		{
			i = -1;
			while (champs[++i])
			{
				j = -1;
				while (champs[i]->process[++j])
				{
					if (!champs[i]->process[j]->wait_cycle) 
					{
						env->debug = 0;
						
						if (j == 2)
							lol++;
						if(j == 2 && lol >= 140 && lol <= 170){
							ft_putstr("\nPROCESS NB: ");
							ft_putnbr(j);
							ft_putstr("\nPROCESS PC: ");
							ft_putnbr(champs[i]->process[j]->pc);
							ft_putstr("\nNEXT OP: ");
							ft_print_memory(&(env->mem[champs[i]->process[j]->pc]), 1);
							ft_putstr("\n");

							env->debug = 1;
						}
						if (lol == 170){
							ft_print_memory(env->mem, MEM_SIZE);
							ft_putstr("\n Cycle: ");
							ft_putnbr(env->cycle);
							exit(0);
						}

						if (j == 2 || j == 0)
						{
							if (exec_inst(champs[i]->process[j], env, i, j) == 1)
								exec_fork_lfork(i, j, env);
						}
					}
					else
						champs[i]->process[j]->wait_cycle--;
				}
			}
			env->cycle++;
			if (++env->current_cycle > env->cycle_to_die)
			{
				check_live(env);
				ft_putstr("cycle to die: ");
				ft_putnbr(env->cycle_to_die);
				ft_putstr("\n");
			}
			//int reg2 = 0;
  			//ft_memcpy(&reg2, env->champs[0]->process[0]->reg[1], 4);
  			
  			//ft_print_memory(env->champs[0]->process[0]->reg[1], 4);
  			
  			//revert_endian(reg2);
  			//ft_putstr("\nreg2: ");
  			//ft_putnbr(reg2);
		}

	}

	ft_putstr(env->champs[0]->name);
	ft_putstr(" (champion nb: ");
	ft_putnbr(env->champs[0]->nb);
	ft_putstr(") won the game!\n");
	ft_putstr("cycle: ");
	ft_putnbr(env->cycle);
	if (DISPLAY)
		render(NULL);

}
