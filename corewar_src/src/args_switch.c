#include "corewar.h"

/*
* 	Set tab depend on arg_code (mem[pc + 1])   
*/

int		args_switch(char code, int *tab, t_process *process, int op)
{
	int inc;

	inc = 0;
	if (op == 1)
	{
		if (code == 0x54) 
			ft_memcpy(tab, "\x01\x00\x00\x00\x01\x00\x00\x00", 8); //set tab to int {1,1}
		else if (code == 0x58)
			ft_memcpy(tab, "\x01\x00\x00\x00\x03\x00\x00\x00", 8); //set tab to int {1,3}
		else if (code == 0x64) 
			ft_memcpy(tab, "\x03\x00\x00\x00\x01\x00\x00\x00", 8); //set tab to int {3,1}
		else if (code == 0x68) 
			ft_memcpy(tab, "\x03\x00\x00\x00\x03\x00\x00\x00", 8); //set tab to int {3,3}
		else if (code == 0x74) 
			ft_memcpy(tab, "\x02\x00\x00\x00\x01\x00\x00\x00", 8); //set tab to int {2,1}
		else if (code == 0x78) 
			ft_memcpy(tab, "\x02\x00\x00\x00\x03\x00\x00\x00", 8); //set tab to int {2,3}
		else
			inc += 2;
	}

	if (inc)
	{
		INC_PC(inc);
		return (1);
	}
	return (0);
}