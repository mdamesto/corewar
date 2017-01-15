#include "libft.h"

int 	ft_is_label_char(char c)
{
	int i;
	char *label_char = "abcdefghijklmnopqrstuvwxyz_0123456789";

	i = -1;
	while(label_char[++i])
	{
		if (label_char[i] == c)
			return (1);
	}
	return (0);
}