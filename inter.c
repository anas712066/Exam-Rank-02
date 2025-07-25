int	found( char *str, char c, int limit)
{
	int	i;

	i = 0;
	while (str[i] && (i < limit || limit < 0))
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if (!found(argv[1], argv[1][i], i) && found(argv[2], argv[1][i], -1))
			write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
