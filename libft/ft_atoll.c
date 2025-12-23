
long long int	ft_atoll(const char *str)
{
	int				negative;
	int				index;
	long long int	to_return;

	negative = -1;
	index = 0;
	while (str[index] == ' ' || ('\t' <= str[index] && str[index] <= '\r'))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
		{
			negative = -negative;
		}
		index++;
	}
	to_return = 0;
	while (('0' <= str[index] && str[index] <= '9'))
	{
		to_return *= 10;
		to_return -= str[index] - '0';
		index++;
	}
	to_return *= negative;
	return (to_return);
}
