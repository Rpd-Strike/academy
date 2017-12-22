#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = (dest > src) ? n : 1;
	n = (dest > src) ? 0 : n + 1;
	while (i != n)
	{
		((char *)dest)[i - 1] = ((const char *)src)[i - 1];
		i = (dest > src) ? i - 1 : i + 1;
	}
	return (dest);
}