#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int		i;
	char	bit;

	i = 7;
	while (i >= 0)
	{
		if((octet >> i) & 1)
			bit = '1';
		else
			bit = '0';
		write(1, &bit, 1);
		i--;
	}
}

#include <stdio.h>

int	main(void)
{
	print_bits(2);
	write(1, "\n", 1);
	print_bits(255);
	write(1, "\n", 1);
	print_bits(128);
	write(1, "\n", 1);
	return (0);
}