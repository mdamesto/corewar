#include "libft.h"

char	*ft_strcut(char *str, int s, int e)
{
	char *ret;
	int i;
	int j;

	if(!str || !(ret = ft_strnew(ft_strlen(str) - (e - s))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < s)
		ret[j++] = str[i];
	while (++i < e - 1)
		;
	while (str[++i])
		ret[j++] = str[i];
	return (ret);
}

char	*ft_strcut_f(char *str, int s, int e)
{
	char *ret;
	int i;
	int j;

	if(!str || !(ret = ft_strnew(ft_strlen(str) - (e - s))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < s)
		ret[j++] = str[i];
	while (++i < e - 1)
		;
	while (str[++i])
		ret[j++] = str[i];
	free(str);
	return (ret);
}
