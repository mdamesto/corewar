#include "corewar.h"

char	*str_to_hex(char *str)
{
	char **tab;
	char *hex;
	int i;

	tab = ft_tab_set(ft_strlen(str), 0);
	i = -1;
	while (str[++i])
		tab[i] = convert_hex_octnb((int)str[i], 1);
	hex = ft_tab_join(tab);
	ft_tab_free(tab);
	return (hex);
}

char	*ret_to_oct(char *tmp, int oct_nb) 
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