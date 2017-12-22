#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*s2;
	int			i;

	i = 0;
	if (s == NULL)
		return (0);
	s2 = ft_strnew(len);
	if (s2 == NULL)
		return (0);
	while (len > 0)
	{
		s2[i] = s[start + i];
		++i;
		--len;
	}
	return (s2);
}