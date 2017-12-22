#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	c2;

	c2 = (char)c;
	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0 && s[i] != c2)
		i--;
	if (i < 0)
		return (NULL);
	else
		return ((char *)s + i);
}