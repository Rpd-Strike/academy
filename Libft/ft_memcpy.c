#include "includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;
	
	i = 0;
	s = (unsigned char *)dst;
	d = (unsigned char *)src;
	while (i < n)
	{
		s[i] = d[i];
		++i;
	}
	return (s);
}