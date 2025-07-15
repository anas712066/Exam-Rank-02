#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	reversed = 0;
	int				i = 0;

	while (i < 8)
	{
		reversed = (reversed << 1) | (octet & 1);
		octet >>= 1;
		i++;
	}
	return (reversed);
}

void	print_bits(unsigned char octet)
{
	int	i = 7;
	while (i >= 0)
	{
		if(octet & (1 << i))
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i--;
	}
}

int	main(void)
{
	unsigned char	octet = 2;
	unsigned char	reversed;

	printf("Original bits: ");
	print_bits(octet);
	printf("\n");

	reversed = reverse_bits(octet);
	printf("Reversed bits: ");
	print_bits(reversed);
	printf("\n");

	return (0);
}