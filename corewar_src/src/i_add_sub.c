#include "corewar.h"

/*unsigned int add(unsigned int a, unsigned int b)
{
	unsigned int carry;
    unsigned int result;
    unsigned int shiftedcarry;

    carry = a & b;
    result = a ^ b;
    while(carry != 0)
    {
        shiftedcarry = carry << 1;
        carry = result & shiftedcarry;
        result ^= shiftedcarry;
    }
    return (result);
}*/

int exec_add_sub(unsigned char *mem, int pc, t_process *process)
{
	char arg1[REG_SIZE];
	char arg2[REG_SIZE];
	char arg3[1];
	int i;

	if (mem[pc + 1] == 0x54)
	{
		// get arg_nb and store it into arg1/2/3
		ft_memcpy(arg1, &mem[pc + 2], 1);
		ft_memcpy(arg2, &mem[pc + 3], 1);
		ft_memcpy(arg3, &mem[pc + 4], 1);
		if ((*arg1 <= 0x10 || *arg1 >= 0x01) && (*arg1 <= 0x10 || *arg1 >= 0x01)\
		 	&& (*arg1 <= 0x10 || *arg1 >= 0x01))
		{
			// replace arg_nb by it's value in arg1/2
			ft_memcpy(arg1, process->reg[hatole(arg1, 1) - 1], REG_SIZE);
			ft_memcpy(arg2, process->reg[hatole(arg2, 1) - 1], REG_SIZE);
			if (mem[pc] == 0x04)
				i = hatole(arg1, 4) + hatole(arg2, 4);
			if (mem[pc] == 0x05)
				i = hatole(arg1, 4) - hatole(arg2, 4);
			// store reverted endian value of arg1 (+ or -) arg2 in reg[arg3]
			i = revert_endian(i);
			ft_memcpy(process->reg[hatole(arg3, 1) - 1], &(i), REG_SIZE);
		}
		else
		{
			process->pc += 5;
			exit(0);
			return (1);
		}
	}
	else
	{
		process->pc += 2;
		exit(0);
		return (1);
	}
	process->wait_cycle = 10; 
	process->pc += 5;
	
	ft_putstr("--------- In exec_add_sub() (exec_inst.c) ----------\n");
	ft_putstr("\nprocess->reg[");
	ft_putnbr(hatole(arg3, 1));
	ft_putstr("]: ");
	ft_print_memory(process->reg[hatole(arg3, 1) - 1], REG_SIZE);

	exit(0);
	return (0);
}