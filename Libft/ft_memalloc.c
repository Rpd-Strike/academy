#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*pt;

	pt = malloc(size);
	if (!pt)
		return (NULL);
	ft_memset(pt, 0, size);
	return (pt);
}