#include "corewar.h"

/*
* 	Set tab depend on arg_code (mem[pc + 1])   
*/

int		args_switch(unsigned char code, int *tab, int op)
{
	if (op == 1)
	{
		if (code == 0x54) 
			ft_memcpy(tab, "\x01\x00\x00\x00\x01\x00\x00\x00", 8); //set tab to int {1,1}
		else if (code == 0x64) 
			ft_memcpy(tab, "\x01\x00\x00\x00\x04\x00\x00\x00", 8); //set tab to int {1,4}
		else if (code == 0x74) 
			ft_memcpy(tab, "\x01\x00\x00\x00\x02\x00\x00\x00", 8); //set tab to int {1,2}
		else if (code == 0x94) 
			ft_memcpy(tab, "\x04\x00\x00\x00\x01\x00\x00\x00", 8); //set tab to int {4,1}
		else if (code == 0xa4) 
			ft_memcpy(tab, "\x04\x00\x00\x00\x04\x00\x00\x00", 8); //set tab to int {4,4}
		else if (code == 0xb4) 
			ft_memcpy(tab, "\x04\x00\x00\x00\x02\x00\x00\x00", 8); //set tab to int {4,2}
		else if (code == 0xd4) 
			ft_memcpy(tab, "\x02\x00\x00\x00\x01\x00\x00\x00", 8); //set tab to int {2,1}
		else if (code == 0xe4) 
			ft_memcpy(tab, "\x02\x00\x00\x00\x04\x00\x00\x00", 8); //set tab to int {2,4}
		else if (code == 0xf4) 
			ft_memcpy(tab, "\x02\x00\x00\x00\x02\x00\x00\x00", 8); //set tab to int {2,2}
		else
			return (1);
	}
	if (op == 2)
	{
		if (code == 0x54) 
			ft_memcpy(tab, "\x01\x00\x00\x00\x01\x00\x00\x00", 8); //set tab to int {1,1}
		else if (code == 0x64) 
			ft_memcpy(tab, "\x01\x00\x00\x00\x03\x00\x00\x00", 8); //set tab to int {1,3}
		else if (code == 0x94) 
			ft_memcpy(tab, "\x03\x00\x00\x00\x01\x00\x00\x00", 8); //set tab to int {3,1}
		else if (code == 0xa4) 
			ft_memcpy(tab, "\x03\x00\x00\x00\x03\x00\x00\x00", 8); //set tab to int {3,3}
		else if (code == 0xd4) 
			ft_memcpy(tab, "\x02\x00\x00\x00\x01\x00\x00\x00", 8); //set tab to int {2,1}
		else if (code == 0xe4) 
			ft_memcpy(tab, "\x02\x00\x00\x00\x03\x00\x00\x00", 8); //set tab to int {2,3}
	}
	if (op == 3)
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
			return (1);
	}
	return (0);
}