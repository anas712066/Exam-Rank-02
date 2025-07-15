#include <unistd.h>
#include <stdlib.h>

int	is_prime(int n)
{
	int	i = 2;
	
	if (n < 2)
		return (0);
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	add_prime_sum(int n)
{
	int	sum = 0;
	int	i = 2;
	
	while (i <= n)
	{
		if (is_prime(i))
			sum += i;
		i++;
	}
	return (sum);
}

void	ft_putnumber(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnumber(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int isspace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
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

int	main(int argc, char **argv)
{
	int	n;
	int	len;

	if (argc != 2)
	{
		write(1, "0\n", 2);
		return (0);
	}
	n = ft_atoi(argv[1]);
	if (n <= 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	ft_putnumber(add_prime_sum(n));
	write(1, "\n", 1);
	return (0);
}