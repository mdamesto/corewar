#include "corewar.h"

/*char **get_args(unsigned char *mem, int a, int b, int c)
{
	char **ret;

	ret = ft_tab_set(3, 4);
	ft_memcpy(ret[0], mem, a);
	if (b)
		ft_memcpy(ret[1], &mem[a], b);
	if (c)
		ft_memcpy(ret[2], &mem[a + b], c);
	
	if (a == 1 && (hatole(ret[0], 1) < 1 || hatole(ret[0], 1) > 16))
		ret = NULL;
	if (b == 1 && (hatole(ret[1], 1) < 1 || hatole(ret[1], 1) > 16))
		ret = NULL;
	if (c == 1 && (hatole(ret[2], 1) < 1 || hatole(ret[2], 1) > 16))
		ret = NULL;

	return (ret);
}*/

# define GET_REGV(x) ft_memcpy((x), process->reg[hatole((x), 1) -1], REG_SIZE);
# define GET_INDV(x, y) ft_memcpy((x), &mem[(y) + (hatole((x), 2) % IDX_MOD)], REG_SIZE);

char **get_args2(unsigned char *mem, int pc, int *tab, t_process *process)
{
	int i;
	int n;
	char **ret;
	
	i = -1;
	n = 0;
	ret = ft_tab_set(3, 4);
	while (++i < 2)
	{
		if (tab[i] == 1)
		{
			ft_memcpy(ret[i], &mem[pc + 2 + n], tab[i]);
			if (tab[i] == 1 && (hatole(ret[i], 1) < 1 || hatole(ret[i], 1) > 16))
				return (ret = NULL);
			GET_REGV(ret[i]);
			n++;

		}
		else if (tab[i] == 2)
		{
			ft_memcpy(ret[i], &mem[pc + 2 + n], tab[i]);
			GET_INDV(ret[i], pc);
			n += 2;
		}
		else if (tab[i] == 4)
		{
			ft_memcpy(ret[i], &mem[pc + 2 + n], tab[i]);
			n += 4;
		}
	}
	process->pc += (2 + n);
	return (ret);
}

int exec_and(unsigned char *mem, int pc, t_process *process)
{
	char 		**args;
	uint32_t	and;
	int 		tab[2];

	args = NULL;
	ft_putstr("--------- In exec_and (exec_inst.c) ----------\n");
	
	// Set tab depend on arg_code
	if (mem[pc + 1] == 0x54) 
		ft_memcpy(tab, "\x01\x00\x00\x00\x01\x00\x00\x00", 8); //set tab to int {1,1}
	else if (mem[pc + 1]== 0x64) 
		ft_memcpy(tab, "\x01\x00\x00\x00\x04\x00\x00\x00", 8); //set tab to int {1,4}
	else if (mem[pc + 1]== 0x74) 
		ft_memcpy(tab, "\x01\x00\x00\x00\x02\x00\x00\x00", 8); //set tab to int {1,2}
	else if (mem[pc + 1]== 0x94) 
		ft_memcpy(tab, "\x04\x00\x00\x00\x01\x00\x00\x00", 8); //set tab to int {4,1}
	else if (mem[pc + 1]== 0xa4) 
		ft_memcpy(tab, "\x04\x00\x00\x00\x04\x00\x00\x00", 8); //set tab to int {4,4}
	else if (mem[pc + 1]== 0xb4) 
		ft_memcpy(tab, "\x04\x00\x00\x00\x02\x00\x00\x00", 8); //set tab to int {4,2}
	else if (mem[pc + 1]== 0xd4) 
		ft_memcpy(tab, "\x02\x00\x00\x00\x01\x00\x00\x00", 8); //set tab to int {2,1}
	else if (mem[pc + 1]== 0xe4) 
		ft_memcpy(tab, "\x02\x00\x00\x00\x04\x00\x00\x00", 8); //set tab to int {2,4}
	else if (mem[pc + 1]== 0xf4) 
		ft_memcpy(tab, "\x02\x00\x00\x00\x02\x00\x00\x00", 8); //set tab to int {2,2}
	else
	{
		process->pc += 2;
		exit(0);
		return (1);
	}

	//	get arg[0] & arg[1] based on tab. 
	//	Ex: tab = {1, 4} ===> args[0] = GET_REGV(REG) && args[1] = DIR ) 
	if (!(args = get_args2(mem, pc, &tab[0], process)))
	{
			exit(0);
			return (1);
	}

	//	Get args3 -> reg
	ft_memcpy(args[2], &mem[pc + 2 + tab[0] + tab[1]], 1);

	//	Use the binary op depend on op_code
	if (mem[pc] == 0x06)
		and = *(int*)args[0] & *(int*)args[1];
	else if (mem[pc] == 0x07)
		and = *(int*)args[0] | *(int*)args[1];
	else if (mem[pc] == 0x08)
		and = *(int*)args[0] ^ *(int*)args[1];

	//	Copy result in args[3] (REG)
	ft_memcpy(process->reg[hatole(args[2], 1) - 1], &and, REG_SIZE);
	
	// DEBUG
	ft_print_memory(args[0], 4);
	ft_print_memory(args[1], 4);
	ft_print_memory(&and, 4);
	ft_print_memory(process->reg[hatole(args[2], 1) - 1], 4);
	
	exit(0);
	return (0);
}