#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        int a = atoi(argv[1]);
        int b = atoi(argv[3]);
        char op = argv[2][0];
        int result = 0;

        if (op == '+')
            result = a + b;
        else if (op == '-')
            result = a - b;
        else if (op == '*')
            result = a * b;
        else if (op == '/')
        {
            if (b != 0)
                result = a / b;
        }
        else if (op == '%')
        {
            if (b != 0)
                result = a % b;
        }

        printf("%d\n", result);
    }
    else
        write(1, "\n", 1);
    return 0;
}