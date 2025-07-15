int isspace(int c)
{
	return (c==' ' || (c>=9 && c<=13));
} 

void find_word(char *str, int *start, int *end)
{
    int i = 0;

    while (isspace(str[i]))
        i++;
    *start = i;
    while (str[i] && !isspace(str[i]))
        i++;
    *end = i;
}

void find_begin(char *str, int *end, int *begin)
{
    int i = *end;

    while (str[i] && isspace(str[i]))
        i++;
    *begin = i;
}

void print_result(char *str, int start, int end, int begin)
{
    while (str[begin])
    {
        write(1, &str[begin], 1);
        begin++;
    }
    if (start != end)
        write(1, " ", 1);
    while (start < end)
    {
        write(1, &str[start], 1);
        start++;
    }
}

int main(int argc, char *argv[])
{
	int *start=0, *end=0, *begin=0;
	
	if(argc==2)
	{
		find_word(argv[1], &start, &end);
		find_begin(argv[1], &end, &begin);
		print_result(argv[1], *start, *end, *begin)
	}
	write(1, "\n", 1);
}       