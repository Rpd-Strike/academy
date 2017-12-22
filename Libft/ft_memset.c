#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*start;
	unsigned char	val;
	size_t			i;
	
	i = 0;
	start = (unsigned char *)b;
	val = (unsigned char)c;
	while (i < len)
	{
		start[i] = val;
		i++;
	}
	return (start);
}