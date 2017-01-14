#include "libft.h"

int 	ft_bin_to_int(char *str)
{
	int len;
	int ret;
	int mult;

	len = ft_strlen(str) - 1;
	ret = 0;
	mult = 1;
	while (len >= 0)
	{
		ret += (str[len--] - '0') * mult;
		mult = mult * 2;
	}
	return (ret);
}