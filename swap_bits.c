#include <stdio.h>

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

int	main(void)
{
	unsigned char octet;

	octet = 0x41;
	printf("Original byte: %02x\n", octet);
	printf("Swapped byte:  %02x\n", swap_bits(octet));
	octet = 0xF0;
	printf("Original byte: %02x\n", octet);
	printf("Swapped byte:  %02x\n", swap_bits(octet));
	octet = 0xA5;
	printf("Original byte: %02x\n", octet);
	printf("Swapped byte:  %02x\n", swap_bits(octet));

	return (0);
}