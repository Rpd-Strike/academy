char	*ft_strstr(const char *s1, const char *s2)
{
	char	*a;
	char	*b;
	char	*str;

	str = (char *)s1;
	if (*s2 == '\0')
		return ((char *)s1);
	while (*str)
	{
		a = (char *)str;
		b = (char *)s2;
		while (*b && *a == *b)
		{
			++a;
			++b;
		}
		if (*b == '\0')
			return ((char *)str);
		str++;
	}
	return (NULL);
}