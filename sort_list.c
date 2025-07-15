#include <stdlib.h>

typedef struct s_list
{
	int data;
	struct s_list *next;
} t_list;

t_list *create_node(int n)
{
	t_list *node;
	
	node=(t_list *)malloc(sizeof(t_list));
	if(!node)
		return (NULL);
	node->data=n;
	node->next=NULL;
	return (node);
}

void swap(t_list *a, t_list *b)
{
	int temp;
	
	temp = a->data;
    a->data = b->data;
    b->data = temp;
}

t_list *sort_list(t_list *lst, int (cmp)(int, int))
{
	t_list *current;
	t_list *c_next;
	int swapped;
	
	swapped=1;
	if(!lst)
		return (NULL);
	while(swapped)
	{
		swapped=0;
		current=lst;
		while(current && current->next)
		{
			c_next=current->next;
			if(!cmp(current->data, c_next->data))
			{
				swap(current, c_next);
				swapped=1;
			}
			current=current->next;
		}
	}
	return (lst);
}

int ascending(int a, int b)
{
    return a <= b;
}

int descending(int a, int b)
{
    return a >= b;
}

#include <stdio.h>
void print_list(t_list *first)
{
    while (first)
    {
        printf("%d -> ", first->data);
        first = first->next;
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
    t_list *first;
	
	first = create_node(3);
    first->next = create_node(2);
    first->next->next = create_node(4);
    first->next->next->next = create_node(1);

    printf("Lista original:\n");
    print_list(first);
	
    first = sort_list(first, ascending);
    printf("Lista ascendente:\n");
    print_list(first);
	
	first = sort_list(first, descending);
    printf("Lista descendente:\n");
    print_list(first);
	
	free_list(first);
    return 0;
}
