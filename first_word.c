#include <unistd.h>

int isspace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

void first_word(char *str)
{
    int i = 0;

    while (str[i] && isspace(str[i]))
        i++;
    while (str[i] && !isspace(str[i]))
        write(1, &str[i++], 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        first_word(argv[1]);
    write(1, "\n", 1);
    return 0;
}