#include "libft.h"

char	*ft_tab_join(char **tab)
{
	int i;
	char *str;
	char *tmp;
	
	str = ft_strnew(ft_strlen(tab[0]));
	ft_strcpy(str, tab[0]);
	i = 1;
	while(tab[i])
	{
		tmp = str;
		str = ft_strjoin(str, tab[i]);
		free(tmp);
		i++;
	}
	return (str);
}