int	is_letter(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int ismin(int c)
{
	return (c >= 'a' && c <= 'z');
}

int ismax(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int isspace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

void	rstr_capitalizer(char *str)
{
	int	i = 0;
	int	last_letter = -1;

	while (str[i])
	{
		if (is_letter(str[i]))
		{
			if (last_letter != -1)
				if(ismax(str[last_letter]))
					str[last_letter] += 32;
			last_letter = i;
		}
		else if (last_letter != -1 && isspace(str[i]))
		{
			if(ismin(str[last_letter]))
				str[last_letter] -= 32;
			last_letter = -1;
		}
		i++;
	}
	if (last_letter != -1)
		if(ismin(str[last_letter]))
				str[last_letter] -= 32;
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
		rstr_capitalizer(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}