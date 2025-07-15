int is_power_of_2(unsigned int n)
{
    if (n == 0)
        return 0;
    while (n > 1)
    {
        if (n % 2 != 0)
            return 0;
        n /= 2;
    }
    return 1;
}

int main(void)
{
    unsigned int test_values[] = {0, 1, 2, 3, 4, 8, 16, 31, 32, 64, 127, 128, 255, 256};
    int i = 0;
	
    while (i < sizeof(test_values) / sizeof(test_values[0]))
    {
        printf("is_power_of_2(%u) = %d\n", test_values[i], is_power_of_2(test_values[i]));
        i++;
    }
    return 0;
}