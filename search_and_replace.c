void search_and_replace(char *str, char to_replace, char replacement)
{
    int i = 0;

    while (str[i])
    {
        if (str[i] == to_replace)
            str[i] = replacement;
        write(1, &str[i++], 1);
    }
}

int main(int argc, char **argv)
{
    if (argc == 4)
        search_and_replace(argv[1], argv[2][0], argv[3][0]);
    write(1, "\n", 1);
    return 0;
}