#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int			i;
	char		*s2;

	i = 0;
	if (s == NULL || f == NULL)
		return (0);
	s2 = ft_strnew(ft_strlen(s));
	if (!s2)
		return (0);
	while (s[i] != '\0')
	{
		s2[i] = f(s[i]);
		i++;
	}
	return (s2);
}