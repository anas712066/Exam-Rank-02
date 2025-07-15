#include <unistd.h>

void rot_13(char *str)
{
    char c;
	int i = 0;
	
    while (str[i])
    {
        c = str[i];
        if ((c >= 'a' && c <= 'z'))
            c = ((c - 'a' + 13) % 26) + 'a';
        else if ((c >= 'A' && c <= 'Z'))
            c = ((c - 'A' + 13) % 26) + 'A';
        write(1, &c, 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        rot_13(argv[1]);
    write(1, "\n", 1);
    return 0;
}