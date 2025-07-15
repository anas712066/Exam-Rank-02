#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	*range;
	int	size;
	int	i;

	range = (int *)malloc(sizeof(int) * size);
	if (!range)
		return (NULL);
	if (start <= end)
		size = end - start + 1;
	else
		size = start - end + 1;
	i = 0;
	while (i < size)
	{
		if (start <= end)
			range[i] = end - i;
		else
			range[i] = end + i;
		i++;
	}

	return (range);
}