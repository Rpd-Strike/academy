#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	val;
	unsigned char	*v;

	val = (unsigned char)c;
	v = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (v[i] == val)
			return (v + i);
		i++;
	}
	return (0);
}