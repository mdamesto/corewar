#include "libft.h"

int		ft_isspace(char c) {
	return ((c <= '\r' && c >= '\t') || c == ' ');
}