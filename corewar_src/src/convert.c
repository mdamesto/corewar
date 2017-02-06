#include "corewar.h"

void	hex_2_to_le(char *str)
{
	short tmpshort;
	int tmpint;
	char tmp;
	
	tmpint = 0;
	tmp = str[0];
	str[0] = str[1];
	str[1] = tmp;
	ft_memcpy(&tmpshort, str, 2);
	tmpint += tmpshort;
	ft_memcpy(str, &tmpint, 4);
}

void	hex_4_to_le(char *str)
{
	char tmp;
	 tmp = str[0];
	 str[0] = str[3];
	 str[3] = tmp;
	 tmp = str[1];
	 str[1] = str[2];
	 str[2] = tmp;
}

int	hex_2_to_int_le(char *str)
{
	short tmpshort;
	int tmpint;
	char tmp;
	
	tmpint = 0;
	tmp = str[0];
	str[0] = str[1];
	str[1] = tmp;
	ft_memcpy(&tmpshort, str, 2);
	tmpint += tmpshort;
	
	return (tmpint);
}

int	hex_4_to_int_le(char *str)
{
	char tmp;
	int ret;

	tmp = str[0];
	str[0] = str[3];
	str[3] = tmp;
	tmp = str[1];
	str[1] = str[2];
	str[2] = tmp;
	
	ft_memcpy(&ret, str, 4);
	return (ret); 
}

int	hex_to_int(char *str)
{
	int ret;

	ft_memcpy(&ret, str, 4);
	return (ret); 
}

int hatole(char *str, int siz)
{
	int n;

	n = 0;
	if (siz == 1)
		n = str[0];
	else if(siz == 2)
	{
		n = ((str[0] << 8) & 0xff00) |
			((str[1]) & 0xff);
	}
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

short revert_endian_2(short nb)
{
	char str[2];
	char tmp;

	ft_memcpy(str, &nb, 2);
	tmp = str[0];
	str[0] = str[1];
	str[1] = tmp;
	ft_memcpy(&nb, str, 2);
	return (nb);
}

void revert_bytes(char *str, int len)
{
	char tmp;
	int i;

	i = -1;
	while (--len > ++i)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
	}
}



