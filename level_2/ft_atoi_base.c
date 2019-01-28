int		is_base(char c, int base)
{
	char	*base_min;
	char	*base_maj;

	base_min = "0123456789abcedf\0";
	base_maj = "0123456789ABCDEF\0";
	while (base--)
	{
		if (base_maj[base] == c || base_min[base] == c)
			return(1);
	}
	return (0);
}

int		value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 10);
	return (0);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int ret;
	int minus;

	ret = 0;
	minus = 1;
	while (*str == ' ' || *str == '\f' || *str == '\r' || *str == '\t' ||
	*str == '\n' || *str == '\v')
		str++;
	if (*str == '-')
		minus = -1;
	while (*str == '-' || *str == '+')
		str++;
	while (is_base(*str, str_base))
		ret = ret * str_base + value(*str++);
	return (ret * minus);
}
