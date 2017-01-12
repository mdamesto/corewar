#include "libft.h"

static size_t	get_size(int i)
{
	size_t n;

	n = 0;
	while (i > 16)
	{
		i = i / 16;
		n++;
	}
	return (n);
} 

void	ft_strfill(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = c;
		i++;
	}
}

char			*ft_itoh_size(int nb, size_t size)
{
	/*static char const	base16[] = "0123456789abcdef";
	char 	*new;
	size_t 	s;
	int		neg = 0;

	if (nb < 0)
	{
		neg = 1;
		nb = -nb;
	}*/
	nb = 0;
	size = get_size(nb);
	return (NULL);





}