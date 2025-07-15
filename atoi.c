#include <stdio.h>

int isspace(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atoi(const char *str)
{
	long	result;
	int	sign;

	result = 0;
	sign = 1;
	while (isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((int)(sign * result));
}