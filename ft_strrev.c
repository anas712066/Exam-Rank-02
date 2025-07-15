void	ft_swap(char *a, char *b)
{
	char temp=*a;
	*a=*b;
	*b=temp;
}

char	*ft_strrev(char *str)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (str[end])
		end++;
	end--;
	while (start < end)
	{
		ft_swap(&str[start], &str[end]);
		start++;
		end--;
	}
	return (str);
}