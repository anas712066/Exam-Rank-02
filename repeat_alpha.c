#include <unistd.h>

int get_alpha_index(char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 'a' + 1);
    if (c >= 'A' && c <= 'Z')
        return (c - 'A' + 1);
    return 0;
}

void repeat_alpha(char *str)
{
	int repeat;
	int i = 0;
	int j;
	
    while (str[i])
    {
        repeat = get_alpha_index(str[i]);
        if (repeat > 0)
        {
            j = 0;
            while (j < repeat)
            {
                write(1, &str[i], 1);
                j++;
            }
        }
        else
            write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        repeat_alpha(argv[1]);
    write(1, "\n", 1);
    return 0;
}