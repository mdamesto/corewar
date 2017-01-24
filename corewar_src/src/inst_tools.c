#include "corewar.h"

/*
*	Get an int tab of args codes to get
*	increment pc and return an char[4] array:
*
*	1 -> Reg: copy reg nb and get it's value
*	2 -> Ind: copy adress and get memory adress value 
*	3 -> Dir(siz = 2): copy direct value and fill with 0x00
* 	4 -> Dir(siz = 4): copy direct value
*/
char **get_args(unsigned char *mem, int pc, int *tab, t_process *process)
{
	int n;
	int i;
	char **ret;
	
	n = 0; 
	if (mem[pc] == 0x0b) //skip first param in sti case
		n = 1;
	i = -1;
	ret = ft_tab_set(3, 4);
	while (++i < 2)
	{
		if (tab[i] == 1)
		{
			ft_memcpy(ret[i], &mem[pc + 2 + n], 1);
			if (tab[i] == 1 && ret[i][0] > 0x0f)
				return (ret = NULL);
			GET_REGV(ret[i]);
			n++;

		}
		else if (tab[i] == 2)
		{
			ft_memcpy(ret[i], &mem[pc + 2 + n], 2);
			GET_INDV(ret[i], pc);
			n += 2;
		}
		else if (tab[i] == 3)
		{
			ft_memset(ret[i], 0x00, 2);
			ft_memcpy(&ret[i][2], &mem[pc + 2 + n], 2);
			n += 2;
		}
		else if (tab[i] == 4)
		{
			ft_memcpy(ret[i], &mem[pc + 2 + n], 4);
			n += 4;
		}
	}
	process->pc += (2 + n);
	return (ret);
}
