int main(int argc, char *argv[])
{
	int num;
	int factor=2;
	
	if(argc==2)
	{
		num=atoi(argv[1]);
		if (n == 1)
		{
			printf("1\n");
			return 0;
		}
		while (factor <= num)
		{
			while(n%factor==0)
			{
				printf("%d", factor);
				n /= factor;
				if (n > 1)
					printf("*");
			}
			else
				factor++;
		}
	}
	printf("\n");
}