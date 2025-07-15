int	is_valid_char(char c, int base)
{
	if (c >= '0' && c <= '9')
		return (c - '0' < base);
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10 < base);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10 < base);
	return (0);
}

int	char_to_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int isspace(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atoi_base(const char *str, int str_base)
{
	long	result = 0;
	int	sign = 1;

	if (!str || str_base < 2 || str_base > 16)
		return (0);
	while (isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && is_valid_char(*str, str_base))
	{
		result = result * str_base + char_to_value(*str);
		str++;
	}
	return ((int)(result * sign));
}

#include <stdio.h>
int	main(void)
{
	printf("Base 16: \"12fdb3\" -> %d\n", ft_atoi_base("12fdb3", 16));
	printf("Base 16: \"-7F\" -> %d\n", ft_atoi_base("-7F", 16));
	printf("Base 2: \"1010\" -> %d\n", ft_atoi_base("1010", 2));
	printf("Base 8: \"123\" -> %d\n", ft_atoi_base("123", 8));
	printf("Base 10: \"-42\" -> %d\n", ft_atoi_base("-42", 10));
	printf("Base 16: \"   +FF\" -> %d\n", ft_atoi_base("   +FF", 16));
	printf("Base 5: \"123\" -> %d\n", ft_atoi_base("123", 5));
	printf("Base 36: \"ZZ\" -> %d\n", ft_atoi_base("ZZ", 36));
	printf("Base 16: \"invalid\" -> %d\n", ft_atoi_base("invalid", 16));
	printf("Base 16: \"\" -> %d\n", ft_atoi_base("", 16));
	printf("Base 2: \"-\" -> %d\n", ft_atoi_base("-", 2));

	return (0);
}