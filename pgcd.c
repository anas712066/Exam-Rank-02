#include <stdio.h>
#include <stdlib.h>

int	gcd(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("\n");
		return (0);
	}
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	if (a <= 0 || b <= 0)
	{
		printf("\n");
		return (0);
	}

	printf("%d\n", gcd(a, b));
	return (0);
}