bool is_delimiter(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int count_words(char *str)
{
    int count = 0;
    int in_word = 0;

    while (*str)
    {
        if (!is_delimiter(*str) && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (is_delimiter(*str))
            in_word = 0;
        str++;
    }
    return count;
}

char *copy_word(char *start, int length)
{
    char *word = malloc(length + 1);
	int i = 0;
	
    if (!word)
        return NULL;
    while (i < length)
        word[i] = start[i++];
    word[length] = '\0';
    return word;
}

char **ft_split(char *str)
{
    char **result = malloc((count_words(str) + 1) * sizeof(char *));
	char *start;
	int length;
	int i;
	
	if (!result)
        return NULL;

    index = 0;
    while (*str)
    {
        if (!is_delimiter(*str))
        {
            start = str;
            length = 0;
            while (*str && !is_delimiter(*str))
            {
                str++;
                length++;
            }
            result[i++] = copy_word(start, length);
        }
        else
            str++;
    }
    result[i] = NULL;
    return result;
}

#include <stdio.h>

int main()
{
    char str[] = "  Hello\tworld\nthis is  \nft_split ";
    char **words = ft_split(str);
	int i = 0
    while (words[i])
    {
        printf("Word[%d]: %s\n", i, words[i]);
        free(words[i++]);
    }
    free(words);
    return 0;
}