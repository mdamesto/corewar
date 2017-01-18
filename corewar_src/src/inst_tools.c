#include "corewar.h"

static int		get_n(char a, char b, int size)
{
	int n;

	n = 0;
	if (a == '5') 
		n = 2;
	else if(a == 'a')
		n = 2 * size;
	else if (a == 'f')
		n = 4;
	else if (a == '6' || a == '9')
		n = 1 + size;
	else if (a == '7' || a == 'd')
		n = 3;
	else if (a == 'b' || a == 'e')
		n = 2 + size;
	if (b == '4')
		n += 1;
	else if (b == '8')
		n += size;
	else if (b == 'c')
		n += 2;
	return ((n + 2) * 2);
}

int 			get_inst_len(char *str)
{
	int n;

	n = 0;
	if(str[0] == '1' && str[1] == '0')
			n += 4;
	else if(str[0] == '0' && ft_ishex(str[1]))
	{
		if(str[1] == '1' )
			n += 10;
		else if (str[1] == '9' || str[1] == 'c' || str[1] == 'f')
			n += 6;
		else if(str[1] == '4' || str[1] == '5')
			n += 10;
		else if (str[1] == 'a' || str[1] == 'b' || str[1] == 'e' || str[1] == '3') //op for wich size direct = 2
			n += get_n(str[2], str[3], 2);
		else if (str[1] == '2' || str[1] == '6' || str[1] == '7' || str[1] == '8' || str[1] == 'd') //op for wich size direct = 4
			n += get_n(str[2], str[3], 4);
	}
	else
		ft_error(E_BD_OP, NULL);
	return (n);

}