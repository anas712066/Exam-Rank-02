typedef struct s_list
{
    struct s_list *next;
    void *data;
} t_list;

#include <stdlib.h>
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *current;
    t_list *prev;
    t_list *temp;

    if (!begin_list || !*begin_list)
        return;
    current = *begin_list;
    prev = NULL;
    while (current)
    {
        if (cmp(current->data, data_ref) == 0)
        {
            temp = current;
            if (prev)
                prev->next = current->next;
            else
                *begin_list = current->next;
            current = current->next;
            free(temp);
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}

int ft_strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

int cmp(void *a, void *b)
{
    return ft_strcmp((char *)a, (char *)b);
}

t_list *create_node(void *data)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

#include <stdio.h>
void print_list(t_list *list)
{
    while (list)
    {
        printf("%s -> ", (char *)list->data);
        list = list->next;
    }
    printf("NULL\n");
}

void free_list(t_list *first)
{
    t_list *current;
	t_list *next;
	
	current = first;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
	first=NULL;
}

int main()
{
    t_list *list = create_node("apple");
    list->next = create_node("banana");
    list->next->next = create_node("cherry");
    list->next->next->next = create_node("banana");
    list->next->next->next->next = create_node("date");
    printf("Original list:\n");
    print_list(list);
    ft_list_remove_if(&list, "banana", cmp);
    printf("List after removing 'banana':\n");
    print_list(list);
    free_list (list);
    return 0;
}