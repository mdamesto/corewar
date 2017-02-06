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
char **get_args_le(unsigned char *mem, int pc, int *tab, t_process *process)
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
			if (ret[i][0] < 1 || ret[i][0] > 16)
				return (ret = NULL);
			GET_REGV(ret[i]);
			revert_bytes(ret[i], 4);
			n++;

		}
		else if (tab[i] == 2)
		{
			ft_memcpy(ret[i], &mem[pc + 2 + n], 2);
			GET_INDV(ret[i], pc - 2);
			revert_bytes(ret[i], 4);
			n += 2;
		}
		else if (tab[i] == 3)
		{
			if (mem[pc] == 0x0a)
			{
				char tmp[2];
				short tmpnb;
				ft_memcpy(tmp, &mem[pc + 2 + n], 2);
				revert_bytes(tmp, 2);
				ft_memcpy(&tmpnb, tmp, 2);
				tmpnb = -tmpnb;
				int test = 0;
				test -= tmpnb;
				test = revert_endian(test);
				ft_memcpy(ret[i], &test, 4);
			}
			else
			{
				ft_memset(ret[i], 0x00, 2);
				ft_memcpy(&ret[i][2], &mem[pc + 2 + n], 2);
				revert_bytes(ret[i], 4);
			}
			n += 2;
		}
		else if (tab[i] == 4)
		{
			ft_memcpy(ret[i], &mem[pc + 2 + n], 4);
			revert_bytes(ret[i], 4);
			n += 4;
		}
	}
	INC_PC(n);
	return (ret);
}

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
			if (ret[i][0] < 1 || ret[i][0] > 16)
				return (ret = NULL);
			GET_REGV(ret[i]);
			n++;

		}
		else if (tab[i] == 2)
		{
			ft_memcpy(ret[i], &mem[pc + 2 + n], 2);
			GET_INDV(ret[i], pc - 2);
			n += 2;
		}
		else if (tab[i] == 3)
		{
			if (mem[pc] == 0x0a)
			{
				char tmp[2];
				short tmpnb;
				ft_memcpy(tmp, &mem[pc + 2 + n], 2);
				revert_bytes(tmp, 2);
				ft_memcpy(&tmpnb, tmp, 2);
				tmpnb = -tmpnb;
				int test = 0;
				test -= tmpnb;
				test = revert_endian(test);
				ft_memcpy(ret[i], &test, 4);
			}
			else
			{
				ft_memset(ret[i], 0x00, 2);
				ft_memcpy(&ret[i][2], &mem[pc + 2 + n], 2);
			}
			n += 2;
		}
		else if (tab[i] == 4)
		{
			ft_memcpy(ret[i], &mem[pc + 2 + n], 4);
			n += 4;
		}
	}
	INC_PC(n);
	return (ret);
}

void	cpy_from_mem(char *dst, unsigned char *mem, int siz, int pc)
{
	int ext;
	char tmp;
	int i;
	int len;

	ext = 0;
	if ((pc + siz) > MEM_SIZE)
		ext = (pc + siz) % MEM_SIZE;

	ft_memcpy(dst, &mem[pc], siz - ext);
	ft_memcpy(&dst[siz - ext], &mem[0], ext);

	//revert endian
	len = siz;
	i = -1;
	while (--len > ++i)
	{
		tmp = dst[i];
		dst[i] = dst[len];
		dst[len] = tmp;
	}

	//if siz = 2 fill withe 0x00 if + 0xff if neg
	if (siz == 2)
	{
		if ((unsigned char)dst[1] > 0x80)
			ft_memcpy(&dst[2], "\xff\xff", 2);
		else
			ft_memcpy(&dst[2], "\x00\x00", 2);
	}

	// DEBUG
	/*ft_putstr("*__FROM__\n");
	ft_putstr("siz: ");
	ft_putnbr(siz);
	ft_putstr("\npc: ");
	ft_putnbr(pc);
	ft_putstr("\npc + siz: ");
	ft_putnbr(pc + siz);
	ft_putstr("\next: ");
	ft_putnbr(ext);
	ft_putstr("\n");
	
	ft_putstr("Copying ");
	ft_putnbr(siz - ext);
	ft_putstr(" Byte from mem[");
	ft_putnbr(pc);
	ft_putstr("] to dst\n");
	if (ext) 
	{
		ft_putstr("Copying ");
		ft_putnbr(ext);
		ft_putstr(" Byte from mem[0] to dst[");
		ft_putnbr(siz - ext);
		ft_putstr("]\n");
	}*/
}

void	cpy_to_mem(unsigned char *mem, char *src, int siz, int pc)
{
	int ext;
	char tmp;
	int i;
	int len;

	//revert endian
	ft_putstr("\ncpy to mem pre revert: ");
	ft_print_memory(src, 4);
	len = siz;
	i = -1;
	while (--len > ++i)
	{
		tmp = src[i];
		src[i] = src[len];
		src[len] = tmp;
	}
	ft_putstr("\ncpy to mem post revert: ");
	ft_print_memory(src, 4);

	ext = 0;
	if ((pc + siz) > MEM_SIZE)
		ext = (pc + siz) % MEM_SIZE;
	ft_memcpy(&mem[pc], src, siz - ext);
	ft_memcpy(&mem[0], &src[siz - ext], ext);

	// DEBUG
	/*ft_putstr("*__TO__\n");
	ft_putstr("siz: ");
	ft_putnbr(siz);
	ft_putstr("\npc: ");
	ft_putnbr(pc);
	ft_putstr("\npc + siz: ");
	ft_putnbr(pc + siz);
	ft_putstr("\next: ");
	ft_putnbr(ext);
	ft_putstr("\n");
	
	ft_putstr("Copying ");
	ft_putnbr(siz - ext);
	ft_putstr(" Byte from src to mem[");
	ft_putnbr(pc);
	ft_putstr("]\n");
	if (ext)
	{
		ft_putstr("Copying ");
		ft_putnbr(ext);
		ft_putstr(" Byte from src[");
		ft_putnbr(siz - ext);
		ft_putstr("] to mem[0]\n");
	}*/
}