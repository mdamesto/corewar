#include "libft.h"

char	*fill_hex(char *tmp, size_t oct_nb) 
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