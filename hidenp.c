#include <unistd.h>

int	hidenp(char *s1, char *s2)
{
	int	i = 0;
	int	j = 0;

	while (s1[i])
	{
		while (s2[j] && s2[j] != s1[i])
			j++;
		if (!s2[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (hidenp(argv[1], argv[2]))
		write(1, "1\n", 2);
	else
		write(1, "0\n", 2);

	return (0);
}