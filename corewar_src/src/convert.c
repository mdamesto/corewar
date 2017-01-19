#include "corewar.h"

uint32_t convert_big_endian(char *str)
{
	uint32_t n;

	n = (str[3] << 24) | (str[2] << 16) | (str[1] << 8) | str[0];
	return(n);
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