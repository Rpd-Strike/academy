int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*a;
	char	*b;

	a = (char *)s1;
	b = (char *)s2;
	while (n > 0)
	{
		if (*a != *b)
			return ((unsigned char)*a - (unsigned char)*b);
		else if (*a == '\0')
			return (0);
		a++;
		b++;
		n--;
	}
	return (0);
}