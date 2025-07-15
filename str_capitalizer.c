#include <unistd.h>

int	is_letter(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ismin(int c)
{
	return (c >= 'a' && c <= 'z');
}

int	ismax(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int	isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

void	str_capitalize(char *str)
{
	int	i = 0;
	int	new_word = 1;

	while (str[i])
	{
		if (is_letter(str[i]))
		{
			if (new_word)
			{
				if (ismin(str[i]))
					str[i] -= 32;
				new_word = 0;
			}
			else
				if (ismax(str[i]))
					str[i] += 32;
		}
		else if (isspace(str[i]))
			new_word = 1;
		i++;
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i = 1;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (i < argc)
	{
		str_capitalize(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}