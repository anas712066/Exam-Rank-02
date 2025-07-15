unsigned int	hcf(unsigned int a, unsigned int b)
{
	while (b != 0)
	{
		unsigned int temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);
	return ((a / hcf(a, b)) * b);
}

#include <stdio.h>

int	main(void)
{
	printf("%u\n", lcm(12, 18));
	printf("%u\n", lcm(0, 5));
	printf("%u\n", lcm(7, 3));
	printf("%u\n", lcm(8, 32));
	printf("%u\n", lcm(1, 1));
	return (0);
}