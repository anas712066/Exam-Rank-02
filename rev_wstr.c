int isspace(int c)
{
	return (c==' ' || (c>=9 && c<=13));
}
#include <unistd.h>
void print_word(char *str, int start, int end)
{
    while (start < end)
        write(1, &str[start++], 1);
}

void rev_wstr(char *str)
{
    int len = 0;
	int end;
    int start;
	
    while (str[len])
        len++;
    end = len;
    start = len - 1;
    while (start >= 0)
    {
        if (isspace(str[start]))
        {
            print_word(str, start + 1, end);
            write(1, " ", 1);
            end = start;
        }
        start--;
    }
    if (end > 0)
        print_word(str, 0, end);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        rev_wstr(argv[1]);
    write(1, "\n", 1);
    return 0;
}