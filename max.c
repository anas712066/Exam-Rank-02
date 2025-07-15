int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				max_value;

	if (len == 0 || !tab)
		return (0);
	max_value = tab[0];
	i = 1;
	while (i < len)
	{
		if (tab[i] > max_value)
			max_value = tab[i];
		i++;
	}
	return (max_value);
}

int	main(void)
{
	int	array1[] = {1, 42, 7, -5, 100};
	int	array2[] = {-10, -20, -30, -40};
	int	array3[] = {};
	int	array4[] = {5};

	printf("Max of array1: %d\n", max(array1, 5));
	printf("Max of array2: %d\n", max(array2, 4));
	printf("Max of array3: %d\n", max(array3, 0));
	printf("Max of array4: %d\n", max(array4, 1));

	return (0);
}