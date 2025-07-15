#include <unistd.h>

int	is_duplicate(char *str, char c, int pos)
{
	int	i = 0;
	while (i < pos)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	display_union(char *s1, char *s2)
{
	int	i = 0;
	int	j = 0;

	while (s1[i])
	{
		if (!is_duplicate(s1, s1[i], i))
			write(1, &s1[i], 1);
		i++;
	}
	while (s2[j])
	{
		if (!is_duplicate(s1, s2[j], i) && !is_duplicate(s2, s2[j], j))
			write(1, &s2[j], 1);
		j++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	display_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}