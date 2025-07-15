#include <unistd.h>

int	isspace(char c)
{
	return (c == ' ' || c == '\t');
}

void	expand_str(char *str)
{
	int	i = 0;
	int	first_word = 1;

	while (str[i])
	{
		while (isspace(str[i]))
			i++;
		if (str[i])
		{
			if (!first_word)
				write(1, "   ", 3);
			first_word = 0;
			while (str[i] && !isspace(str[i]))
				write(1, &str[i++], 1);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1][0])
	{
		write(1, "\n", 1);
		return (0);
	}
	expand_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}