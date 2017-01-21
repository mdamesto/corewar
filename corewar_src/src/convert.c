#include "corewar.h"

int atole(char *str)
{
	int n;

	n = (str[3] << 24) | (str[2] << 16) | (str[1] << 8) | str[0];
	return(n);
}

int hatole(char *str, int siz)
{
	int n;

	n = 0;
	if (siz == 1)
		n = str[0];
	else if(siz == 2)
		n = (str[1]) | str[0] << 8;
	else if(siz == 4)
		n = (str[3] << 24) | (str[2] << 16) | (str[1] << 8) | str[0];
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

/*char *hex_to_str(char *hex)
{
	char tmp[2048];
	int i;
	int code;
	char *ret;

	i = 0;
	while (hex[i])
	{
		code = 0;
		if (ft_isdigit(hex[i])) {
			code = (hex[i] - '0') * 16;
		}
		else{
			code = (hex[i] - 'a' + 10) * 16;
		}
		if (ft_isdigit(hex[i + 1]))
			code = code + hex[i + 1] - '0';
		else
			code = code + hex[i + 1] - 'a' + 10;
		tmp[i / 2] = code;
		i += 2;
	}
	ret = ft_strnew(ft_strlen(tmp));
	ft_strcpy(ret, tmp);
	return (ret);
}

char *hex_to_prog_size(char *hex)
{
	int len;
	int size;
	int mult;

	len = ft_strlen(hex); // always 16?
	size = 0;
	mult = 1;
	while (--len >= 12)
	{
		if (ft_isdigit(hex[len])) {
			size = size + (hex[len] - '0') * mult;
		}
		else{
			size = size + (hex[len] - 'a' + 10) * mult;
		}
		mult *= 16;
	}
	return (ft_itoa(size));
}*/