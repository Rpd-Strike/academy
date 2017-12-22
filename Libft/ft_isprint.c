#include "libft.h"

int	ft_isprint(int c)
{
	if (c == ' ' || (c >= 33 && c <= 126))
		return (1);
	return (0);
}