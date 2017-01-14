#include "libft.h"

void	ft_tab_trim(char **tab)
{
	int i;
	char *tmp;

	i = -1;
	while(tab[++i])
	{
		tmp = tab[i];
		tab[i] = ft_strtrim(tab[i]);
		free(tmp);
	}
}