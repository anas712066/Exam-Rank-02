#include <stdlib.h>
#include <ctype.h>

int issub(int c)
{
	return (c=='_')
}

char	to_capital(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

size_t	count(char *str)
{
	size_t	count = 0;

	while (*str)
	{
		if (!issub(*str))
			count++;
		str++;
	}
	return (count);
}

char	*snake_to_camel(char *str)
{
	size_t	len = count(str) + 1;
	char	*camel = (char *)malloc(len * sizeof(char));
	size_t	i = 0, j = 0;

	while (str[i])
	{
		if (issub(str[i]))
		{
			i++;
			if (str[i] >= 'a' && str[i] <= 'z')
				camel[j++] = to_capital(str[i++]);
		}
		else
			camel[j++] = str[i++];
	}
	camel[j] = '\0';
	return (camel);
}

int	ft_strlen(char *str)
{
	int i=0;
	
	while(str[i])
		i++;
	return i;
}

int	main(int argc, char **argv)
{
	char	*result;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	result = snake_to_camel(argv[1]);
	if (result)
	{
		write(1, result, ft_strlen(result));
		free(result);
	}
	write(1, "\n", 1);
	return (0);
}