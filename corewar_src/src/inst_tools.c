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
			cpy_from_mem(ret[i], mem, 1, pc + 2 + n);
			if (ret[i][0] < 0 || ret[i][0] > 15)
				return (ret = NULL);
			ft_memcpy(ret[i], process->reg[INT ret[i]], REG_SIZE);
			n++;

		}
		else if (tab[i] == 2)
		{
			cpy_from_mem(ret[i], mem, IND_SIZE, pc + 2 + n);
			cpy_from_mem(ret[i], mem, REG_SIZE, pc + INT ret[i]);
			n += IND_SIZE;
		}
		else if (tab[i] == 3)
		{
			cpy_from_mem(ret[i], mem, IND_SIZE, pc + 2 + n);
			n += IND_SIZE;
		}
		else if (tab[i] == 4)
		{
			/*n += */cpy_from_mem(ret[i], mem, REG_SIZE, pc + 2 + n);
			n += DIR_SIZE;
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

	pc = MODFIX(pc, MEM_SIZE);
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

	//if siz = 1 || 2 fill withe 0x00 if + 0xff if neg
	if (siz == 1)
	{
		if ((unsigned char)dst[0] > 0x80)
			ft_memcpy(&dst[1], "\xff\xff\xff", 2);
		else
			ft_memcpy(&dst[1], "\x00\x00\x00", 2);
		dst[0]--; //decrementent reg since reg 1 is stored in reg[0], ect...
	}
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

void	cpy_to_mem(unsigned char *mem, char *src, int pc, t_process *process)
{
	int i;
	int ext;
	char tmp[4];

	pc = MODFIX(pc, MEM_SIZE);
	
	//revert endian
	i = -1;
	while (++i < 4)
		tmp[i] = src[3 - i];

	ext = 0;
	if ((pc + 4) > MEM_SIZE)
		ext = (pc + 4) % MEM_SIZE;
	ft_memcpy(&mem[pc], tmp, 4 - ext);
	ft_memcpy(&mem[0], &tmp[4 - ext], ext);

	if (DISPLAY)
		print_inst(tmp, pc, process->champ->color);

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