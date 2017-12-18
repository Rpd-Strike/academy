static int		ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

static int		bad(long long test)
{
	if (test <= 2147483647 || test >= -2147483648)
		return (0);
	return (1);
}

static int		over(long long test)
{
	if (test < -2147483648)
		return 	-2147483648;
	return 2147483647;
}

int				ft_atoi(const char *str)
{
	long long	sum;
	int			semn;

	sum = 0;
	semn = 1;
	while (ft_isspace(*str) || *str == '-' || *str == '+')
	{
		if (*str == '+' || *str == '-')
		{
			if (*str == '-')
				semn = -semn;
			str++;
			break ;
		}
		str++;
	}
	while (ft_isdigit(*str))
	{
		sum = (10 * sum) + *str - 48;
		if (bad(sum * semn))
			return over(sum * semn);
		str++;
	}
	return (sum * semn);
}