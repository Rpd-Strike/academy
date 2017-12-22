#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	char	*s;

	s = (char *)s2;
	i = 0;
	while (s1[i])
		i++;
	while (*s)
	{
		s1[i] = *(s++);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}