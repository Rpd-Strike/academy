#include "libft.h"

static	int		strleng(char *str)
{
	int i;
	int count;

	count = 0;
	i = -1;
	while (str[++i])
	{
		count++;
	}
	return (count);
}

static	void	schimba(char *a, char *b)
{
	char c;

	c = *a;
	*a = *b;
	*b = c;
}

char			*ft_strrev(char *str)
{
	int len;
	int c;

	c = 0;
	len = strleng(str) - 1;
	while (c < len)
	{
		schimba(&str[c], &str[len]);
		c++;
		len--;
	}
	return (str);
}