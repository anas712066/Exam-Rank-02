#include <unistd.h>
#include <stdlib.h>

void	print_hex(unsigned int n)
{
	char	hex_digits[] = "0123456789abcdef";

	if (n >= 16)
		print_hex(n / 16);
	write(1, &hex_digits[n % 16], 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	unsigned int n = (unsigned int)atoi(argv[1]);
	print_hex(n);
	write(1, "\n", 1);
	return (0);
}