#include <unistd.h>

void rotone(char *str)
{
    char c;
	int i = 0;
	
    while (str[i])
    {
        c = str[i];
        if (c >= 'a' && c <= 'z')
		{
			if(c == 'z')
				c = 'a';
			else
				c=c+1;
		}
        else if (c >= 'A' && c <= 'Z')
        {
			if(c == 'Z')
				c = 'A';
			else
				c=c+1;
		}
        write(1, &c, 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        rotone(argv[1]);
    write(1, "\n", 1);
    return 0;
}