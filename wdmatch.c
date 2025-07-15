#include <unistd.h>

void	wdmatch(char *s1, char *s2)
{
	int	i = 0;
	int	j = 0;

	while (s1[i])
	{
		while (s2[j] && s2[j] != s1[i])
			j++;
		if (!s2[j])
		{
			write(1, "\n", 1);
			return;
		}
		i++;
		j++;
	}
	while (*s1)
		write(1, s1++, 1);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	wdmatch(argv[1], argv[2]);
	return (0);
}