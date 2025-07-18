#include <unistd.h>

int     ft_isspace(int c)
{
        return (c == ' ' || (c >=9 && c <=13));
}

void    print_word(char *str, int start, int end)
{
        while (start < end)
                write(1, &str[start++], 1);
}

void    rev_wstr(char *str)
{
        int     i;
        int     end;
        int     start;

        i = 0;
        while (str[i])
                i++;
        end = i;
        i--;
        while (i >= 0)
        {
                if (ft_isspace(str[i]))
                {
                        print_word(str, i + 1, end);
                        write (1, " ", 1);
                        end = i;
                }
                i--;
        }
        print_word(str, 0, end);
}

int     main(int argc, char **argv)
{
        if (argc == 2)
                rev_wstr(argv[1]);
        write(1, "\n", 1);
        return (0);
}
