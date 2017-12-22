#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	cc;
	unsigned char	*d;

	i = 0;
	cc = (unsigned char)c;
	d = (unsigned char *)dst;
	while (i < n)
	{
		d[i] = ((char *)src)[i];
		++i;
		if (d[i - 1] == cc)
			return (&d[i]);
	}
	return (NULL);
}