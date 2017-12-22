#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	int		i;
	int		j;
	char	*s2;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) - 1;
	i = 0;
	j = 0;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	if (len > 0)
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
	s2 = ft_strnew(len - i + 1);
	if (!s2)
		return (NULL);
	while (j < len - i + 1)
	{
		s2[j] = s[i + j];
		j++;
	}
	return (s2);
}