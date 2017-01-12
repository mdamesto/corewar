#include "corewar.h"

static char	*fill_hex(char *tmp, size_t oct_nb) 
{
	int i;
	char *ret;
	int ret_len;
	int tmp_len;

	ret_len = (oct_nb * 2);
	ret = ft_strnew(ret_len);
	i = 0;
	while (i < ret_len)
		ret[i++] = '0';
	tmp_len = ft_strlen(tmp);

	i = 0;
	ret_len = ret_len - tmp_len;
	while ( i < tmp_len) {
		ret[ret_len + i] = tmp[i];
		i++;
	}
	return (ret);
}

char	*convert_hex_octnb(int nb, size_t oct_nb)
{
	char *hex;

	hex = NULL;
	if (nb < 0) 
	{
		if (oct_nb == 1)
			hex = ft_itoa_base(256 + nb, 16);
		else if (oct_nb == 2)
			hex = ft_itoa_base(65536 + nb, 16);
		else if (oct_nb == 4)
			hex = ft_itoa_base(4294967296 + nb, 16);
	}
	else
		hex = fill_hex(hex = ft_itoa_base(nb, 16), oct_nb);
	return (hex);

}