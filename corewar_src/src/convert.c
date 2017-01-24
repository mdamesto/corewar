#include "corewar.h"

int hatole(char *str, int siz)
{
	int n;

	n = 0;
	if (siz == 1)
		n = str[0];
	else if(siz == 2)
		n = ((str[0] << 8) & 0xff00) |
			((str[1]) & 0xff);
	else if(siz == 4)
		n = ((str[0] << 24) & 0xff000000) | 
			((str[1] << 16) & 0xff0000) | 
			((str[2] << 8) & 0xff00)| 
			((str[3]) & 0xff);
	return(n);
}

int revert_endian(int nb)
{
	char str[4];
	char tmp2;
	char tmp3;

	ft_memcpy(str, &nb, 4);
	tmp3 = str[0];
	tmp2 = str[1];
	str[0] = str[3];
	str[1] = str[2];
	str[2] = tmp2;
	str[3] = tmp3;
	ft_memcpy(&nb, str, 4);
	return (nb);
}
